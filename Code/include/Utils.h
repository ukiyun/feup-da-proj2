#ifndef UTILS_H
#define UTILS_H

// C++ libraries
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <limits>

// Header Files
#include "Graph.h"


using namespace std;

/// @class Utils
/// @brief A Class Dedicated to the Implementation of Auxiliary Functions
class Utils {
public:
    /// @brief Function Used to Solve the Backtracking Problem
    static float backtracking(Graph& graph);

    /// @brief Function Used to Find the Nearest Neighbour
    static float nearest_neighbor(Graph &graph);

    // Add the declarations here when you implement the functions

    /// @brief Function Used to Solve the Triangular Approximation Problem
    vector<vector<float>> AdjacencyMatrix (Graph &graph);

    /// @brief Function Used to Solve the Triangular Approximation Problem

    /// @brief Function Used to Solve the TSP in Real World Problem
    static float tsp_real_world(Graph &graph);           // Placeholder for future implementation

private:
    /// @brief Function Used to help the Backtracking function
    static void backtrackingHelper(Graph &graph, vector<bool> &visited, int currentVertex, int startVertex, float pathLength, float &minPathLength);
};


#endif //UTILS_H
