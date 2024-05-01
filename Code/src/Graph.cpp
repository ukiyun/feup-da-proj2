#include "../include/Graph.h"

// ============ Edge Functions ============== //

Edge::Edge(Node* origin, Node* destination, double distance) {
    this->edge_origin_ = origin;
    this->edge_destination_ = destination;
    this->edge_distance_ = distance;
}

Node* Edge::getEdgeOrigin() const {
    return this->edge_origin_;
}

Node* Edge::getEdgeDestination() const{
    return this->edge_destination_;
}

double Edge::getEdgeDistance() const{
    return this->edge_distance_;
}


// ============ Node Functions ============== //

Node::Node(int id, double node_longitude, double node_latitude){
    this->node_id_ = id;
    this->node_longitude_ = node_longitude;
    this->node_latitude_ = node_latitude;
}

int Node::getNodeId() const{
    return this->node_id_;
}

double Node::getNodeLongitude() const{
    return this->node_longitude_;
}

double Node::getNodeLatitude() const{
    return this->node_latitude_;
}

// ============ Graph Functions ============== //

vector<Node *> Graph::get_nodes_vector() {
    return this->nodes_vector_;
}
