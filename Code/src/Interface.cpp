#include "../include/Interface.h"

void Interface::open() {
    while(true){
        if(!displayMainMenu()){
            break;
        }
    }
}

bool Interface::displayMainMenu() {
    cout << '\n';
    usleep(800000);     // sleep in microseconds
    cout << char(218)<< string(4, char(196)) << " Travelling Salesman Problem " << string(3, char(196)) << char(191) << endl;
    cout << "|                                    |\n";
    cout << "|      1. Backtracking Algorithm     |\n";
    cout << "|     2. Triangular Approximation    |\n";
    cout << "|        3. Other Heuristics         |\n";
    cout << "|      4. TSP in the Real World      |\n";
    cout << "|              5. Exit               |\n";
    cout << "|                                    |\n";
    cout << char(192) << string(36, char(196)) << char(217) << endl;
    string choice;
    cout<<"Enter your choice: ";
    cin >> choice;

    cout << "\n";

    // Display the menu based on the prompt from the user

    try{
        switch (stoi(choice)) {
            case 1:
                backtracking_algorithm();
                break;
            case 2:
                triangular_approximation();
                break;
            case 3:
                other_heuristics();
                break;
            case 4:
                tsp_in_real_world();
                break;
            case 5:
                cout<<"Exiting program. Goodbye!"<<endl;
                return false;

            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    catch (invalid_argument &choice){
        cout << "Invalid Choice. Please try Again" << endl;
    }

    return true;
}

int Interface::choose_graph_type() {
    usleep(650000);     // sleep in microseconds
    cout << char(218)<< string(5, char(196)) << " Choose Which Graph to Use " << string(4, char(196)) << char(191) << endl;
    cout << "|                                    |\n";
    cout << "|           1. Toy Graphs            |\n";
    cout << "|        2. Real-World Graphs        |\n";
    cout << "|   3. Extra Fully Connected Graphs  |\n";
    cout << "|            4. Go Back              |\n";
    cout << "|                                    |\n";
    cout << char(192) << string(36, char(196)) << char(217) << endl;
    string choice;
    cout<<"Enter your choice: ";
    cin >> choice;

    cout << "\n";

    // Display the menu based on the prompt from the user

    try{
        switch (stoi(choice)) {
            case 1:
                return 1;
                break;
            case 2:
                return 2;
                break;
            case 3:
                return 3;
                break;
            case 4:
                return 4;
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    catch (invalid_argument &choice){
        cout << "Invalid Choice. Please try Again" << endl;
    }

    return 0;
}

// ============ Backtracking Functions ============== //

void Interface::backtracking_algorithm() {
    int mode = choose_graph_type();
    switch (mode) {
        case 1:
            this->fhs_.choose_toy_graph(mode);
            //missing functions;
            break;
        case 2:
            this->fhs_.choose_real_world_graph(mode);
            //missing functions;
            break;
        case 3:
            this->fhs_.choose_fully_connected_graph(mode);
            //missing functions;
        case 4:
            displayMainMenu();
            break;
    }
}


// ============ Triangular Approximation Functions ============== //

void Interface::triangular_approximation() {
    int mode = choose_graph_type();
    switch (mode) {
        case 1:
            this->fhs_.choose_toy_graph(mode);
            //missing functions;
            break;
        case 2:
            this->fhs_.choose_real_world_graph(mode);
            //missing functions;
            break;
        case 3:
            this->fhs_.choose_fully_connected_graph(mode);
            //missing functions;
        case 4:
            displayMainMenu();
            break;
    }
}

// ============ Other Heuristics ============== //

void Interface::other_heuristics() {
    int mode = choose_graph_type();
    switch (mode) {
        case 1:
            this->fhs_.choose_toy_graph(mode);
            //missing functions;
            break;
        case 2:
            this->fhs_.choose_real_world_graph(mode);
            //missing functions;
            break;
        case 3:
            this->fhs_.choose_fully_connected_graph(mode);
            //missing functions;
        case 4:
            displayMainMenu();
            break;
    }
}

// ============ TSP in Real World Functions ============== //

void Interface::tsp_in_real_world() {
    int mode = choose_graph_type();
    switch (mode) {
        case 1:
            this->fhs_.choose_toy_graph(mode);
            //missing functions;
            break;
        case 2:
            this->fhs_.choose_real_world_graph(mode);
            //missing functions;
            break;
        case 3:
            this->fhs_.choose_fully_connected_graph(mode);
            //missing functions;
        case 4:
            displayMainMenu();
            break;
    }
}