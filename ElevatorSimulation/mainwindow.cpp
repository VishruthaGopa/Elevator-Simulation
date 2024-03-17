#include "mainwindow.h"
#include "ui_mainwindow.h"

// store the current moving elevator ID
//int elevatorId = -1;

// Constructor for MainWindow class
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Setup the UI
    ui->setupUi(this);

    // Initialize the ElevatorControlSystem
    ecs = new ElevatorControlSystem();
    elevatorId = -1;

    // Update the system display
    updateSystemDisplay();

    // Disable the down button when starting floor is 1.
    ui->downButton->setEnabled(false);

    // Connect signals from floor panel buttons to corresponding slots
    connect(ui->upButton, SIGNAL(released()), this, SLOT (upButtonPressed()));
    connect(ui->downButton, SIGNAL(released()), this, SLOT (downButtonPressed()));

    // Connect signals from elevator buttons to corresponding slots
    connect(ui->openDoorButton, SIGNAL(released()), this, SLOT (openButtonPressed()));
    connect(ui->closeDoorButton, SIGNAL(released()), this, SLOT (closeButtonPressed()));
    connect(ui->button1, SIGNAL(released()), this, SLOT (floorButtonPressed()));
    connect(ui->button2, SIGNAL(released()), this, SLOT (floorButtonPressed()));
    connect(ui->button3, SIGNAL(released()), this, SLOT (floorButtonPressed()));
    connect(ui->button4, SIGNAL(released()), this, SLOT (floorButtonPressed()));
    connect(ui->button5, SIGNAL(released()), this, SLOT (floorButtonPressed()));
    connect(ui->button6, SIGNAL(released()), this, SLOT (floorButtonPressed()));
    connect(ui->button7, SIGNAL(released()), this, SLOT (floorButtonPressed()));

    // Connect safety buttons to corresponding slots
    connect(ui->helpButton, &QPushButton::released, this, [this]() { handleSafetyButtonPress("helpButton"); });
    connect(ui->powerOutage, &QPushButton::released, this, [this]() { handleSafetyButtonPress("powerOutage"); });
    connect(ui->blockDoor, &QPushButton::released, this, [this]() { handleSafetyButtonPress("blockDoor"); });
    connect(ui->fireAlarm, &QPushButton::released, this, [this]() { handleSafetyButtonPress("fireAlarm"); });
    connect(ui->overload, &QPushButton::released, this, [this]() { handleSafetyButtonPress("overload"); });

    // Initialize console log scrolling area
    consoleLogScroll = new QWidget(ui->ConsoleLog_scroll);
    scrollLayout = new QVBoxLayout(consoleLogScroll);
    scrollLayout->setAlignment(Qt::AlignTop); // start widgets at the top

    // Disable up/down buttons based on starting floor
    connect(ui->startingFloorInput, SIGNAL(valueChanged(int)), this, SLOT (startingFloorSpinBox()));
    
    // Connect the statusUpdate signal from ElevatorControlSystem to the updateLogMessage slot in MainWindow
    connect(ecs, &ElevatorControlSystem::statusUpdate, this, &MainWindow::updateLogMessage);

    // connect ecs signal to a slot in the MainWindow class responsible for checking the safety signals:
    connect(ecs, &ElevatorControlSystem::checkSafetySignals, this, &MainWindow::checkSafetySignals);



    // Set up QTimer to periodically call moveElevator
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        // Iterate through elevators and call moveElevator for each elevator
        for (Elevator* elevator : ecs->elevators) {
            // Call moveElevator function of ElevatorControlSystem instance
            ecs->moveElevator(elevator->getElevatorID());
        }
    });
    timer->start(3000); // Adjust the interval as needed (1000 milliseconds = 1 second)
   
}

// Slot to update log message with the received message and system display on GUI
void MainWindow::updateLogMessage(string message) {
    logMessage(message);
    updateSystemDisplay();
}

