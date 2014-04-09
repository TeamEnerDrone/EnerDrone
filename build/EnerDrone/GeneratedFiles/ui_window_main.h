/********************************************************************************
** Form generated from reading UI file 'window_main.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_MAIN_H
#define UI_WINDOW_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_MainClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QLabel *image_droneStatus;
    QLabel *label_droneStatus;
    QTextEdit *textEdit_droneName;
    QLabel *image_warning;
    QLabel *image_batteryLevel;
    QLabel *label_batteryLevel;
    QPushButton *pushButton_DroneCamera;
    QLabel *label_warning;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Window_MainClass)
    {
        if (Window_MainClass->objectName().isEmpty())
            Window_MainClass->setObjectName(QStringLiteral("Window_MainClass"));
        Window_MainClass->resize(595, 386);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI Light"));
        font.setPointSize(12);
        Window_MainClass->setFont(font);
        centralWidget = new QWidget(Window_MainClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setEnabled(true);
        pushButton_start->setGeometry(QRect(80, 190, 141, 41));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 195, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(93, 255, 93, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(46, 243, 46, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 116, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(0, 155, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        QBrush brush7(QColor(0, 232, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush8(QColor(127, 243, 127, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        QBrush brush9(QColor(255, 255, 220, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        QBrush brush10(QColor(168, 168, 168, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QBrush brush11(QColor(85, 0, 255, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        pushButton_start->setPalette(palette);
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI Light"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        pushButton_start->setFont(font1);
        pushButton_start->setAutoDefault(false);
        pushButton_start->setDefault(false);
        pushButton_start->setFlat(false);
        pushButton_stop = new QPushButton(centralWidget);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setEnabled(true);
        pushButton_stop->setGeometry(QRect(360, 190, 141, 41));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush12(QColor(255, 0, 0, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush12);
        QBrush brush13(QColor(255, 0, 0, 150));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush13);
        QBrush brush14(QColor(255, 63, 63, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush14);
        QBrush brush15(QColor(127, 0, 0, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush15);
        QBrush brush16(QColor(170, 0, 0, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush16);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush17(QColor(255, 127, 127, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush17);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush14);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush15);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush16);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush17);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        QBrush brush18(QColor(168, 168, 168, 30));
        brush18.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush18);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush14);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush16);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        pushButton_stop->setPalette(palette1);
        pushButton_stop->setFont(font);
        pushButton_stop->setStyleSheet(QStringLiteral(""));
        image_droneStatus = new QLabel(centralWidget);
        image_droneStatus->setObjectName(QStringLiteral("image_droneStatus"));
        image_droneStatus->setGeometry(QRect(30, 90, 21, 41));
        image_droneStatus->setTextFormat(Qt::PlainText);
        label_droneStatus = new QLabel(centralWidget);
        label_droneStatus->setObjectName(QStringLiteral("label_droneStatus"));
        label_droneStatus->setGeometry(QRect(60, 100, 81, 21));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        label_droneStatus->setFont(font2);
        textEdit_droneName = new QTextEdit(centralWidget);
        textEdit_droneName->setObjectName(QStringLiteral("textEdit_droneName"));
        textEdit_droneName->setGeometry(QRect(160, 90, 291, 41));
        QFont font3;
        font3.setPointSize(16);
        textEdit_droneName->setFont(font3);
        textEdit_droneName->setReadOnly(true);
        image_warning = new QLabel(centralWidget);
        image_warning->setObjectName(QStringLiteral("image_warning"));
        image_warning->setGeometry(QRect(140, 280, 61, 71));
        image_warning->setPixmap(QPixmap(QString::fromUtf8(":/Window_Main/alerte_50.png")));
        image_batteryLevel = new QLabel(centralWidget);
        image_batteryLevel->setObjectName(QStringLiteral("image_batteryLevel"));
        image_batteryLevel->setGeometry(QRect(500, 50, 51, 81));
        label_batteryLevel = new QLabel(centralWidget);
        label_batteryLevel->setObjectName(QStringLiteral("label_batteryLevel"));
        label_batteryLevel->setGeometry(QRect(470, 130, 91, 31));
        label_batteryLevel->setAlignment(Qt::AlignCenter);
        pushButton_DroneCamera = new QPushButton(centralWidget);
        pushButton_DroneCamera->setObjectName(QStringLiteral("pushButton_DroneCamera"));
        pushButton_DroneCamera->setGeometry(QRect(220, 300, 141, 41));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush19(QColor(85, 170, 255, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush19);
        QBrush brush20(QColor(127, 213, 255, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush20);
        QBrush brush21(QColor(63, 191, 255, 255));
        brush21.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush21);
        QBrush brush22(QColor(0, 85, 127, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush22);
        QBrush brush23(QColor(0, 113, 170, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush23);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        QBrush brush24(QColor(0, 170, 255, 255));
        brush24.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush24);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush25(QColor(127, 212, 255, 255));
        brush25.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush25);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush19);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush20);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush21);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush22);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush23);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush24);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush25);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush22);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush19);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush20);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush21);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush22);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush23);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush22);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush22);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush24);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush24);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush24);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        pushButton_DroneCamera->setPalette(palette2);
        label_warning = new QLabel(centralWidget);
        label_warning->setObjectName(QStringLiteral("label_warning"));
        label_warning->setGeometry(QRect(30, 310, 111, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush12);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush12);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush12);
        QBrush brush26(QColor(120, 120, 120, 255));
        brush26.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush26);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush26);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush26);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush12);
        label_warning->setPalette(palette3);
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        label_warning->setFont(font4);
        Window_MainClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Window_MainClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Window_MainClass->setStatusBar(statusBar);

        retranslateUi(Window_MainClass);

        QMetaObject::connectSlotsByName(Window_MainClass);
    } // setupUi

    void retranslateUi(QMainWindow *Window_MainClass)
    {
        Window_MainClass->setWindowTitle(QApplication::translate("Window_MainClass", "Window_Main", 0));
        pushButton_start->setText(QApplication::translate("Window_MainClass", "Start", 0));
        pushButton_stop->setText(QApplication::translate("Window_MainClass", "Stop", 0));
        image_droneStatus->setText(QString());
        label_droneStatus->setText(QApplication::translate("Window_MainClass", "On ground", 0));
        image_warning->setText(QString());
        image_batteryLevel->setText(QString());
        label_batteryLevel->setText(QString());
        pushButton_DroneCamera->setText(QApplication::translate("Window_MainClass", "Drone Camera", 0));
        label_warning->setText(QApplication::translate("Window_MainClass", "Warning !!!", 0));
    } // retranslateUi

};

namespace Ui {
    class Window_MainClass: public Ui_Window_MainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_MAIN_H
