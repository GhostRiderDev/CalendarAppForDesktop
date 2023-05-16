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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayoutTableAndbuttonsut;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonAtras;
    QComboBox *mesNow;
    QLabel *label;
    QSpinBox *spinBoxAnio;
    QLabel *anio;
    QPushButton *buttonNextMonth;
    QTableWidget *tablecalendar;
    QVBoxLayout *verticalLayout_2;
    QCommandLinkButton *crearEvento;
    QPushButton *pushButton;
    QPushButton *buttonExit;
    QTableView *TableBase;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(731, 562);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        LayoutTableAndbuttons QGridLayout(Widget);
        LayoutTableAndbuttonsbjectName("gridLayout");
        LayoutTableAndbuttons = new QVBoxLayout();
        LayoutTableAndbuttons->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        buttonAtras = new QPushButton(Widget);
        buttonAtras->setObjectName("buttonAtras");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/flechaRetroceder.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonAtras->setIcon(icon);
        buttonAtras->setIconSize(QSize(50, 50));
        buttonAtras->setFlat(true);

        horizontalLayout_2->addWidget(buttonAtras);

        mesNow = new QComboBox(Widget);
        mesNow->setObjectName("mesNow");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mesNow->sizePolicy().hasHeightForWidth());
        mesNow->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(mesNow);

        label = new QLabel(Widget);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        spinBoxAnio = new QSpinBox(Widget);
        spinBoxAnio->setObjectName("spinBoxAnio");
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBoxAnio->sizePolicy().hasHeightForWidth());
        spinBoxAnio->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(spinBoxAnio);

        anio = new QLabel(Widget);
        anio->setObjectName("anio");

        horizontalLayout_2->addWidget(anio);

        buttonNextMonth = new QPushButton(Widget);
        buttonNextMonth->setObjectName("buttonNextMonth");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/flechaAvanzar (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonNextMonth->setIcon(icon1);
        buttonNextMonth->setIconSize(QSize(50, 50));
        buttonNextMonth->setFlat(true);

        horizontalLayout_2->addWidget(buttonNextMonth);


       LayoutTableAndbuttons3->addLayout(horizontalLayout_2);

        tablecalendar = new QTableWidget(Widget);
        tablecalendar->setObjectName("tablecalendar");
        sizePolicy.setHeightForWidth(tablecalendar->sizePolicy().hasHeightForWidth());
        tablecalendar->setSizePolicy(sizePolicy);

       LayoutTableAndbuttons3->addWidget(tablecalendar);


        gridLayout->addLayoutLayoutTableAndbuttons3, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        crearEvento = new QCommandLinkButton(Widget);
        crearEvento->setObjectName("crearEvento");
        crearEvento->setAutoFillBackground(false);
        crearEvento->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 11pt \"Arial\";"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icono2.png"), QSize(), QIcon::Normal, QIcon::Off);
        crearEvento->setIcon(icon2);
        crearEvento->setIconSize(QSize(40, 40));
        crearEvento->setAutoDefault(false);

        verticalLayout_2->addWidget(crearEvento);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setAutoFillBackground(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/menu.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon3);
        pushButton->setIconSize(QSize(40, 40));
        pushButton->setFlat(true);

        verticalLayout_2->addWidget(pushButton);

        buttonExit = new QPushButton(Widget);
        buttonExit->setObjectName("buttonExit");

        verticalLayout_2->addWidget(buttonExit);

        TableBase = new QTableView(Widget);
        TableBase->setObjectName("TableBase");

        verticalLayout_2->addWidget(TableBase);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        buttonAtras->setText(QString());
        label->setText(QCoreApplication::translate("Widget", "Mes", nullptr));
        anio->setText(QCoreApplication::translate("Widget", "A\303\261o", nullptr));
        buttonNextMonth->setText(QString());
        crearEvento->setText(QString());
        pushButton->setText(QCoreApplication::translate("Widget", "Menu", nullptr));
        buttonExit->setText(QCoreApplication::translate("Widget", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
