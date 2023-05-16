#include "widget.h"
#include "ui_widget.h"
#include "QPushButton"
#include "QBoxLayout"
#include "QMessageBox"
#include "QDialogButtonBox"
#include <QDate>
#include <QCheckBox>
#include "QInputDialog"
#include <QButtonGroup>
#include <QComboBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QFileInfo>


void Widget::updateCalendar(int year,int month )
{


     // Nombre de la ventana
    setWindowTitle("Calendario   O.D.J");

    // Obtener el número de días en el mes y el día de la semana en que comienza
    QDate date(year, month, 1);
    int numDays = date.daysInMonth();
    int dayBegin = date.dayOfWeek() - 1;

    // Actualizar la tabla del calendario con el número correcto de días
    int row = 0; // Comenzar a agregar días a la primera fila
    int col = dayBegin;

    for (int i = 0; i < ui->tablecalendar->rowCount(); ++i) {
        for (int j = 0; j < ui->tablecalendar->columnCount(); ++j) {
            QTableWidgetItem *item = ui->tablecalendar->item(i, j);
            if (item) {
                delete item;
            }
            item = new QTableWidgetItem;
            ui->tablecalendar->setItem(i, j, item);
        }
    }

    for (int day = 1; day <= numDays; ++day) {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString::number(day));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tablecalendar->setItem(row, col, item);
        col = (col + 1) % 7; // Cambiar a la siguiente columna después de agregar un día
        if (col == 0) {
            ++row; // Cambiar a la siguiente fila después de agregar una semana completa
        }
    }

    // Rellenar las celdas vacías al final del mes con el primer día del mes siguiente
    if (col != 0) {
        QDate nextMonth = date.addMonths(1);
        int daysToAdd = 7 - col;
        for (int i = 0; i < daysToAdd; ++i) {
            QTableWidgetItem *item = new QTableWidgetItem;
            ui->tablecalendar->setItem(row, col, item);
            col = (col + 1) % 7;
            if (col == 0) {
                ++row;
            }
        }
        dayBegin = col;
        date = nextMonth;
        numDays = date.daysInMonth();
    }

    // Rellenar las celdas vacías al principio del mes con el último día del mes anterior
    if (dayBegin != 0) {
        QDate prevMonth = date.addMonths(-1);
        int prevNumDays = prevMonth.daysInMonth();
        for (int i = dayBegin - 1; i >= 0; --i) {
            QTableWidgetItem *item = new QTableWidgetItem;
            ui->tablecalendar->setItem(0, i, item);
        }
    }
}


class dateNow{
    public:
    dateNow(){
        QDate currentDate = QDate::currentDate();
        day=currentDate.day();
        month=currentDate.month();
        year=currentDate.year();
    }
    ~dateNow(){

    }

    int getDay(){
        return day;
    }

    int getYear(){
        return year;
    }

    int getMonth(){
        return month;
    }
    private:
    int day, month, year;

};
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{



    dateNow dateNow1;

    ui->setupUi(this);
    m_exists=QFileInfo("data.sqlite").exists();
    m_db=QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("data.sqlite");
    m_db.open();
    populateDatabase();
    m_model=new QSqlTableModel(this);
    m_model->setTable("persona");
    m_model->select();
    ui->TableBase->setModel(m_model);


    ui->crearEvento->setText("Agregar Evento");
    ui->spinBoxAnio->setRange(1,999999999);
    ui->spinBoxAnio->setValue(dateNow1.getYear());


    const QString month[] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre",
                             "Noviembre","Diciembre"};

    for (int i = 0; i < (sizeof(month)/sizeof(month[0])); i++) {
        ui->mesNow->addItem(month[i]);
    }

    ui->mesNow->setCurrentIndex((dateNow1.getMonth())-1);
    ui->mesNow->setStyleSheet("background-color: white; QComboBox::drop-down { background-color: red; }");

    //ui->barraSeleccionDate->setStyleSheet("background-color: blue");

   //ui->ListaEventos->setStyleSheet("background-color: white;  border-radius: 10px;");



   ui->tablecalendar->setRowCount(6);
   ui->tablecalendar->setEditTriggers(QAbstractItemView::NoEditTriggers);
   ui->tablecalendar->setColumnCount(7);

   ui->tablecalendar->setStyleSheet("QTableView {border: none;}");
   ui->tablecalendar->verticalHeader()->setVisible(false);
   QStringList labels {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
   ui->tablecalendar->setHorizontalHeaderLabels(labels);
   ui->tablecalendar->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   ui->tablecalendar->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);





   int numColumns = ui->tablecalendar->columnCount();
   for (int i = 0; i < numColumns; i++) {
        ui->tablecalendar->setColumnWidth(i, 85);
   }

  // Establecer una altura de 30 píxeles para todas las filas
   for (int i = 0; i < ui->tablecalendar->rowCount(); i++) {
        ui->tablecalendar->setRowHeight(i, 60);
   }

   // Obtener el mes y el año seleccionados
   int monthAhora = ui->mesNow->currentIndex() + 1; // El índice del mes comienza desde 0
   int yearAhora = ui->spinBoxAnio->value();
   updateCalendar(yearAhora,monthAhora);
   connect(ui->spinBoxAnio, SIGNAL(valueChanged(int)), this, SLOT(updateCalendar()));
   connect(ui->mesNow, SIGNAL(currentIndexChanged(int)), this, SLOT(updateCalendar()));


}

Widget::~Widget()
{
    delete ui;
}






