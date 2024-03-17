#ifndef ELEVATORCONTROLSYSTEM_H
#define ELEVATORCONTROLSYSTEM_H

#include "Elevator.h"
#include <iostream>
#include <vector>
#include <QObject>
#include <chrono>
#include <thread>
#include <QTimer> // for delaying elevator movement
#include <QEventLoop> // for creating an event loop

using namespace std;

class ElevatorControlSystem : public QObject {
    Q_OBJECT // Required for signals/slots

public:
    // Constructor
    ElevatorControlSystem();

    // Destructor 
    ~ElevatorControlSystem();

    // Vector to store pointers to Elevator objects
    vector<Elevator*> elevators;

    // Function to allocate an elevator for a request
    int allocateElevator(int requestedFloor, int direction);

    // Function to check elevators' status
    void checkElevators();

    // Getter for the floor of a specific elevator
    int getElevatorFloor(int elevatorId) const;

    // Function to add request to elevator queue
    void addRequest(int elevatorId, int floor);

    // Function to move a specific elevator
    void moveElevator(int elevatorId);

    // Function to find an elevator by its ID
    Elevator* findElevatorById(int elevatorId);

    // Flag indicating the safety state
    bool safety_state;
    bool readyForRequest;

    // String indicating the pressed signal
    string pressedSignal;

    // Function to open/close the doors of an elevator
    void openElevatorDoors(int elevatorId);
    void closeElevatorDoors(int elevatorId);


    void clearAllRequestQueues();

private:
    // NOTE to TAs: Adjust the number of floors and elevators here.
    // The backend can handle a variable number of floors and elevators, but the GUI currently supports a fixed number (i.e. 7 floors and 3 elevators).
    // If you need to change the number of floors or elevators, ensure that the GUI components (e.g., push buttons, spin boxes)
    // are updated accordingly to accommodate the changes.
    const int num_floors = 7;
    const int num_elevators = 3;

signals:
    // Signal to inform MainWindow about status updates
    void statusUpdate(string message);

    // Signal to check safety signals
    void checkSafetySignals();

};


#endif // ELEVATORCONTROLSYSTEM_H
