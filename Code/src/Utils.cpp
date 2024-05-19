#include "../include/Utils.h"
#include "../include/Graph.h"
#include <algorithm>

using namespace std;

vector<int> Utils::triangular_approximation(const Graph &graph) {
    vector<int> empty;
    // Implement the triangular approximation heuristic
    // Ensure the graph is fully connected using Haversine distance if needed
    // ...
    return empty;
}

float Utils::tsp(const Graph &graph) {
    // Implement another heuristic for TSP
    return 0;
}

float Utils::backtracking(Graph &graph) {
    int n = graph.get_nodes_vector().size(); // Get the number of nodes in the graph
    vector<bool> visited(n, false);
    float minPathLength = numeric_limits<float>::max(); // Initialize with max value
    backtrackingHelper(graph, visited, 0, 1, 0, minPathLength); // Start from vertex 0
    return minPathLength;
}

void Utils::backtrackingHelper(Graph &graph, vector<bool> &visited, int currentVertex, int count, float pathLength, float &minPathLength) {
    visited[currentVertex] = true;
    int totalNodes = graph.get_nodes_vector().size(); // Get the total number of nodes in the graph
    if (count == totalNodes && graph.find_edge(graph.get_nodes_vector()[currentVertex]->getNodeId(), graph.get_nodes_vector()[0]->getNodeId()) != nullptr) {
        minPathLength = min(minPathLength, static_cast<float>(pathLength + graph.find_edge(graph.get_nodes_vector()[currentVertex]->getNodeId(), graph.get_nodes_vector()[0]->getNodeId())->getEdgeDistance()));
    } else {
        for (auto edge : graph.get_nodes_vector()[currentVertex]->get_adjacent_edges_vector()) {
            MyNode *destination = edge->getEdgeDestination();
            int destinationId = destination->getNodeId();
            if (!visited[destinationId]) {
                float newPathLength = pathLength + edge->getEdgeDistance();
                backtrackingHelper(graph, visited, destinationId, count + 1, newPathLength, minPathLength);
            }
        }
    }
    visited[currentVertex] = false;
}
