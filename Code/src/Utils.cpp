#include "../include/Utils.h"


float Utils::backtracking(Graph& graph) {
    vector<bool> visited(graph.get_nodes_vector().size(), false);
    float minPathLength = numeric_limits<float>::max();
    backtrackingHelper(graph, visited, 0, 0, 0.0, minPathLength);
    return minPathLength;
}

void Utils::backtrackingHelper(Graph &graph, vector<bool> &visited, int currentVertex, int startVertex, float pathLength, float &minPathLength) {
    visited[currentVertex] = true;

    bool allVisited = true;
    for (bool v : visited) {
        if (!v) {
            allVisited = false;
            break;
        }
    }

    if (allVisited) {
        minPathLength = min(minPathLength, pathLength + static_cast<float>(graph.find_edge(graph.get_nodes_vector()[currentVertex]->getNodeId(), graph.get_nodes_vector()[startVertex]->getNodeId())->getEdgeDistance()));
        visited[currentVertex] = false;
        return;
    }

    for (Edge *edge : graph.get_nodes_vector()[currentVertex]->get_adjacent_edges_vector()) {
        int nextVertex = edge->getEdgeDestination()->getNodeId();
        if (!visited[nextVertex]) {
            backtrackingHelper(graph, visited, nextVertex, startVertex, pathLength + static_cast<float>(edge->getEdgeDistance()), minPathLength);
        }
    }

    visited[currentVertex] = false;
}


float Utils::nearest_neighbor(Graph &graph) {
    vector<Node*> nodes = graph.get_nodes_vector();
    vector<bool> visited(nodes.size(), false);
    float totalDistance = 0.0;
    int currentNode = 0;
    visited[currentNode] = true;

    for (size_t i = 1; i < nodes.size(); ++i) {
        float nearestDistance = numeric_limits<float>::max();
        int nearestNode = -1;

        for (size_t j = 0; j < nodes.size(); ++j) {
            if (!visited[j]) {
                float distance = nodes[currentNode]->haversine_formula(nodes[j]);
                if (distance < nearestDistance) {
                    nearestDistance = distance;
                    nearestNode = j;
                }
            }
        }

        totalDistance += nearestDistance;
        currentNode = nearestNode;
        visited[currentNode] = true;
    }

    totalDistance += nodes[currentNode]->haversine_formula(nodes[0]);
    return totalDistance;
}


// Placeholder for TSP in the real world
float Utils::tsp_real_world(Graph &graph) {
    // Implement TSP in the real world algorithm here
    return 0.0;
}

vector<vector<float>> Utils::AdjacencyMatrix(Graph &graph) {
    int matrix_size = graph.get_nodes_vector().size();
    vector<vector<float>> matrix (matrix_size, vector<float>(matrix_size, 0));
    return matrix;
}
