#ifndef UTILS_H
#define UTILS_H

#include "Graph.h"

class Utils {
public:
    static float backtracking(Graph &graph);
    static float nearest_neighbor(Graph &graph);
    // Add the declarations here when you implement the functions
    static float triangular_approximation(Graph &graph); // Placeholder for future implementation
    static float tsp_real_world(Graph &graph);           // Placeholder for future implementation

private:
    static void backtrackingHelper(Graph &graph, std::vector<bool> &visited, int currentVertex, int startVertex, float pathLength, float &minPathLength);
};

#endif // UTILS_H
