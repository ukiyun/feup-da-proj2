#ifndef GRAPH_H
#define GRAPH_H

// C++ Libraries
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

// Header Files

/// @class Node
/// @brief A Class Dedicated to the Handling of Nodes, that will Belong to a Graph


class Edge;

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
    Node() = default;

    /// @brief A Function used to get the Id of the Node
    /// @return Returns the Integer of the Node ID
    int getNodeId() const;

    /// @brief A Function used to get the Longitude of the Node
    /// @return Returns the Double of the Node Longitude
    double getNodeLongitude() const;

    /// @brief A Function used to get the Latitude of the Node
    /// @return Returns the Double of the Node Latitude
    double getNodeLatitude() const;

    /// @brief A Function used to add an Edge to the Node
    /// @return Returns the Edge that was Added to the Node
    Edge* add_edge_to_node(Edge * new_edge);

    /// @brief A Function used to get the Outgoing Edge of the Node
    /// @return Returns the Edge that Connects to Destination Node if found, Returns nullptr Otherwise
    Edge* find_edge(const Node * node_destination);

    /// @brief A Function used to get the Outgoing Edge of the Node
    /// @return Returns the Edge that Connects to Destination Node if found, Returns nullptr Otherwise
    std::vector<Edge *> get_adjacent_edges_vector() const;

    /// @brief A Function used to Calculate the Distance between Two Points
    /// @return Returns the double Value of the Distance between Nodes
    double haversine_formula(const Node* destination_node) const;

private:
    /// @brief Integer with the Id of the Node
    int node_id_{};

    /// @brief Double with the Node Distance ?
    double node_distance_{};

    /// @brief Double with the Node's Longitude
    double node_longitude_{};

    /// @brief Double with the Node's Latitude
    double node_latitude_{};

    /// @brief Vector with all the Edges connected to a Node
    std::vector<Edge *> adjacent_edges_;
};


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
    Edge()=default;

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
    /// @brief Node with the Edge Origin, i.e., where the Edge starts
    Node* edge_origin_;

    /// @brief Node with the Edge Destination, i.e., where the Edge ends
    Node* edge_destination_;

    /// @brief Integer with the Distance of the Edge, i.e., its Size
    double edge_distance_;
};



/// @class Graph
/// @brief A Class Dedicated to the Handling of Graphs
class Graph {
public:
    /// @brief A Default Empty Constructor for the Graph
    Graph()=default;

    /// @brief A Function used to add Nodes to the Graph
    /// @return Returns True if Node was Successfully added, False Otherwise
    bool add_node(Node * new_node);

    /// @brief A Function used to add Edges to the Graph
    /// @return Returns True if Edge was Successfully added, False Otherwise
    bool add_edge(Edge * new_edge);

    /// @brief A Function used to find Nodes in the Graph
    /// @return Returns Node if Node was Successfully found, Nullptr Otherwise
    Node* find_node(Node * node);

    /// @brief A Function used to get the Nodes Vector
    /// @return Returns the Vector of the Nodes
    std::vector<Node *> get_nodes_vector();

    /// @brief A Function used to Delete the Current Graph
    void delete_graph();
    std::vector<Node *> get_nodes_vector() const;

    Edge* find_edge(int originNodeId, int destinationNodeId) const;

private:
    /// @brief Vector with the All the Nodes in a Graph
    std::vector<Node *> nodes_vector_;
};










#endif //GRAPH_H