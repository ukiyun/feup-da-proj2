#include "../include/FileHandler.h"


// ============ Toy Graph Functions ============== //

vector<ToyGraph> FileHandler::get_toy_graph_vector() {
    return this->toy_graph_nodes_;
}

Graph FileHandler::get_toy_graph(){
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
    for(auto toy: toy_graph_nodes_) {
        if(toy.getOrigin()==ToyGraphInput.getOrigin() && toy.getDestination()==ToyGraphInput.getDestination() && toy.getDistance()==ToyGraphInput.getDistance() && toy.getOriginLabel()==ToyGraphInput.getOriginLabel() && toy.getDestinationLabel()==ToyGraphInput.getDestinationLabel()) {
            return;             // Exit function if Toy Graph Input is in the vector
        }
    }

    Node origin_node(ToyGraphInput.getOrigin());
    Node destination_node(ToyGraphInput.getDestination());

    // Adding The Nodes from the Toy CSV to the Toy Graph. In Toy Graph Input, the first Argument is one Node, and the Second is Another Node
    cout << "current nodes vector size: " << this->toy_graph_.get_nodes_vector().size()<< endl;
    cout << "current origin_node: " << origin_node.getNodeId() << endl;
    cout << "current destination_node: " << destination_node.getNodeId()<< endl;
    this->toy_graph_.add_node(&origin_node);
    this->toy_graph_.add_node(&destination_node);
    cout << "current nodes vector size: " << this->toy_graph_.get_nodes_vector().size()<< endl;



    this->toy_graph_nodes_.push_back(ToyGraphInput);

    Edge new_edge(&origin_node, &destination_node, ToyGraphInput.getDistance());

    this->toy_graph_.find_node(&origin_node)->add_edge_to_node(&new_edge);

}

void FileHandler::read_ToyGraph_csv(string fileName){
    this->toy_graph_nodes_.clear();           // Reset the Vector with the Toy Graph Nodes as to start a new Vector
    this->toy_graph_.delete_graph();          // Reset the Toy Graph
    
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
             parse_ToyGraph_csv(line);       // If Line Position is not 0, i.e., the Header, Perform Parse Function to Divide the Line into ToyGraph data type and Add it to the Respective Vector
        }

        linePos = 1;
    }
    toyGraphCSV.close();                // Close the Open CSV
}

// ============ Real World Graph Functions ============== //

vector<Node> FileHandler::get_real_world_graph_vector() {
    return this->real_world_nodes_;
}

Graph FileHandler::get_real_world_graph() {
    return this->real_world_graph_;
}

void FileHandler::parse_RealWorld_Nodes_csv(string currentLine) {
    vector<string> parsed;                 // Create  a Vector to Store currentLine into Different Vector Elements for Easier Access
    stringstream ss(currentLine);      // Constructor of Object w/ Type stringstream, and currentLine is Copied to Said ss
    string singleColumn;                   // Auxiliary String

    while(getline(ss, singleColumn, ',')) {     // Read Data from Input Stream into String Variable, Delimiter Indicates the Division between the Different Attributes
        parsed.push_back(singleColumn);
    }

    // Since ID, Longitude and Latitude are Integers/Doubles, Convert said Strings to Ints/Doubles
    Node RealWorldInput(stoi(parsed[0]), stod(parsed[1]), stod(parsed[2]));


    // Check if Toy Graph is not already in the vector
    for(auto node: real_world_nodes_) {
        if(node.getNodeId()==RealWorldInput.getNodeId() && node.getNodeLongitude()==RealWorldInput.getNodeLongitude() && node.getNodeLatitude()==RealWorldInput.getNodeLatitude()) {
            return;             // Exit function if Real World Input is in the vector
        }
    }

    // Adding The Nodes from the Real World CSV to the Real World Graph.
    this->real_world_graph_.add_node(&RealWorldInput);
    this->real_world_nodes_.push_back(RealWorldInput);
}

