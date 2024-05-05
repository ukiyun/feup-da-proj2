#include "../include/FileHandler.h"


// ============ Toy Graph Functions ============== //

vector<ToyGraph> FileHandler::get_toy_graph_vector() {
    return this->toy_graph_;
}

void FileHandler::parse_ToyGraph_csv(string currentLine){
    vector<string> parsed;                 // Create  a Vector to Store currentLine into Different Vector Elements for Easier Access
    stringstream ss(currentLine);      // Constructor of Object w/ Type stringstream, and currentLine is Copied to Said ss
    string singleColumn;                   // Auxiliary String

    while(getline(ss, singleColumn, ',')) {     // Read Data from Input Stream into String Variable, Delimiter Indicates the Division between the Different Attributes
        parsed.push_back(singleColumn);
    }

    // Since Origin, Destination and Distance are Integers, Convert said String to Ints
    ToyGraph ToyGraphInput;

    if(parsed.size()<=3){
        ToyGraphInput = ToyGraph(stoi(parsed[0]), stoi(parsed[1]), stof(parsed[2]));
    }
    else{
        ToyGraphInput = ToyGraph(stoi(parsed[0]), stoi(parsed[1]), stof(parsed[2]), parsed[3], parsed[4]);
    }



    // Check if Toy Graph is not already in the vector
    for(auto toy: toy_graph_) {
        if(toy.getOrigin()==ToyGraphInput.getOrigin() && toy.getDestination()==ToyGraphInput.getDestination() && toy.getDistance()==ToyGraphInput.getDistance() && toy.getOriginLabel()==ToyGraphInput.getOriginLabel() && toy.getDestinationLabel()==ToyGraphInput.getDestinationLabel()) {
            return;             // Exit function if Toy Graph Input is in the vector
        }
    }

    // Add Item to Graph ?

    this->toy_graph_.push_back(ToyGraphInput);
}

void FileHandler::read_ToyGraph_csv(string fileName){
    this->toy_graph_.clear();           // Reset the Vector with the Toy Graph Nodes as to start a new Vector
    fstream toyGraphCSV;               // Declare FileStream Object
    string filePath = "../Code/datasets/Toy-Graphs/" + fileName;

    toyGraphCSV.open(filePath);     // filePath is Passed as Constructor and Opens File with that
    int linePos = 0;                   // Line Position to Handle Possible Headers in CSV

    if(toyGraphCSV.fail()) {           // If Toy Graph CSV doesn't open, i.e., open fails
        cerr << "Unable to open specified file: " << fileName << endl;     // Print Error Message
    }

    string line;

    while(getline(toyGraphCSV, line)) {
        if(line.empty()) {              // Skip Eventual Empty Lines in the CSV
            continue;
        }
        if(linePos == 1) {
             // function has stack error
             parse_ToyGraph_csv(line);       // If Line Position is not 0, i.e., the Header, Perform Parse Function to Divide the Line into ToyGraph data type and Add it to the Respective Vector
        }

        linePos = 1;
    }
    toyGraphCSV.close();                // Close the Open CSV
}

// ============ Real World Graph Functions ============== //

vector<int> FileHandler::get_real_world_graph_vector() {
    return this->real_world_;
}

void FileHandler::parse_RealWorld_csv(string currentLine){
// Data Type is Different Solve it after
}

void FileHandler::read_RealWorld_csv(string NodeFilePath, string EdgeFilePath){
    // Dont forget to clear vector before initializing a new one
    // Data Type is Different Solve it after
}


// ============ Extra Fully Connected Graph Functions ============== //

vector<ToyGraph> FileHandler::get_fully_connected_graph_vector() {
    return this->fully_connected_;
}

void FileHandler::parse_FullyConnected_csv(string currentLine){
    vector<string> parsed;                 // Create  a Vector to Store currentLine into Different Vector Elements for Easier Access
    stringstream ss(currentLine);      // Constructor of Object w/ Type stringstream, and currentLine is Copied to Said ss
    string singleColumn;                   // Auxiliary String

    while(getline(ss, singleColumn, ',')) {     // Read Data from Input Stream into String Variable, Delimiter Indicates the Division between the Different Attributes
        parsed.push_back(singleColumn);
    }

    // Since Origin, Destination and Distance are Integers, Convert said String to Ints
    ToyGraph FullyConnectedInput(stoi(parsed[0]), stoi(parsed[1]), stof(parsed[2]));     // Construct Toy Graph Item with Parameters from String Vector

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

void FileHandler::read_FullyConnected_csv(string fileName){
    this->fully_connected_.clear();           // Clear vector to avoid overstacking graph results
    fstream fullyConnectedCSV;               // Declare FileStream Object
    string filePath = "../Code/datasets/Extra_Fully_Connected_Graphs/" + fileName;
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
        parse_FullyConnected_csv(line);      // Perform Parse Function to Divide the Line into ToyGraph data type and Add it to the Fully Connected Vector
    }

    fullyConnectedCSV.close();                // Close the Open CSV
}