// Function to log a message in the console log scrolling area
void MainWindow::logMessage(const string &message) {
    // Convert the string message to QString
    QString qstr = QString::fromStdString(message);
    
    // Create a new QLabel with the message
    QLabel *label = new QLabel(qstr);

    // To get the scrolling area, set the console scroll area's widget to the console layout
    scrollLayout->addWidget(label);
    ui->ConsoleLog_scroll->setWidget(consoleLogScroll);
}

// Destructor for MainWindow class
MainWindow::~MainWindow(){
    delete ui;
    delete ecs; 
}

// Function to handle floor panel request
void MainWindow::handleFloorPanelRequest(int direction) {
    int startingFloor = ui->startingFloorInput->value();
    ecs->pressedSignal = "NewRequest";
    ecs->readyForRequest = true;
    string directionStr = (direction == 1) ? "UP" : "DOWN";
    qInfo("Request Received: %s at floor %d", directionStr.c_str(), startingFloor);
    logMessage("Request Received: " + directionStr + " at floor " + to_string(startingFloor));
    
    // Print all Elevator's status
    ecs->checkElevators();

    // Call allocateElevator function from ElevatorControlSystem
    // elevatorId is the current allocated and only moving elevator
    elevatorId = ecs->allocateElevator(startingFloor, direction);

    if (elevatorId != -1) {
        qInfo("ECS allocated request.");
        logMessage("ECS allocated request");

        // Log the allocated elevator ID
        qInfo("Allocated Elevator ID #%d for %s request at floor %d", elevatorId, directionStr.c_str(), startingFloor);
        logMessage("Elevator ID #" + to_string(elevatorId) + ": Servicing " + directionStr + " request at floor " + to_string(startingFloor));

        ecs->addRequest(elevatorId, startingFloor);

    } else {
        qInfo("No avaliable elevator.");
        logMessage("No available elevator.");
    }

    ecs->readyForRequest = false;

}

// Slot to handle up button press
void MainWindow::upButtonPressed() {
    handleFloorPanelRequest(1); // UP direction
}

// Slot to handle down button press
void MainWindow::downButtonPressed() {
    handleFloorPanelRequest(-1); // DOWN direction
}

// Slot to handle open door button press
void MainWindow::openButtonPressed(){
    qInfo("openDoorButtonPressed");
    ecs->openElevatorDoors(elevatorId);
}

// Slot to handle close door button press
void MainWindow::closeButtonPressed(){
    qInfo("closeDoorButtonPressed");    
    ecs->closeElevatorDoors(elevatorId);
}

// Slot to handle floor button press
void MainWindow::floorButtonPressed(){
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    int requestedFloor = 0;
    if (button != nullptr) {
        // Determine the requested floor based on the button pressed
        if (button == ui->button1) {
            requestedFloor = 1;
        } else if (button == ui->button2) {
            requestedFloor = 2;
        } else if (button == ui->button3) {
            requestedFloor = 3;
        } else if (button == ui->button4) {
            requestedFloor = 4;
        } else if (button == ui->button5) {
            requestedFloor = 5;
        } else if (button == ui->button6) {
            requestedFloor = 6;
        } else if (button == ui->button7) {
            requestedFloor = 7;
        }

        qInfo("Floor %d button pressed", requestedFloor);
        logMessage("Floor " + to_string(requestedFloor) + " button pressed");
    }

    ecs->addRequest(elevatorId, requestedFloor);
}

