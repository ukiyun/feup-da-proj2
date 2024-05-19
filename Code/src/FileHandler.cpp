#include "../include/FileHandler.h"
#include "../include/Graph.h"
#include "../include/ToyGraph.h"
#include <algorithm> // Include algorithm header for std::find_if

using namespace std;

vector<ToyGraph> FileHandler::get_toy_graph_vector() {
    return toy_graph_nodes_;
}

Graph FileHandler::get_toy_graph() {
    return toy_graph_;
}

void FileHandler::read_ToyGraph_csv(string fileName) {
    ifstream file(fileName);
    string line;
    while (getline(file, line)) {
        parse_ToyGraph_csv(line);
    }
    file.close();
}

void FileHandler::parse_ToyGraph_csv(string currentLine) {
    stringstream ss(currentLine);
    string token;

    getline(ss, token, ',');
    int origin = stoi(token);
    getline(ss, token, ',');
    int destination = stoi(token);
    getline(ss, token, ',');
    double distance = stod(token);
    getline(ss, token, ',');
    string label_origin = token;
    getline(ss, token, ',');
    string label_destination = token;

    ToyGraph ToyGraphInput(origin, destination, distance, label_origin, label_destination);

    // Use appropriate longitude and latitude for ToyGraph
    MyNode* origin_node = new MyNode(ToyGraphInput.getOrigin(), 0.0, 0.0);
    MyNode* destination_node = new MyNode(ToyGraphInput.getDestination(), 0.0, 0.0);

    Edge* edge = new Edge(origin_node, destination_node, ToyGraphInput.getDistance());
    toy_graph_.add_node(origin_node);
    toy_graph_.add_node(destination_node);
    toy_graph_.add_edge(edge);
}

vector<MyNode> FileHandler::get_real_world_graph_vector() {
    return real_world_nodes_;
}

Graph FileHandler::get_real_world_graph() {
    return real_world_graph_;
}

void FileHandler::read_RealWorld_csv(string NodeFilePath, string EdgeFilePath) {
    ifstream nodesFile(NodeFilePath);
    ifstream edgesFile(EdgeFilePath);
    string line;

    while (getline(nodesFile, line)) {
        parse_RealWorld_Nodes_csv(line);
    }

    while (getline(edgesFile, line)) {
        parse_RealWorld_Edges_csv(line);
    }

    nodesFile.close();
    edgesFile.close();
}

void FileHandler::parse_RealWorld_Nodes_csv(string currentLine) {
    stringstream ss(currentLine);
    string token;

    getline(ss, token, ',');
    int id = stoi(token);
    getline(ss, token, ',');
    double longitude = stod(token);
    getline(ss, token, ',');
    double latitude = stod(token);

    MyNode node(id, longitude, latitude);
    real_world_nodes_.push_back(node);
}

void FileHandler::parse_RealWorld_Edges_csv(string currentLine) {
    stringstream ss(currentLine);
    string token;

    getline(ss, token, ',');
    int originId = stoi(token);
    getline(ss, token, ',');
    int destinationId = stoi(token);
    getline(ss, token, ',');
    double distance = stod(token);

    // Assuming nodes are already created and stored in real_world_nodes_
    auto originNode = find_if(real_world_nodes_.begin(), real_world_nodes_.end(), [originId](const MyNode& node) {
        return node.getNodeId() == originId;
    });

    auto destinationNode = find_if(real_world_nodes_.begin(), real_world_nodes_.end(), [destinationId](const MyNode& node) {
        return node.getNodeId() == destinationId;
    });

    if (originNode != real_world_nodes_.end() && destinationNode != real_world_nodes_.end()) {
        MyNode* origin_node_ptr = &(*originNode);
        MyNode* destination_node_ptr = &(*destinationNode);
        Edge* edge = new Edge(origin_node_ptr, destination_node_ptr, distance);
        real_world_graph_.add_edge(edge);
    }
}

vector<ToyGraph> FileHandler::get_fully_connected_graph_vector() {
    return fully_connected_nodes_;
}

Graph FileHandler::get_fully_connected_graph() {
    return fully_connected_graph_;
}

void FileHandler::read_FullyConnected_csv(string filePath) {
    ifstream file(filePath);
    string line;
    while (getline(file, line)) {
        parse_FullyConnected_csv(line);
    }
    file.close();
}

void FileHandler::parse_FullyConnected_csv(string currentLine) {
    stringstream ss(currentLine);
    string token;

    getline(ss, token, ',');
    int origin = stoi(token);
    getline(ss, token, ',');
    int destination = stoi(token);
    getline(ss, token, ',');
    double distance = stod(token);

    ToyGraph FullyConnectedInput(origin, destination, distance);

    MyNode* origin_node = new MyNode(FullyConnectedInput.getOrigin(), 0.0, 0.0);
    MyNode* destination_node = new MyNode(FullyConnectedInput.getDestination(), 0.0, 0.0);

    Edge* edge = new Edge(origin_node, destination_node, FullyConnectedInput.getDistance());
    fully_connected_graph_.add_node(origin_node);
    fully_connected_graph_.add_node(destination_node);
    fully_connected_graph_.add_edge(edge);
}

void FileHandler::add_nodes_to_graph(Graph* graph) {
    for (auto& node : real_world_nodes_) {
        graph->add_node(&node);
    }
}
