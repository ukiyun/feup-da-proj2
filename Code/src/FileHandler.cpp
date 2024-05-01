#include "../include/FileHandler.h"

// ============ Toy Graph Functions ============== //

vector<ToyGraph> FileHandler::get_toy_graph_vector() {
    return this->toy_graph_;
}

void parse_ToyGraph_csv(string currentLine){
    vector<string> parsed;                 // Create  a Vector to Store currentLine into Different Vector Elements for Easier Access
    stringstream ss(currentLine);      // Constructor of Object w/ Type stringstream, and currentLine is Copied to Said ss
    string singleColumn;                   // Auxiliary String

    while(getline(ss, singleColumn, ',')) {     // Read Data from Input Stream into String Variable, Delimiter Indicates the Division between the Different Attributes
        parsed.push_back(singleColumn);
    }

    // Since Origin, Destination and Distance are Integers, Convert said String to Ints
    ToyGraph ToyGraphInput(stoi(parsed[0]), stoi(parsed[1]), stof(parsed[2]), parsed[3], parsed[4]);     // Construct Toy Graph Item with Parameters from String Vector

    // Check if Toy Graph is not already in the vector
    for(auto toy: get_toy_graph_vector()) {
        if(toy.getOrigin()==ToyGraphInput.getOrigin() && toy.getDestination()==ToyGraphInput.getDestination() && toy.getDistance()==ToyGraphInput.getDistance() && toy.getOriginLabel()==ToyGraphInput.getOriginLabel() && toy.getDestinationLabel()==ToyGraphInput.getDestinationLabel()) {
            return;             // Exit function if Toy Graph Input is in the vector
        }
    }

    // Add Item to Graph ?
    toy_graph_.push_back(ToyGraphInput);
}

void read_ToyGraph_csv(string filePath){
    fstream toyGraphCSV;               // Declare FileStream Object
    toyGraphCSV.open(filePath);     // filePath is Passed as Constructor and Opens File with that Path
    int linePos = 0;                   // Line Position to Handle Possible Headers in CSV

    if(toyGraphCSV.fail()) {           // If Toy Graph CSV doesn't open, i.e., open fails
        cerr << "Unable to open specified file: " << filePath << endl;     // Print Error Message
    }

    string line;
    while(getline(toyGraphCSV, line)) {
        if(line.empty()) {              // Skip Eventual Empty Lines in the CSV
            continue;
        }

        if(linePos == 1) {
            parse_ToyGraph_csv(line);       // If Line Position is not 0, i.e., the Header, Perform Parse Function to Divide the Line into ToyGraph data type and Add it to the Respective Vector
        }
        linePos = 1;
    }

    toyGraphCSV.close();                // Close the Open CSV
}


void FileHandler::choose_toy_graph(int mode) {
    usleep(650000);     // sleep in microseconds
    cout << char(218)<< string(4, char(196)) << " Choose the Toy Graph to Use " << string(3, char(196)) << char(191) << endl;
    cout << "|                                    |\n";
    cout << "|          1. Shipping Graph         |\n";
    cout << "|          2. Stadiums Graph         |\n";
    cout << "|          3. Tourism Graph          |\n";
    cout << "|             4. Go Back             |\n";
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
                read_ToyGraph_csv("../datasets/Toy-Graphs/shipping.csv");
                break;
            case 2:
                read_ToyGraph_csv("../datasets/Toy-Graphs/stadiums.csv");
                break;
            case 3:
                read_ToyGraph_csv("../datasets/Toy-Graphs/tourism.csv");
                break;
            case 4:
                Interface a;
                switch(mode){
                    case 1:
                        a.backtracking_algorithm();
                        break;
                    case 2:
                        a.triangular_approximation();
                        break;
                    case 3:
                        a.other_heuristics();
                        break;
                    case 4:
                        a.tsp_in_real_world();
                        break;
                    default:
                        break;
                }
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    catch (invalid_argument &choice){
        cout << "Invalid Choice. Please try Again" << endl;
    }
}


// ============ Real World Graph Functions ============== //

vector<int> FileHandler::get_real_world_graph_vector() {
    return this->real_world_;
}

void parse_RealWorld_csv(string currentLine){
// Data Type is Different Solve it after
}

void read_RealWorld_csv(string NodeFilePath, string EdgeFilePath){
// Data Type is Different Solve it after
}


void FileHandler::choose_real_world_graph(int mode) {
    usleep(650000);     // sleep in microseconds
    cout << char(218)<< string(4, char(196)) << " Choose the Real World Graph " << string(3, char(196)) << char(191) << endl;
    cout << "|                                    |\n";
    cout << "|             1. Graph 1             |\n";
    cout << "|             2. Graph 2             |\n";
    cout << "|             3. Graph 3             |\n";
    cout << "|             4. Go Back             |\n";
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
                read_RealWorld_csv("../datasets/Real-world Graphs/graph1/nodes.csv", "../datasets/Real-world Graphs/graph1/edges.csv");
                break;
            case 2:
                read_RealWorld_csv("../datasets/Real-world Graphs/graph2/nodes.csv", "../datasets/Real-world Graphs/graph2/edges.csv");
                break;
            case 3:
                read_RealWorld_csv("../datasets/Real-world Graphs/graph3/nodes.csv", "../datasets/Real-world Graphs/graph3/edges.csv");
                break;
            case 4:
                Interface a;
                switch(mode){
                    case 1:
                        a.backtracking_algorithm();
                        break;
                    case 2:
                        a.triangular_approximation();
                        break;
                    case 3:
                        a.other_heuristics();
                        break;
                    case 4:
                        a.tsp_in_real_world();
                        break;
                    default:
                        break;
                }
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    catch (invalid_argument &choice){
        cout << "Invalid Choice. Please try Again" << endl;
    }
}


