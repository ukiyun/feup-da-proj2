#include "../include/Utils.h"
#include "../include/Graph.h"
#include <vector>
#include <limits> // for numeric_limits
#include <algorithm>



std::vector<int> Utils::triangular_approximation(const Graph &graph) {
    std :: vector<int> empty;
    return empty;
}

float Utils::tsp(const Graph &graph) {
    return 0;
}


float Utils::backtracking(const Graph &graph) {
    int n = graph.get_nodes_vector().size(); // Get the number of nodes in the graph
    std:: vector<bool> visited(n, false);
    float minPathLength = std:: numeric_limits<float>::max(); // Initialize with max value
    backtrackingHelper(graph, visited, 0, 1, 0, minPathLength);
    //Use of undeclared identifier 'backtrackingHelper'backtrackingHelper(graph, visited, 0, 1, 0, minPathLength); // Start from vertex 0
    return minPathLength;
}

void Utils::backtrackingHelper(const Graph &graph, std::vector<bool> &visited, int currentVertex, int count,
                               float pathLength, float &minPathLength) {

}

void backtrackingHelper(const Graph &graph, std::vector<bool> &visited, int currentVertex, int count, float pathLength, double &minPathLength) {
    visited[currentVertex] = true;
    int totalNodes = graph.get_nodes_vector().size(); // Get the total number of nodes in the graph
    if (count == totalNodes && graph.find_edge(graph.get_nodes_vector()[currentVertex]->getNodeId(), graph.get_nodes_vector()[0]->getNodeId()) != nullptr) {
        minPathLength = std:: min(minPathLength, pathLength + graph.find_edge(graph.get_nodes_vector()[currentVertex]->getNodeId(), graph.get_nodes_vector()[0]->getNodeId())->getEdgeDistance());
    } else {
        for (auto edge : graph.get_nodes_vector()[currentVertex]->get_adjacent_edges_vector()) {
            Node *destination = edge->getEdgeDestination();
            int destinationId = destination->getNodeId();
            if (!visited[destinationId]) {
                float newPathLength= pathLength + edge->getEdgeDistance();
                minPathLength= std::min( static_cast <float>(minPathLength),   newPathLength);
                backtrackingHelper(graph, visited, destinationId, count + 1, pathLength + edge->getEdgeDistance(), minPathLength);
            }
        }
    }
    visited[currentVertex] = false;
}



