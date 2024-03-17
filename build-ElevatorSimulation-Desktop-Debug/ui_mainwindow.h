/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *FloorPanelFrame;
    QLabel *FloorPanel_label;
    QFrame *FloorPanel;
    QLabel *startFloor_label;
    QSpinBox *startingFloorInput;
    QPushButton *upButton;
    QPushButton *downButton;
    QFrame *ElevatorPanelFrame;
    QLabel *elevatorPanel_label;
    QFrame *ElevatorPanel;
    QPushButton *button5;
    QPushButton *button6;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button7;
    QPushButton *button4;
    QPushButton *button1;
    QPushButton *openDoorButton;
    QPushButton *closeDoorButton;
    QPushButton *helpButton;
    QFrame *AdminPanel;
    QPushButton *fireAlarm;
    QPushButton *powerOutage;
    QPushButton *blockDoor;
    QPushButton *overload;
    QLabel *elevator1;
    QLabel *elevator2;
    QLabel *elevator3;
    QFrame *line2;
    QTextBrowser *E1;
    QTextBrowser *E2;
    QTextBrowser *E3;
    QLabel *E1_label;
    QLabel *E2_label;
    QLabel *E3_label;
    QFrame *AdminPanelFrame;
    QLabel *AdminPanel_label;
    QLabel *AdminPanel_label_2;
    QFrame *line1;
    QFrame *ConsoleLogFrame;
    QLabel *ConsoleLog_label;
    QScrollArea *ConsoleLog_scroll;
    QWidget *scrollArea;
    QMenuBar *menubar;
    QMenu *menuElevator_Simulation;
    QMenu *menuBy_Vishrutha_Gopa;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(852, 563);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        FloorPanelFrame = new QFrame(centralwidget);
        FloorPanelFrame->setObjectName(QString::fromUtf8("FloorPanelFrame"));
        FloorPanelFrame->setGeometry(QRect(510, 0, 341, 31));
        FloorPanelFrame->setStyleSheet(QString::fromUtf8("background-color: #D9D9D9\n"
""));
        FloorPanelFrame->setFrameShape(QFrame::StyledPanel);
        FloorPanelFrame->setFrameShadow(QFrame::Raised);
        FloorPanel_label = new QLabel(FloorPanelFrame);
        FloorPanel_label->setObjectName(QString::fromUtf8("FloorPanel_label"));
        FloorPanel_label->setGeometry(QRect(130, 10, 121, 17));
        FloorPanel_label->setStyleSheet(QString::fromUtf8("color: Black;\n"
" font-weight: bold;"));
        FloorPanel = new QFrame(centralwidget);
        FloorPanel->setObjectName(QString::fromUtf8("FloorPanel"));
        FloorPanel->setGeometry(QRect(510, 30, 341, 91));
        FloorPanel->setStyleSheet(QString::fromUtf8("background-color: #EDE9E9\n"
""));
        FloorPanel->setFrameShape(QFrame::StyledPanel);
        FloorPanel->setFrameShadow(QFrame::Raised);
        startFloor_label = new QLabel(FloorPanel);
        startFloor_label->setObjectName(QString::fromUtf8("startFloor_label"));
        startFloor_label->setGeometry(QRect(40, 30, 101, 17));
        startFloor_label->setStyleSheet(QString::fromUtf8("color: Black;"));
        startingFloorInput = new QSpinBox(FloorPanel);
        startingFloorInput->setObjectName(QString::fromUtf8("startingFloorInput"));
        startingFloorInput->setGeometry(QRect(140, 20, 45, 31));
        startingFloorInput->setMinimum(1);
        startingFloorInput->setMaximum(7);
        upButton = new QPushButton(FloorPanel);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        upButton->setGeometry(QRect(210, 10, 83, 25));
        downButton = new QPushButton(FloorPanel);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        downButton->setGeometry(QRect(210, 40, 83, 25));
        ElevatorPanelFrame = new QFrame(centralwidget);
        ElevatorPanelFrame->setObjectName(QString::fromUtf8("ElevatorPanelFrame"));
        ElevatorPanelFrame->setGeometry(QRect(510, 120, 341, 31));
        ElevatorPanelFrame->setStyleSheet(QString::fromUtf8("background-color: #D9D9D9\n"
""));
        ElevatorPanelFrame->setFrameShape(QFrame::StyledPanel);
        ElevatorPanelFrame->setFrameShadow(QFrame::Raised);
        elevatorPanel_label = new QLabel(ElevatorPanelFrame);
        elevatorPanel_label->setObjectName(QString::fromUtf8("elevatorPanel_label"));
        elevatorPanel_label->setGeometry(QRect(130, 10, 121, 17));
        elevatorPanel_label->setStyleSheet(QString::fromUtf8("color: Black; font-weight:bold;"));
        ElevatorPanel = new QFrame(centralwidget);
        ElevatorPanel->setObjectName(QString::fromUtf8("ElevatorPanel"));
        ElevatorPanel->setGeometry(QRect(510, 150, 341, 211));
        ElevatorPanel->setStyleSheet(QString::fromUtf8("background-color: #EDE9E9\n"
""));
        ElevatorPanel->setFrameShape(QFrame::StyledPanel);
        ElevatorPanel->setFrameShadow(QFrame::Raised);
        button5 = new QPushButton(ElevatorPanel);
        button5->setObjectName(QString::fromUtf8("button5"));
        button5->setGeometry(QRect(90, 20, 51, 25));
        button6 = new QPushButton(ElevatorPanel);
        button6->setObjectName(QString::fromUtf8("button6"));
        button6->setGeometry(QRect(150, 20, 51, 25));
        button2 = new QPushButton(ElevatorPanel);
        button2->setObjectName(QString::fromUtf8("button2"));
        button2->setGeometry(QRect(90, 60, 51, 25));
        button3 = new QPushButton(ElevatorPanel);
        button3->setObjectName(QString::fromUtf8("button3"));
        button3->setGeometry(QRect(150, 60, 51, 25));
        button7 = new QPushButton(ElevatorPanel);
        button7->setObjectName(QString::fromUtf8("button7"));
        button7->setGeometry(QRect(210, 20, 51, 25));
        button4 = new QPushButton(ElevatorPanel);
        button4->setObjectName(QString::fromUtf8("button4"));
        button4->setGeometry(QRect(210, 60, 51, 25));
        button1 = new QPushButton(ElevatorPanel);
        button1->setObjectName(QString::fromUtf8("button1"));
        button1->setGeometry(QRect(150, 100, 51, 25));
        openDoorButton = new QPushButton(ElevatorPanel);
        openDoorButton->setObjectName(QString::fromUtf8("openDoorButton"));
        openDoorButton->setGeometry(QRect(90, 140, 51, 25));
        openDoorButton->setAutoFillBackground(false);
        closeDoorButton = new QPushButton(ElevatorPanel);
        closeDoorButton->setObjectName(QString::fromUtf8("closeDoorButton"));
        closeDoorButton->setGeometry(QRect(150, 140, 51, 25));
        helpButton = new QPushButton(ElevatorPanel);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setGeometry(QRect(210, 140, 51, 25));
        helpButton->setStyleSheet(QString::fromUtf8("color: red;"));
        AdminPanel = new QFrame(centralwidget);
        AdminPanel->setObjectName(QString::fromUtf8("AdminPanel"));
        AdminPanel->setGeometry(QRect(0, 390, 851, 121));
        AdminPanel->setStyleSheet(QString::fromUtf8("background-color: #EDE9E9\n"
""));
        AdminPanel->setFrameShape(QFrame::StyledPanel);
        AdminPanel->setFrameShadow(QFrame::Raised);
        fireAlarm = new QPushButton(AdminPanel);
        fireAlarm->setObjectName(QString::fromUtf8("fireAlarm"));
        fireAlarm->setGeometry(QRect(540, 20, 131, 25));
        powerOutage = new QPushButton(AdminPanel);
        powerOutage->setObjectName(QString::fromUtf8("powerOutage"));
        powerOutage->setGeometry(QRect(700, 20, 131, 25));
        blockDoor = new QPushButton(AdminPanel);
        blockDoor->setObjectName(QString::fromUtf8("blockDoor"));
        blockDoor->setGeometry(QRect(700, 60, 131, 25));
        overload = new QPushButton(AdminPanel);
        overload->setObjectName(QString::fromUtf8("overload"));
        overload->setGeometry(QRect(540, 60, 131, 25));
        elevator1 = new QLabel(AdminPanel);
        elevator1->setObjectName(QString::fromUtf8("elevator1"));
        elevator1->setGeometry(QRect(30, 50, 62, 17));
        elevator2 = new QLabel(AdminPanel);
        elevator2->setObjectName(QString::fromUtf8("elevator2"));
        elevator2->setGeometry(QRect(190, 50, 62, 17));
        elevator3 = new QLabel(AdminPanel);
        elevator3->setObjectName(QString::fromUtf8("elevator3"));
        elevator3->setGeometry(QRect(350, 50, 62, 17));
        line2 = new QFrame(AdminPanel);
        line2->setObjectName(QString::fromUtf8("line2"));
        line2->setGeometry(QRect(500, 0, 20, 121));
        line2->setFrameShape(QFrame::VLine);
        line2->setFrameShadow(QFrame::Sunken);
        E1 = new QTextBrowser(AdminPanel);
        E1->setObjectName(QString::fromUtf8("E1"));
        E1->setGeometry(QRect(100, 40, 61, 31));
        E1->setStyleSheet(QString::fromUtf8(""));
        E2 = new QTextBrowser(AdminPanel);
        E2->setObjectName(QString::fromUtf8("E2"));
        E2->setGeometry(QRect(260, 40, 61, 31));
        E2->setStyleSheet(QString::fromUtf8("text-align: center;"));
        E3 = new QTextBrowser(AdminPanel);
        E3->setObjectName(QString::fromUtf8("E3"));
        E3->setGeometry(QRect(420, 40, 61, 31));
        E1_label = new QLabel(AdminPanel);
        E1_label->setObjectName(QString::fromUtf8("E1_label"));
        E1_label->setGeometry(QRect(110, 46, 41, 20));
        E1_label->setStyleSheet(QString::fromUtf8("text-align: center;"));
        E1_label->setAlignment(Qt::AlignCenter);
        E2_label = new QLabel(AdminPanel);
        E2_label->setObjectName(QString::fromUtf8("E2_label"));
        E2_label->setGeometry(QRect(270, 45, 41, 20));
        E2_label->setStyleSheet(QString::fromUtf8("text-align: center;"));
        E2_label->setAlignment(Qt::AlignCenter);
        E3_label = new QLabel(AdminPanel);
        E3_label->setObjectName(QString::fromUtf8("E3_label"));
        E3_label->setGeometry(QRect(430, 46, 41, 20));
        E3_label->setStyleSheet(QString::fromUtf8("text-align: center;"));
        E3_label->setAlignment(Qt::AlignCenter);
        AdminPanelFrame = new QFrame(centralwidget);
        AdminPanelFrame->setObjectName(QString::fromUtf8("AdminPanelFrame"));
        AdminPanelFrame->setGeometry(QRect(0, 360, 851, 31));
        AdminPanelFrame->setStyleSheet(QString::fromUtf8("background-color: #D9D9D9\n"
""));
        AdminPanelFrame->setFrameShape(QFrame::StyledPanel);
        AdminPanelFrame->setFrameShadow(QFrame::Raised);
        AdminPanel_label = new QLabel(AdminPanelFrame);
        AdminPanel_label->setObjectName(QString::fromUtf8("AdminPanel_label"));
        AdminPanel_label->setGeometry(QRect(650, 10, 121, 17));
        AdminPanel_label->setStyleSheet(QString::fromUtf8("color: Black; font-weight:bold;"));
        AdminPanel_label_2 = new QLabel(AdminPanelFrame);
        AdminPanel_label_2->setObjectName(QString::fromUtf8("AdminPanel_label_2"));
        AdminPanel_label_2->setGeometry(QRect(220, 10, 121, 17));
        AdminPanel_label_2->setStyleSheet(QString::fromUtf8("color: Black; font-weight:bold;"));
        line1 = new QFrame(AdminPanelFrame);
        line1->setObjectName(QString::fromUtf8("line1"));
        line1->setGeometry(QRect(510, 0, 3, 61));
        line1->setFrameShape(QFrame::VLine);
        line1->setFrameShadow(QFrame::Sunken);
        ConsoleLogFrame = new QFrame(centralwidget);
        ConsoleLogFrame->setObjectName(QString::fromUtf8("ConsoleLogFrame"));
        ConsoleLogFrame->setGeometry(QRect(0, 0, 511, 31));
        ConsoleLogFrame->setStyleSheet(QString::fromUtf8("background-color: #D9D9D9;\n"
"font-weight: bold;"));
        ConsoleLogFrame->setFrameShape(QFrame::StyledPanel);
        ConsoleLogFrame->setFrameShadow(QFrame::Raised);
        ConsoleLog_label = new QLabel(ConsoleLogFrame);
        ConsoleLog_label->setObjectName(QString::fromUtf8("ConsoleLog_label"));
        ConsoleLog_label->setGeometry(QRect(210, 10, 121, 17));
        ConsoleLog_label->setStyleSheet(QString::fromUtf8("color: Black;\n"
" font-weight: bold;"));
        ConsoleLog_scroll = new QScrollArea(centralwidget);
        ConsoleLog_scroll->setObjectName(QString::fromUtf8("ConsoleLog_scroll"));
        ConsoleLog_scroll->setGeometry(QRect(0, 30, 511, 331));
        ConsoleLog_scroll->setStyleSheet(QString::fromUtf8("background-color: #EDE9E9\n"
""));
        ConsoleLog_scroll->setWidgetResizable(true);
        scrollArea = new QWidget();
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 509, 329));
        ConsoleLog_scroll->setWidget(scrollArea);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 852, 22));
        menuElevator_Simulation = new QMenu(menubar);
        menuElevator_Simulation->setObjectName(QString::fromUtf8("menuElevator_Simulation"));
        menuBy_Vishrutha_Gopa = new QMenu(menubar);
        menuBy_Vishrutha_Gopa->setObjectName(QString::fromUtf8("menuBy_Vishrutha_Gopa"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuElevator_Simulation->menuAction());
        menubar->addAction(menuBy_Vishrutha_Gopa->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        FloorPanel_label->setText(QCoreApplication::translate("MainWindow", "Floor Panel", nullptr));
        startFloor_label->setText(QCoreApplication::translate("MainWindow", "Starting Floor", nullptr));
        upButton->setText(QCoreApplication::translate("MainWindow", "\342\226\262", nullptr));
        downButton->setText(QCoreApplication::translate("MainWindow", "\342\226\274", nullptr));
        elevatorPanel_label->setText(QCoreApplication::translate("MainWindow", "Elevator Panel", nullptr));
        button5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        button6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        button2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        button3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        button7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        button4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        button1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        openDoorButton->setText(QCoreApplication::translate("MainWindow", "\342\227\200\342\224\203\342\226\266", nullptr));
        closeDoorButton->setText(QCoreApplication::translate("MainWindow", "\342\226\266\342\224\203\342\227\200", nullptr));
        helpButton->setText(QCoreApplication::translate("MainWindow", "\342\234\206", nullptr));
        fireAlarm->setText(QCoreApplication::translate("MainWindow", "Fire Alarm", nullptr));
        powerOutage->setText(QCoreApplication::translate("MainWindow", "Power Outage", nullptr));
        blockDoor->setText(QCoreApplication::translate("MainWindow", "Block Door", nullptr));
        overload->setText(QCoreApplication::translate("MainWindow", "Overload", nullptr));
        elevator1->setText(QCoreApplication::translate("MainWindow", "Elevator1", nullptr));
        elevator2->setText(QCoreApplication::translate("MainWindow", "Elevator2", nullptr));
        elevator3->setText(QCoreApplication::translate("MainWindow", "Elevator3", nullptr));
        E2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        E1_label->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        E2_label->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        E3_label->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        AdminPanel_label->setText(QCoreApplication::translate("MainWindow", "Admin Panel", nullptr));
        AdminPanel_label_2->setText(QCoreApplication::translate("MainWindow", "System Display", nullptr));
        ConsoleLog_label->setText(QCoreApplication::translate("MainWindow", "Console Log", nullptr));
        menuElevator_Simulation->setTitle(QCoreApplication::translate("MainWindow", "Elevator Simulation", nullptr));
        menuBy_Vishrutha_Gopa->setTitle(QCoreApplication::translate("MainWindow", "By: Vishrutha Gopa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
