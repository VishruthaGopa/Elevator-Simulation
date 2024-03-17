#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include <iostream>

using namespace std;

class Elevator{
public:
    // Constructor
    Elevator(int eleID);

    // Function to move the elevator to a specific floor
    void moveToFloor(int floor);

    // Function to add a request to the elevator's queue
    void addRequest(int floor);

    // Function to clear all request in elevator's queue
    void clearRequests();

    // Getters
    int getCurrentFloor() const;
    int getDirection() const;
    int getElevatorID() const;
    vector<int>& getRequestQueue();

    // Functions to check door status
    bool areDoorsOpen() const;
    bool areDoorsClose() const;

    //Setters
    void setDirection(int dir);

    // Function to open/close the doors of the elevator
    void openDoors();
    void closeDoors();

    // Function to check if elevator is idle
    bool isIdle() const;

private:
    int elevatorID;         // Unique ID for the elevator
    int current_floor;      // Current floor of the elevator
    int direction;          
    /*
        DIRECTION_UP = 1;
        DIRECTION_DOWN = -1;
        DIRECTION_IDLE = 0;
    */
    bool doorsOpen;         // Flag to track whether the doors are open or closed
    vector<int> requestsQueue;  // Queue of floor requests
};

#endif // ELEVATOR_H
