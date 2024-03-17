#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <string>
#include <QTimer>
#include <iostream>

#include "ElevatorControlSystem.h" 

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Log a message to the console
    void logMessage(const string &message);

    // Check safety signals
    bool checkSafetySignals();

    Ui::MainWindow *ui;
    int elevatorId; // store the current moving elevator ID

private:
    ElevatorControlSystem* ecs;

    // Console Log
    QWidget *consoleLogScroll;
    QVBoxLayout *scrollLayout;

private slots:
    // Slot to update console log on the GUI
    void updateLogMessage(string message);

    // Slots for handling up/down floor panel
    void upButtonPressed();
    void downButtonPressed();
    void handleFloorPanelRequest(int direction);

    //  Slots for handling elevator panel button presses 
    void openButtonPressed();
    void closeButtonPressed();
    void floorButtonPressed();

    // Slot for handling safety button presses
    void handleSafetyButtonPress(const QString &buttonName);

    // Slot for updating starting floor spin box
    void startingFloorSpinBox();

    // Slot for updating system display
    void updateSystemDisplay();

};
#endif // MAINWINDOW_H
