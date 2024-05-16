#ifndef UTILS_H
#define UTILS_H

// C++ libraries
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

// Header Files
#include "Graph.h"

/// @class Utils
/// @brief A Class Dedicated to the Implementation of Auxiliary Functions
class Utils {

    static float backtracking(Graph &graph);
    float tsp(const Graph& graph);
    static std::vector<int> triangular_approximation(const Graph& graph);
    static void backtrackingHelper(Graph &graph, std::vector <bool> &visited,int currentVertex, int count, float pathLength, float &minPathLength );

};


#endif //UTILS_H
