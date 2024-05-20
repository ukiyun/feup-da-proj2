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

Edge *Node::add_edge_to_node(Edge *new_edge) {
    for (auto e: adjacent_edges_){
        if(e == new_edge){
            return nullptr;
        }
    }
    this->adjacent_edges_.push_back(new_edge);
    return new_edge;
}

Edge *Node::find_edge(const Node *node_destination) {
    for(auto edge: this->adjacent_edges_){
        if(edge->getEdgeDestination() == node_destination){
            return edge;
        }
    }

    return nullptr;
}

vector<Edge *> Node::get_adjacent_edges_vector() const {
    return this->adjacent_edges_;
}

double Node::haversine_formula(const Node *destination_node) const {
    // Earth Radius in Kilometers
    double earth_radius = 6371;

    // Coordinates in Decimal Degrees
    double latitude1 = this->getNodeLatitude();
    double latitude2 = destination_node->getNodeLatitude();
    double longitude1 = this->getNodeLongitude();
    double longitude2 = destination_node->getNodeLongitude();

    // Calculating the Latitude and Longitude Deltas in Radians
    double delta_lat = (latitude2-latitude1) * M_PI / 180.0;
    double delta_lon = (longitude2-longitude1) * M_PI / 180.0;

    // Converting the Latitudes into Radians
    double lat1_radian = latitude1 * M_PI / 180.0;
    double lat2_radian = latitude2 * M_PI / 180.0;

    // Calculating Variable a
    double a_left = pow(sin(delta_lat/2),2);
    double a_right = cos(lat1_radian) * cos(lat2_radian) * pow(sin(delta_lon/2),2);
    double a = a_left + a_right;

    // Calculating Variable c
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    // Calculating Final Distance
    double d = earth_radius * c;

    return d;
}



// ============ Graph Functions ============== //

bool Graph::add_node(Node *new_node) {
    if(find_node(new_node)!= nullptr){
        return false;
    }
    this->nodes_vector_.push_back(new_node);
    return true;
}

bool Graph::add_edge(Edge *new_edge) {
    auto origin_node = find_node(new_edge->getEdgeOrigin());
    auto destination_node = find_node(new_edge->getEdgeDestination());

    if(origin_node == nullptr || destination_node == nullptr){
        perror("Invalid Nodes");
        return false;
    }

    origin_node->add_edge_to_node(new_edge);
    return true;
}

Node *Graph::find_node(Node *node_to_find) {
    for (auto node: this->nodes_vector_){
        if(node->getNodeId() == node_to_find->getNodeId()){
            return node;
        }
    }
    return nullptr;
}


vector<Node *> Graph::get_nodes_vector() {
    return this->nodes_vector_;
}

void Graph::delete_graph() {
    this->nodes_vector_.clear();        // Removes all Items from the Nodes Vector, i.e., Deleting the Nodes in the Graph
}

Edge* Graph::find_edge(int i, int i1) {
    for (auto nodes: this->nodes_vector_){
        if(nodes->getNodeId()== i){
            for(auto edges: nodes->get_adjacent_edges_vector()){
                if(edges->getEdgeDestination()->getNodeId()==i1){
                    return edges;
                }
            }
        }
        if(nodes->getNodeId()== i1){
            for(auto edges: nodes->get_adjacent_edges_vector()){
                if(edges->getEdgeDestination()->getNodeId()==i){
                    return edges;
                }
            }
        }
    }

    return nullptr;
}

double Graph::triangularApproximationTSP(const vector<Node *> nodes) {
    int n = this->nodes_vector_.size();
    double totalDistance = 0.0;
    // Start with the first Node
    Node* currentNode = nodes_vector_[0];
    // Visit remaining nodes in the order of nearest neighbor
    for (int i = 1; i < n; ++i) {
        double minDistance = numeric_limits<double>::max();
        int nearestNodeIndex = -1;
        for (int j = 1; j < n; ++j) {
            if (i != j) {
                double dist = Node::haversine_formula(currentNode);
                if (dist < minDistance) {
                    minDistance = dist;
                    nearestNodeIndex = j;
                }}}
        totalDistance += minDistance;
        currentNode = this->nodes_vector_[nearestNodeIndex];
    }// Return to the starting Node
    totalDistance += Node::haversine_formula(currentNode);
    return totalDistance;
}