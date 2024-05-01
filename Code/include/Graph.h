#ifndef GRAPH_H
#define GRAPH_H

// C++ Libraries
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <cmath>

// Header Files


using namespace std;

class Node;

/// @class Edge
/// @brief A Class Dedicated to the Handling of Edges, that will Belong to a Graph
class Edge{
public:
    /// @brief A Constructor for the Toy Graph
    /// @param origin Edge's Origin Node
    /// @param destination Edge's Destination Node
    /// @param distance Double with the Edge Distance
    Edge(Node *origin, Node *destination, double distance);

    /// @brief A Default Empty Constructor for the Delivery Site
    Edge();

    /// @brief A Function used to get the Edge Origin Node
    /// @return Returns the Node of the  Edge Origin
    Node* getEdgeOrigin() const;

    /// @brief A Function used to get the Edge Destination Node
    /// @return Returns the Node of the  Edge Destination
    Node* getEdgeDestination() const;

    /// @brief A Function used to get the Edge Distance
    /// @return Returns the Integer of the Edge Distance
    double getEdgeDistance() const;

private:
    Node* edge_origin_;
    Node* edge_destination_;
    double edge_distance_;
};


/// @class Node
/// @brief A Class Dedicated to the Handling of Nodes, that will Belong to a Graph
class Node{
public:
    /// @brief A Constructor for the Toy Graph
    /// @param origin Integer with the Origin
    /// @param destination Integer with the Destination
    /// @param distance Integer with the Distance
    /// @param label_origin String with the Label of the Origin, can be empty or null
    /// @param label_destination String with the Label of the Destination, can be empty or null
    Node(int id, double node_longitude = 0, double node_latitude = 0);

    /// @brief A Default Empty Constructor for the Delivery Site
    Node();

    /// @brief A Function used to get the Id of the Node
    /// @return Returns the Integer of the Node ID
    int getNodeId() const;

    /// @brief A Function used to get the Longitude of the Node
    /// @return Returns the Double of the Node Longitude
    double getNodeLongitude() const;

    /// @brief A Function used to get the Latitude of the Node
    /// @return Returns the Double of the Node Latitude
    double getNodeLatitude() const;

private:
    int node_id_;
    double node_distance_;
    double node_longitude_;
    double node_latitude_;
};


/// @class Graph
/// @brief A Class Dedicated to the Handling of Graphs
class Graph {
public:
    /// @brief A Default Empty Constructor for the Graph
    Graph();

    /// @brief A Function used to get the Nodes Vector
    /// @return Returns the Vector of the Nodes
    vector<Node *> get_nodes_vector();
private:
    vector<Node *> nodes_vector_;
};


#endif //GRAPH_H
