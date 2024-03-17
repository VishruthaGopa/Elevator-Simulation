#include "ElevatorControlSystem.h"

// Constructor
ElevatorControlSystem::ElevatorControlSystem() {
    // Initialize elevators
    for (int i = 0; i < num_elevators; ++i) {
        Elevator* ele = new Elevator(i);
        elevators.push_back(ele);
    }
    safety_state = false;
    readyForRequest= false;
    pressedSignal = "None";
}

// Destructor
ElevatorControlSystem::~ElevatorControlSystem() {
    // Deallocate memory for each elevator
    for (Elevator* ele : elevators) {
        delete ele;
    }
}

// Function to find an elevator by its ID
Elevator* ElevatorControlSystem::findElevatorById(int elevatorId) {
    if (elevatorId>0){
        for (Elevator* elevator : elevators) {
            if (elevator->getElevatorID() == elevatorId) {
                return elevator;
            }
        }
    }
    cerr << "Elevator with ID " << elevatorId << " not found!" << endl; // Error handling
    return nullptr;
}

// Function to check the status of all elevators
void ElevatorControlSystem::checkElevators() {    
    for (Elevator* elevator : elevators) {
        cout << "Elevator "<< elevator->getElevatorID() << " at floor " << elevator->getCurrentFloor() << ", direction: " << elevator->getDirection() << endl;
    }
}

// Function to allocate an elevator for a request
int ElevatorControlSystem::allocateElevator(int requestedFloor, int direction) {
    //cout << "in allocateElevator function" << endl;

    // Step 1: Find elevators moving in the requested direction and intersecting the requested floor
    vector<Elevator*> movingElevators;
    for (Elevator* elevator : elevators) {
        //cout << "In loop" << endl;
        int currentFloor = elevator->getCurrentFloor();
        int elevatorDirection = elevator->getDirection();
        
        // Check if the elevator is moving in the requested direction and intersects the requested floor
        if ((direction == 1 && elevatorDirection == 1 && currentFloor < requestedFloor) || 
            (direction == -1 && elevatorDirection == -1 && currentFloor > requestedFloor)) {
            movingElevators.push_back(elevator);
        }
    }

    // Print the number of moving elevators found
    //cout << "Number of moving elevators: " << movingElevators.size() << endl;
    //checkElevators();

    // Step 2: If there are moving elevators, find the closest one based on distance
    if (!movingElevators.empty()) {
        Elevator* closestElevator = nullptr;
        int minDistance = INT_MAX;
        for (Elevator* elevator : movingElevators) {
            int currentFloor = elevator->getCurrentFloor();
            int distance = abs(currentFloor - requestedFloor);
            if (distance < minDistance) {
                minDistance = distance;
                closestElevator = elevator;
            }
        }

        // Print the minimum distance and elevator ID
        //cout << "Minimum distance: " << minDistance << endl;
        //cout << "Elevator ID: " << closestElevator->getElevatorID() << endl;

        closestElevator->setDirection(direction);
        // Return the ID of the closest elevator
        return closestElevator->getElevatorID();
    }

    // Step 3: If no moving elevators, find the closest idle elevator
    Elevator* closestIdleElevator = nullptr;
    int minIdleDistance = INT_MAX;
    for (Elevator* elevator : elevators) {
        if (elevator->isIdle()) {
            int currentFloor = elevator->getCurrentFloor();
            int distance = abs(currentFloor - requestedFloor);
            if (distance < minIdleDistance) {
                minIdleDistance = distance;
                closestIdleElevator = elevator;
            }
        }
    }

    // If an idle elevator is found
    if (closestIdleElevator != nullptr) {
        cout << "Idle Elevator ID: " << closestIdleElevator->getElevatorID() << " with distance: " << minIdleDistance << endl;
        closestIdleElevator->setDirection(direction);
        return closestIdleElevator->getElevatorID();
    }

    // If no elevators are available
    cout << "No elevator found." << endl;
    return -1; // -1 elevatorID doesnt exists therefore no elevators available
}

// Function to get the current floor of a specific elevator using elevatorId
int ElevatorControlSystem::getElevatorFloor(int elevatorId) const {
    // Iterate through all elevators
    for (Elevator* elevator : elevators) {
        if (elevator->getElevatorID() == elevatorId) { // Assuming getElevatorID() returns the elevator's ID
            return elevator->getCurrentFloor();
        }
    }

    // Elevator with given ID not found
    return -1;
}

void ElevatorControlSystem::addRequest(int elevatorId, int floor){
    // Get the elevator object
    Elevator* elevator = findElevatorById(elevatorId);
    if (elevator == nullptr) {
        cerr << "Elevator with ID " << elevatorId << " not found!" << endl;
        return;
    }
    // Add the requested floor to the elevator's request queue
    elevator->addRequest(floor);
}

