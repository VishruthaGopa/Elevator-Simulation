#include "Elevator.h"

Elevator::Elevator(int eleID) : elevatorID(eleID + 1), current_floor(1), direction(0), doorsOpen(false) {}

// Simulate elevator movement
void Elevator::moveToFloor(int floor) {
    current_floor = floor;
}

// Add floor to request queue
void Elevator::addRequest(int floor) {
    requestsQueue.push_back(floor);
}

vector<int>& Elevator::getRequestQueue() {
    return requestsQueue;
}

// Clear request queue
void Elevator::clearRequests() {
    requestsQueue.clear();
}

int Elevator::getCurrentFloor() const {
    return current_floor;
}

int Elevator::getElevatorID() const {
    return elevatorID;
}

int Elevator::getDirection() const {
    return direction;
}

void Elevator::setDirection(int dir) {
    direction = dir;
}

bool Elevator::isIdle() const {
    return direction == 0 && requestsQueue.empty();
}

void Elevator::openDoors() {
    if (!doorsOpen) { // Check if the doors are not already open
        doorsOpen = true; // Set the flag to indicate that the doors are open
    }
}

void Elevator::closeDoors() {
    if (doorsOpen) { // Check if the doors are not already closed
        doorsOpen = false; // Set the flag to indicate that the doors are closed
    }
}

bool Elevator::areDoorsOpen() const {
    return doorsOpen;
}

bool Elevator::areDoorsClose() const {
    return !doorsOpen;
}