// ============ Extra Fully Connected Graph Functions ============== //
vector<ToyGraph> FileHandler::get_fully_connected_graph_vector() {
    return this->fully_connected_;
}

void parse_FullyConnected_csv(string currentLine){
    vector<string> parsed;                 // Create  a Vector to Store currentLine into Different Vector Elements for Easier Access
    stringstream ss(currentLine);      // Constructor of Object w/ Type stringstream, and currentLine is Copied to Said ss
    string singleColumn;                   // Auxiliary String

    while(getline(ss, singleColumn, ',')) {     // Read Data from Input Stream into String Variable, Delimiter Indicates the Division between the Different Attributes
        parsed.push_back(singleColumn);
    }

    // Since Origin, Destination and Distance are Integers, Convert said String to Ints
    ToyGraph FullyConnectedInput(stoi(parsed[0]), stoi(parsed[1]), stof(parsed[2]), parsed[3], parsed[4]);     // Construct Toy Graph Item with Parameters from String Vector

    // Check if Toy Graph is not already in the vector
    for(auto fully: get_fully_connected_graph_vector()) {
        if(fully.getOrigin()==FullyConnectedInput.getOrigin() && fully.getDestination()==FullyConnectedInput.getDestination() && fully.getDistance()==FullyConnectedInput.getDistance() && fully.getOriginLabel()==FullyConnectedInput.getOriginLabel() && fully.getDestinationLabel()==FullyConnectedInput.getDestinationLabel()) {
            return;             // Exit function if Fully Connected Input is in the vector
        }
    }

    fully_connected_.push_back(FullyConnectedInput);
    // Add Item to Graph ? Node and Edge
    // Node = Origin + Destination + Eventual Labels
    // Edge = Vertex Origin + Vertex Destination + Distance
}

void read_FullyConnected_csv(string filePath){
    fstream fullyConnectedCSV;               // Declare FileStream Object
    fullyConnectedCSV.open(filePath);     // filePath is Passed as Constructor and Opens File with that Path
    // This CSV doesn't have a Header

    if(fullyConnectedCSV.fail()) {           // If Fully Connected Graph CSV doesn't open, i.e., open fails
        cerr << "Unable to open specified file: " << filePath << endl;     // Print Error Message
    }

    string line;
    while(getline(fullyConnectedCSV, line)) {
        if(line.empty()) {              // Skip Eventual Empty Lines in the CSV
            continue;
        }
        parse_ToyGraph_csv(line);      // Perform Parse Function to Divide the Line into ToyGraph data type and Add it to the Fully Connected Vector
    }

    fullyConnectedCSV.close();                // Close the Open CSV
}


void FileHandler::choose_fully_connected_graph(int mode) {
    usleep(650000);     // sleep in microseconds
    cout << char(218)<< string(3, char(196)) << " Choose the Extra Graph to Use " << string(2, char(196)) << char(191) << endl;
    cout << "|                                    |\n";
    cout << "|            1. 25 Nodes             |\n";
    cout << "|            2. 50 Nodes             |\n";
    cout << "|            3. 75 Nodes             |\n";
    cout << "|            4. 100 Nodes            |\n";
    cout << "|            5. 200 Nodes            |\n";
    cout << "|            6. 300 Nodes            |\n";
    cout << "|            7. 400 Nodes            |\n";
    cout << "|            8. 500 Nodes            |\n";
    cout << "|            9. 600 Nodes            |\n";
    cout << "|            10. 700 Nodes           |\n";
    cout << "|            11. 800 Nodes           |\n";
    cout << "|            12. 900 Nodes           |\n";
    cout << "|            13. Go Back             |\n";
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
                read_FullyConnected_csv("../datasets/Extra_Fully_Connected_Graphs/edges_25.csv");
                break;
            case 2:
                read_FullyConnected_csv("../datasets/Extra_Fully_Connected_Graphs/edges_50.csv");
                break;
            case 3:
                read_FullyConnected_csv("../datasets/Extra_Fully_Connected_Graphs/edges_75.csv");
                break;
            case 4:
                read_FullyConnected_csv("../datasets/Extra_Fully_Connected_Graphs/edges_100.csv");
                break;
            case 5:
                read_FullyConnected_csv("../datasets/Extra_Fully_Connected_Graphs/edges_200.csv");
                break;
            case 6:
                read_FullyConnected_csv("../datasets/Extra_Fully_Connected_Graphs/edges_300.csv");
                break;
            case 7:
                read_FullyConnected_csv("../datasets/Extra_Fully_Connected_Graphs/edges_400.csv");
                break;
            case 8:
                read_FullyConnected_csv("../datasets/Extra_Fully_Connected_Graphs/edges_500.csv");
                break;
            case 9:
                read_FullyConnected_csv("../datasets/Extra_Fully_Connected_Graphs/edges_600.csv");
                break;
            case 10:
                read_FullyConnected_csv("../datasets/Extra_Fully_Connected_Graphs/edges_700.csv");
                break;
            case 11:
                read_FullyConnected_csv("../datasets/Extra_Fully_Connected_Graphs/edges_800.csv");
                break;
            case 12:
                read_FullyConnected_csv("../datasets/Extra_Fully_Connected_Graphs/edges_900.csv");
                break;
            case 13:
                Interface a;
                switch(mode){
                    case 1:
                        a.backtracking_algorithm();
                        break;
                    case 2:
                        a.triangular_approximation();
                        break;
                    case 3:
                        a.other_heuristics();
                        break;
                    case 4:
                        a.tsp_in_real_world();
                        break;
                    default:
                        break;
                }
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    catch (invalid_argument &choice){
        cout << "Invalid Choice. Please try Again" << endl;
    }
}
