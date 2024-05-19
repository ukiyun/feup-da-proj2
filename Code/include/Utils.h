#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits> // for numeric_limits

#include "Graph.h"

using namespace std;

/// @class Utils
/// @brief A Class Dedicated to the Implementation of Auxiliary Functions
class Utils {
public:
    static float backtracking(Graph &graph);
    float tsp(const Graph& graph);
    static vector<int> triangular_approximation(const Graph& graph);
    static void backtrackingHelper(Graph &graph, vector<bool> &visited, int currentVertex, int count, float pathLength, float &minPathLength);
};

#endif //UTILS_H