// Function to move a specific elevator
void ElevatorControlSystem::moveElevator(int elevatorId) {
    // Get the elevator object
    Elevator* elevator = findElevatorById(elevatorId);
    if (elevator == nullptr) {
        cerr << "Elevator with ID " << elevatorId << " not found!" << endl;
        return;
    }

    // Get current floor of the elevator
    int currentFloor = elevator->getCurrentFloor();

    // Get the request queue of the elevator
    vector<int>& requestQueue = elevator->getRequestQueue(); // Get a reference to the request queue

    // If the request queue is empty, there is no need to move
    if (requestQueue.empty()) {
        elevator->setDirection(0); // Set elevator direction to idle
        return; // Exit the function early
    }

    // Print the elevator ID and its request queue
    cout << "Elevator " << elevatorId << " Request Queue: ";
    for (int floor : requestQueue) {
        cout << floor << " ";
    }
    cout << endl;

    // Sort the request queue based on distance from the current floor
    sort(requestQueue.begin(), requestQueue.end(), [&](int floor1, int floor2) {
        return abs(floor1 - currentFloor) < abs(floor2 - currentFloor);
    });

    // Determine the direction of movement based on the closest remaining floor
    int direction = (requestQueue.front() > currentFloor) ? 1 : -1;
    elevator->setDirection(direction);

    // Process each floor in the request queue sequentially
    while (!requestQueue.empty() && !safety_state && !readyForRequest) {

        qInfo("------------------------------------");
        emit statusUpdate("------------------------------------");

        // Move the elevator until it reaches the next requested floor or the safety state changes
        while (currentFloor != requestQueue.front() && !safety_state && !readyForRequest) {
            // Simulate the time it takes to move between floors by introducing a delay
            QEventLoop loop;
            QTimer::singleShot(1000, &loop, &QEventLoop::quit); // Adjust the delay time as needed (1000 milliseconds = 1 second)
            loop.exec();

            emit checkSafetySignals(); // Emit the checkSafetySignals signal.

            // Check for new requests periodically even while the elevator is in motion
            // Update the request queue and direction if new requests are found
            requestQueue = elevator->getRequestQueue();
            
            // Sort the request queue based on distance from the current floor
            sort(requestQueue.begin(), requestQueue.end(), [&](int floor1, int floor2) {
                return abs(floor1 - currentFloor) < abs(floor2 - currentFloor);
            });

            direction = (requestQueue.front() > currentFloor) ? 1 : -1;
            elevator->setDirection(direction);   
             

            // Move the elevator by one floor in the determined direction
            currentFloor += direction;
            elevator->moveToFloor(currentFloor);

            // Print elevator movement
            cout << "Elevator " << elevatorId << " moved to floor " << currentFloor << endl; //print to gui

            // emit the statusUpdate signal
            emit statusUpdate("Elevator ID #" + to_string(elevatorId) + ": Moved to floor " + to_string(currentFloor));
        }

        // Open the doors if the current floor is in the request queue
        if (currentFloor == requestQueue.front()) {
            openElevatorDoors(elevatorId);
            
            // Remove the current floor from the request queue
            requestQueue.erase(requestQueue.begin());

            // Simulate a delay of 5s
            QEventLoop loop;
            QTimer::singleShot(5000, &loop, &QEventLoop::quit); // Adjust the delay time as needed (1000 milliseconds = 1 second)
            loop.exec();

            closeElevatorDoors(elevatorId);

            qInfo("------------------------------------");
            emit statusUpdate("------------------------------------");
        }
    }
    // Set elevator direction to idle when there are no more requests
    elevator->setDirection(0);
    //checkElevators();
}



// Function to open the doors of a specific elevator
void ElevatorControlSystem::openElevatorDoors(int elevatorId) {
    // Find the elevator by ID
    Elevator* elevator = findElevatorById(elevatorId);
    if (elevator == nullptr) {
        cerr << "Elevator with ID " << elevatorId << " not found!" << endl;
        return;
    }

    // Check if the doors are already open
    if (!elevator->areDoorsOpen()) {
        // If not open, open the doors
        elevator->openDoors();
        cout << "Elevator " << elevatorId << " opening the doors." << endl;
        cout << "Elevator " << elevatorId << " rings the bell." << endl;
        emit statusUpdate("Elevator ID #" + to_string(elevatorId) + ": Opening doors [5s]");
        emit statusUpdate("Elevator ID #" + to_string(elevatorId) + ": Rings bell");
        
    } else {
        emit statusUpdate("Elevator ID #" + to_string(elevatorId) + ": Doors are opened.");
        cout << "Elevator " << elevatorId << " doors are already open." << endl;
    }
}

// Function to close the doors of a specific elevator
void ElevatorControlSystem::closeElevatorDoors(int elevatorId) {
    // Find the elevator by ID
    Elevator* elevator = findElevatorById(elevatorId);
    if (elevator == nullptr) {
        cerr << "Elevator with ID " << elevatorId << " not found!" << endl;
        return;
    }

    // Check if the doors are already closed
    if (elevator->areDoorsOpen()) {
        // If not closed, close the doors
        elevator->closeDoors();
        cout << "Elevator " << elevatorId << " closing the doors." << endl;
        cout << "Elevator " << elevatorId << " rings the bell." << endl;
        emit statusUpdate("Elevator ID #" + to_string(elevatorId) + ": Closing doors");
        emit statusUpdate("Elevator ID #" + to_string(elevatorId) + ": Rings bell");
    } else {
        emit statusUpdate("Elevator ID #" + to_string(elevatorId) + ": Doors are closed.");
        cout << "Elevator " << elevatorId << " doors are already closed." << endl;
    }
}


void ElevatorControlSystem::clearAllRequestQueues() {
    for (Elevator* elevator : elevators) {
        elevator->clearRequests();
    }
}