//Interfaz y boton de agregar eventos

void Widget::on_crearEvento_clicked()
{

    dateNow dateNow1;
    QMessageBox::information(this, "Mensaje", "creando un evento");
    QDialog dialog(this);
    dialog.setWindowTitle("Crear Evento");
    QVBoxLayout layout(&dialog);

    // Campo de año
    QSpinBox yearSpinBox(&dialog);
    yearSpinBox.setRange(1, 99999);
    yearSpinBox.setValue(QDate::currentDate().year());
    QLabel yearLabel("Año:", &dialog);
        layout.addWidget(&yearLabel);
    layout.addWidget(&yearSpinBox);
    int year = yearSpinBox.value();

    // Campo de mes
    QDate DateMonth = QDate::currentDate();
    int monthNow = DateMonth.month();
    const QStringList monthList = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
                                   "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    QComboBox monthComboBox(&dialog);
    monthComboBox.addItems(monthList);
    QLabel monthLabel("Mes:", &dialog);
    monthComboBox.setCurrentIndex(monthNow-1);
    layout.addWidget(&monthLabel);
    layout.addWidget(&monthComboBox);
    int month = monthComboBox.currentIndex();

    // Campo de día
    QSpinBox daySpinBox(&dialog);
    daySpinBox.setRange(1, 31);
    daySpinBox.setValue(dateNow1.getDay());
    QLabel dayLabel("Día:", &dialog);
        layout.addWidget(&dayLabel);
    layout.addWidget(&daySpinBox);





    // Campo de hora
    QSpinBox hourSpinBox(&dialog);
    hourSpinBox.setRange(0, 12);
    hourSpinBox.setValue(QTime::currentTime().hour());
    QLabel hourLabel("Hora:", &dialog);
    layout.addWidget(&hourLabel);
    layout.addWidget(&hourSpinBox);



    QCheckBox *checkAm = new QCheckBox(nullptr);
    checkAm->setText("AM");
    layout.addWidget(checkAm);

    QCheckBox *checkPm = new QCheckBox(nullptr);
    checkPm->setText("PM");
    layout.addWidget(checkPm);

    QButtonGroup *buttonGroup = new QButtonGroup(nullptr);
    buttonGroup->addButton(checkAm);
    buttonGroup->addButton(checkPm);
    buttonGroup->setExclusive(true);



    // Botones de aceptar y cancelar
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    layout.addWidget(&buttonBox);

    // Conecta los botones aceptar y cancelar
    QObject::connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    QObject::connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    // Muestra el diálogo y espera a que el usuario seleccione "Aceptar" o "Cancelar"
    if (dialog.exec() == QDialog::Accepted) {
        int day = daySpinBox.value();
        int month = monthComboBox.currentIndex() + 1; // Los índices comienzan en 0
        int year = yearSpinBox.value();
        int hour = hourSpinBox.value();

        // Haz algo con los valores ingresados
        // ...
    }
}


void Widget::on_buttonExit_clicked()
{
    if (QMessageBox::question(this, "Pregunta", "¿Seguro desea salir de la aplicación?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        close();
    } else {
        QMessageBox::information(this, "Mensaje", "Continúa en la aplicación");
    }
}


void Widget::on_mesNow_activated(int index)
{
    // Obtener el valor actual del spinBoxAnio
    int yearSelect = ui->spinBoxAnio->value();

    // Actualizar el comboBoxMes
    ui->mesNow->setCurrentIndex(index);

    // Actualizar el calendario con los valores actuales de ambos widgets
    updateCalendar(yearSelect, index+1);
}

void Widget::on_spinBoxAnio_valueChanged(int arg1)
{
    // Obtener el valor actual del comboBoxMes
    int monthSelect = ui->mesNow->currentIndex() + 1;

    // Actualizar el calendario con los valores actuales de ambos widgets
    updateCalendar(arg1, monthSelect);
}


void Widget::on_buttonAtras_clicked()
{

    int yearSelect = ui->spinBoxAnio->value();
    int monthSelect = ui->mesNow->currentIndex() + 1;
    if(monthSelect>1){
        monthSelect--;
        ui->mesNow->setCurrentIndex(monthSelect-1);
        updateCalendar(yearSelect, monthSelect);
    }

}


void Widget::on_buttonNextMonth_clicked()
{
    int yearSelect = ui->spinBoxAnio->value();
    int monthSelect = ui->mesNow->currentIndex() + 1;
    if(monthSelect<12){
        monthSelect--;
        ui->mesNow->setCurrentIndex(monthSelect+1);
        updateCalendar(yearSelect, monthSelect);
    }
}

void Widget::populateDatabase(){
    if(m_exists==false){
        QString sql="create table if not exists persona(id integer primary key autoincrement, nombre text, edad integer, salario float)";
        QSqlQuery query;
        query.prepare(sql);
        query.exec();

        insertPerson("Carlos", 26, 477462.2);
        insertPerson("Ana", 30, 5000.0);
        insertPerson("Pedro", 45, 9000.0);
        insertPerson("Luisa", 25, 6000.0);
        insertPerson("Marta", 35, 8000.0);
        insertPerson("Antonio", 50, 1000.0);

    }
}

void Widget::insertPerson(const QString nombre, int edad, double salario)const{
    QString sql="insert into persona(nombre, edad, salario) values(?,?,?)";
    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(nombre);
    query.addBindValue(edad);
    query.addBindValue(salario);
    query.exec();
}