// Slot to handle safety button press
void MainWindow::handleSafetyButtonPress(const QString &buttonName) {
    ecs->safety_state = true;     // Set safety state to true

    if (buttonName == "helpButton") {
        qInfo("Help Button Pressed");
        ecs->pressedSignal = "Help Button";

        // Generate a random number between 1 and 10
        int randomNumber = rand() % 10 + 1;
        cout << "Random number..."<< randomNumber << endl;

        if (randomNumber <= 6) { // 60% chance of connecting to building safety service
            // Connect to building safety service through a voice connection
            cout << "Elevator " << elevatorId << " connecting to building safety service through voice connection..." << endl;
            logMessage("Elevator ID #" + to_string(elevatorId) + ": Connecting to building safety service through voice connection...");
        } else { // 30% chance of placing a 911 emergency call
            // Create a QTimer object
            QTimer *timer = new QTimer(this);

            // Set a single-shot timer for 5 seconds
            timer->setSingleShot(true);
            timer->start(000); // 5000 milliseconds = 5 seconds

            // Message indicating waiting for building safety service response
            cout << "Elevator " << elevatorId << " waiting for response from building safety service... [5s]" << endl;
            logMessage("Elevator ID #" + to_string(elevatorId) + ": Waiting for response from building safety service...[5s]");

            // Connect the timeout signal of the timer to a slot that places a 911 emergency call
            connect(timer, &QTimer::timeout, this, [this]() {
                // Place a 911 emergency call
                cout << "Elevator " << elevatorId << " has no response from building safety service. Placing a 911 emergency call." << endl;
                logMessage("Elevator ID #" + to_string(elevatorId) + ": No response from building safety service. Placing a 911 emergency call.");
            });
        }

        ecs->openElevatorDoors(elevatorId);

        ecs->safety_state = true;

    } else if (buttonName == "powerOutage") {
        qInfo("Power Outage Button Pressed");
        ecs->pressedSignal = "Power Outage";
        cout << "Emergency: Power Outage detected. All elevators are moving to safe floors."<<endl;
        cout << "Elevator " << elevatorId << " announces and displays 'Passengers are requested to disembark once the safe floor is reached.'"<<endl;
        logMessage("Emergency: Power Outage detected. All elevators are moving to safe floors.");
        logMessage("Elevator ID #" + to_string(elevatorId) + ": Announces 'Passengers are requested to disembark once the safe floor is reached.'");
        logMessage("Elevator ID #" + to_string(elevatorId) + ": Displays 'Disembark once the elevator stops.'");

        cout << "Elevator " << elevatorId << " Moving to the closest safe floor" << endl;
        logMessage("Elevator ID #" + to_string(elevatorId) + ": Moving to the closest safe floor");

        ecs->openElevatorDoors(elevatorId);

        // Hide all buttons after a power outage
        ui->ElevatorPanel->setVisible(false);
        ui->FloorPanel->setVisible(false);
        ui->powerOutage->setVisible(false);
        ui->blockDoor->setVisible(false);
        ui->fireAlarm->setVisible(false);
        ui->overload->setVisible(false);


    } else if (buttonName == "blockDoor") {
        qInfo("Block Door Button Pressed");
        ecs->pressedSignal = "Block Door";

        // Open the door immediately if it's closing
        Elevator* elevator = ecs->findElevatorById(elevatorId);
        if (elevator != nullptr) {
            ecs->closeElevatorDoors(elevatorId);
            cout << "Door opened due to obstruction." << endl;
            logMessage("Elevator ID #" + to_string(elevatorId) + ": Door opened due to obstruction.");
            elevator->openDoors();

            // Announce and display warning message
            cout << "Elevator " << elevatorId << " announces and displays: Warning! Door obstruction detected. Please do not obstruct the doors." << endl;
            logMessage("Elevator ID #" + to_string(elevatorId) + ": Announces 'Warning! Door obstruction detected. Please do not obstruct the doors.'");
            logMessage("Elevator ID #" + to_string(elevatorId) + ": Displays 'Warning! Door obstruction detected. Please do not obstruct the doors.'");

        } else {
            qWarning("Elevator not found");
        }

        ecs->safety_state = false;

    } else if (buttonName == "fireAlarm") {
        qInfo("Fire Alarm Button Pressed");
        ecs->pressedSignal = "Fire Alarm";
        cout << "Emergency: Fire alarm detected. All elevators are moving to safe floors."<<endl;
        cout << "Elevator " << elevatorId << " announces and displays 'Passengers are requested to disembark once the safe floor is reached.'"<<endl;
        logMessage("Emergency: Fire alarm detected. All elevators are moving to safe floors.");
        logMessage("Elevator ID #" + to_string(elevatorId) + ": Announces 'Passengers are requested to disembark once the safe floor is reached.'");
        logMessage("Elevator ID #" + to_string(elevatorId) + ": Displays 'Disembark once the elevator stops.'");

        cout << "Elevator " << elevatorId << " Moving to the closest safe floor" << endl;
        logMessage("Elevator ID #" + to_string(elevatorId) + ": Moving to the closest safe floor");

        // Hide all buttons after a fire alarm
        ui->ElevatorPanel->setVisible(false);
        ui->FloorPanel->setVisible(false);
        ui->powerOutage->setVisible(false);
        ui->blockDoor->setVisible(false);
        ui->fireAlarm->setVisible(false);
        ui->overload->setVisible(false);

        ecs->openElevatorDoors(elevatorId);

        // Clear all requests in the elevators managed by ecs
        ecs->clearAllRequestQueues();


    } else if (buttonName == "overload") {
        qInfo("Overload Button Pressed");
        ecs->pressedSignal = "Overload";
        cout << "Emergency: Overload detected."<<endl;
        cout << "Elevator " << elevatorId << " announces and displays 'Please reduce the load.'"<<endl;
        logMessage("Emergency: Overload detected.");
        logMessage("Elevator ID #" + to_string(elevatorId) + ": Announces 'Please reduce the load.'");
        logMessage("Elevator ID #" + to_string(elevatorId) + ": Displays 'Please reduce the load'");

        // Create a QTimer object
        QTimer *timer = new QTimer(this);

        // Set a single-shot timer for 10 seconds
        timer->setSingleShot(true);
        timer->start(10000); // 10000 milliseconds = 10 seconds

        // Message indicating that the program is resuming after a 10-second delay
        cout << "Resuming normal operation after a 10-second delay." << endl;
        logMessage("Resuming normal operation after a 10-second delay.");

        // Connect the timeout signal of the timer to a slot that resumes the program after 10 seconds
        connect(timer, &QTimer::timeout, this, [this]() {
            // Resume the program here
            cout << "Overload emergency resolved. Resuming normal operation." << endl;
            logMessage("Overload emergency resolved. Resuming normal operation.");
            ecs->safety_state = false;
        });

    }
}

