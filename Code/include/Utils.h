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
    // Not sure about Parameters
    float backtracking();

    float tsp(const Graph& graph);

    // Not sure about Function
    vector<int> triangular_approximation(const Graph& graph);
};


#endif //UTILS_H
