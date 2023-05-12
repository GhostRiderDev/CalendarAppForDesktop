/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *frame;
    QCommandLinkButton *crearEvento;
    QPushButton *pushButton;
    QPushButton *buttonExit;
    QTableWidget *tablecalendar;
    QSplitter *splitter;
    QPushButton *buttonAtras;
    QComboBox *mesNow;
    QLabel *label;
    QSpinBox *spinBoxAnio;
    QLabel *anio;
    QPushButton *buttonNextMonth;
    QTableView *TableBase;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame = new QFrame(Widget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 181, 601));
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 0, 128);\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        crearEvento = new QCommandLinkButton(frame);
        crearEvento->setObjectName("crearEvento");
        crearEvento->setGeometry(QRect(10, 80, 171, 51));
        crearEvento->setAutoFillBackground(false);
        crearEvento->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 11pt \"Arial\";"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icono2.png"), QSize(), QIcon::Normal, QIcon::Off);
        crearEvento->setIcon(icon);
        crearEvento->setIconSize(QSize(40, 40));
        crearEvento->setAutoDefault(false);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 91, 41));
        pushButton->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/menu.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(40, 40));
        pushButton->setFlat(true);
        buttonExit = new QPushButton(frame);
        buttonExit->setObjectName("buttonExit");
        buttonExit->setGeometry(QRect(0, 580, 80, 24));
        tablecalendar = new QTableWidget(Widget);
        tablecalendar->setObjectName("tablecalendar");
        tablecalendar->setGeometry(QRect(190, 80, 601, 491));
        splitter = new QSplitter(Widget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(190, 0, 601, 51));
        splitter->setOrientation(Qt::Horizontal);
        buttonAtras = new QPushButton(splitter);
        buttonAtras->setObjectName("buttonAtras");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/flechaRetroceder.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonAtras->setIcon(icon2);
        buttonAtras->setIconSize(QSize(50, 50));
        buttonAtras->setFlat(true);
        splitter->addWidget(buttonAtras);
        mesNow = new QComboBox(splitter);
        mesNow->setObjectName("mesNow");
        splitter->addWidget(mesNow);
        label = new QLabel(splitter);
        label->setObjectName("label");
        splitter->addWidget(label);
        spinBoxAnio = new QSpinBox(splitter);
        spinBoxAnio->setObjectName("spinBoxAnio");
        splitter->addWidget(spinBoxAnio);
        anio = new QLabel(splitter);
        anio->setObjectName("anio");
        splitter->addWidget(anio);
        buttonNextMonth = new QPushButton(splitter);
        buttonNextMonth->setObjectName("buttonNextMonth");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/flechaAvanzar (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonNextMonth->setIcon(icon3);
        buttonNextMonth->setIconSize(QSize(50, 50));
        buttonNextMonth->setFlat(true);
        splitter->addWidget(buttonNextMonth);
        TableBase = new QTableView(Widget);
        TableBase->setObjectName("TableBase");
        TableBase->setGeometry(QRect(50, 240, 256, 192));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        crearEvento->setText(QString());
        pushButton->setText(QCoreApplication::translate("Widget", "Menu", nullptr));
        buttonExit->setText(QCoreApplication::translate("Widget", "Exit", nullptr));
        buttonAtras->setText(QString());
        label->setText(QCoreApplication::translate("Widget", "Mes", nullptr));
        anio->setText(QCoreApplication::translate("Widget", "A\303\261o", nullptr));
        buttonNextMonth->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