void FileHandler::parse_RealWorld_Edges_csv(string currentLine) {
    vector<string> parsed;                 // Create  a Vector to Store currentLine into Different Vector Elements for Easier Access
    stringstream ss(currentLine);      // Constructor of Object w/ Type stringstream, and currentLine is Copied to Said ss
    string singleColumn;                   // Auxiliary String

    while(getline(ss, singleColumn, ',')) {     // Read Data from Input Stream into String Variable, Delimiter Indicates the Division between the Different Attributes
        parsed.push_back(singleColumn);
    }

    // Since Origin, Destination are Nodes, Convert said String to Nodes
    // Since these Nodes have Integer ID, also Convert the String to Int
    Node Origin(stoi(parsed[0]));
    Node Destination(stoi(parsed[1]));

    // Input Created Nodes and Convert String with Distance to Double
    Edge RealWorldInput(&Origin, &Destination, stod(parsed[2]));

    real_world_graph_.find_node(&Origin)->add_edge_to_node(&RealWorldInput);
}

void FileHandler::read_RealWorld_csv(string NodeFilePath, string EdgeFilePath){
    this->real_world_nodes_.clear();                 // Reset the Vector with the Real World Graph Nodes as to start a new Vector
    this->real_world_graph_.delete_graph();          // Reset the Real World Graph

    // ---------------------- Node Handling ---------------------- //
    fstream realWorldNodesCSV;                      // Declare FileStream Object
    realWorldNodesCSV.open(NodeFilePath);        // NodeFilePath is Passed as Constructor and Open the File

    // This CSV has a header
    int linePos = 0;

    if(realWorldNodesCSV.fail()) {                   // If Real World Graph CSV doesn't open, i.e., open fails
        cerr << "Unable to open specified file: " << NodeFilePath << endl;     // Print Error Message
    }

    string line;
    while(getline(realWorldNodesCSV, line)) {
        if(line.empty()) {              // Skip Eventual Empty Lines in the CSV
            continue;
        }

        if(linePos == 1){
            parse_RealWorld_Nodes_csv(line);      // Perform Parse Function to Divide the Line into readable data
        }

        linePos = 1;
    }

    realWorldNodesCSV.close();                          // Close the Open CSV


    // ---------------------- Edge Handling ---------------------- //
    fstream realWorldEdgesCSV;                      // Declare FileStream Object
    realWorldNodesCSV.open(EdgeFilePath);        // EdgeFilePath is Passed as Constructor and Open the File

    // This CSV has a header
    int linePos2 = 0;

    if(realWorldEdgesCSV.fail()) {                   // If Real World Graph CSV doesn't open, i.e., open fails
        cerr << "Unable to open specified file: " << NodeFilePath << endl;     // Print Error Message
    }

    string lined;
    while(getline(realWorldEdgesCSV, lined)) {
        if(line.empty()) {              // Skip Eventual Empty Lines in the CSV
            continue;
        }

        if(linePos2 == 1){
            parse_RealWorld_Edges_csv(lined);      // Perform Parse Function to Divide the Line into readable data
        }

        linePos2 = 1;
    }

    realWorldEdgesCSV.close();                          // Close the Open CSV

}


// ============ Extra Fully Connected Graph Functions ============== //

vector<ToyGraph> FileHandler::get_fully_connected_graph_vector() {
    return this->fully_connected_nodes_;
}

Graph FileHandler::get_fully_connected_graph() {
    return this->fully_connected_graph_;
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

    Node origin_node(FullyConnectedInput.getOrigin());
    Node destination_node(FullyConnectedInput.getDestination());

    // Adding The Nodes from the Toy CSV to the Toy Graph. In Toy Graph Input, the first Argument is one Node, and the Second is Another Node
    this->fully_connected_graph_.add_node(&origin_node);
    this->fully_connected_graph_.add_node(&destination_node);


    this->fully_connected_nodes_.push_back(FullyConnectedInput);

    Edge new_edge(&origin_node, &destination_node, FullyConnectedInput.getDistance());

    fully_connected_graph_.find_node(&origin_node)->add_edge_to_node(&new_edge);
}

void FileHandler::read_FullyConnected_csv(string fileName){
    this->fully_connected_nodes_.clear();           // Clear vector to avoid overstacking graph results
    this->fully_connected_graph_.delete_graph();    // Reset the Fully Connected Graph

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