// Slot to handle starting floor spin box value change
void MainWindow::startingFloorSpinBox(){
    int floor = ui->startingFloorInput->value();
    //qInfo("%d", floor);
    ui->upButton->setEnabled(true);
    ui->downButton->setEnabled(true);

    if (floor == 1) {
        ui->downButton->setEnabled(false); 
    }
    if (floor == 7) {
        ui->upButton->setEnabled(false);
    }
}

// Function to update the system display
void MainWindow::updateSystemDisplay() {
    // Update the display of Elevator E1
    ui->E1_label->setText(QString::number(ecs->getElevatorFloor(1)));

    // Update the display of Elevator E2
    ui->E2_label->setText(QString::number(ecs->getElevatorFloor(2)));

    // Update the display of Elevator E3
    ui->E3_label->setText(QString::number(ecs->getElevatorFloor(3)));

}

// Function to check safety signals
bool MainWindow::checkSafetySignals() {
    bool anySignalPressed = ui->powerOutage->isDown() || ui->blockDoor->isDown() || ui->fireAlarm->isDown() || ui->overload->isDown() || ui->helpButton->isDown();

    if (anySignalPressed) {
        // Print which safety signal button is pressed
        qInfo("Safety signal detected: ");
        if (ui->powerOutage->isDown()) {
            qInfo("Power Outage");
            ecs->pressedSignal = "Power Outage";
        }
        if (ui->blockDoor->isDown()) {
            qInfo("Block Door");
            ecs->pressedSignal = "Block Door";
        }
        if (ui->fireAlarm->isDown()) {
            qInfo("Fire Alarm");
            ecs->pressedSignal = "Fire Alarm";
        }
        if (ui->overload->isDown()) {
            qInfo("Overload");
            ecs->pressedSignal = "Overload";
        }
        if (ui->helpButton->isDown()) {
            qInfo("Help Button");
            ecs->pressedSignal = "Help Button";
        }
        
        ecs->safety_state = true;

        return false; // Return false if any safety signal button is pressed
    } else {
        return true; // Return true if no safety signal button is pressed
    }
}
