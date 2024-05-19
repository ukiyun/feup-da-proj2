#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <cmath>

using namespace std;

class MyNode;
class Edge;

class Graph {
public:
    bool add_node(MyNode *new_node);
    bool add_edge(Edge *new_edge);
    MyNode *find_node(MyNode *node_to_find);
    Edge *find_edge(int originNodeId, int destinationNodeId) const;
    vector<MyNode *> get_nodes_vector() const; // Add const here
    void delete_graph();
private:
    vector<MyNode *> nodes_vector_;
};

class MyNode {
public:
    MyNode(int id, double node_longitude, double node_latitude);
    int getNodeId() const;
    double getNodeLongitude() const;
    double getNodeLatitude() const;
    Edge *add_edge_to_node(Edge *new_edge);
    Edge *find_edge(const MyNode *node_destination);
    vector<Edge *> get_adjacent_edges_vector() const;
    double haversine_formula(const MyNode *destination_node) const;
private:
    int node_id_;
    double node_longitude_;
    double node_latitude_;
    vector<Edge *> adjacent_edges_;
};

class Edge {
public:
    Edge(MyNode* origin, MyNode* destination, double distance);
    MyNode* getEdgeOrigin() const;
    MyNode* getEdgeDestination() const;
    double getEdgeDistance() const;
private:
    MyNode* edge_origin_;
    MyNode* edge_destination_;
    double edge_distance_;
};

#endif // GRAPH_H
