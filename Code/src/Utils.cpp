#include "../include/Utils.h"


  
// Triangular Approximation Heuristic for TSP
double triangularApproximationTSP(const std::vector<Node *> nodes_vector_) {
    int n = nodes_vector_.size();
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
        currentNode = nodes_vector_[nearestNodeIndex];
    }// Return to the starting Node
  totalDistance += Node::haversine_formula(currentNode);
return totalDistance;
}


float Utils::tsp(const Graph &graph) {
    return 0;
}

float Utils::backtracking() {
    return 0;
}

