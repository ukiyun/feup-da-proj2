#ifndef INTERFACE_H
#define INTERFACE_H

// C++ libraries
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>

// Header Files
#include "FileHandler.h"


using namespace std;

/// @class Interface
/// @brief A Class Dedicated to the Program's Interface and User Interaction
class Interface {
public:
    /// @brief Main Function to Open the Program
    void open();

    ///@brief Function used to Display the Program's Main Menu
    bool displayMainMenu();

    int choose_graph_type();

    // ============ Backtracking Functions ============== //
    /// @brief Program Option to show a menu the Menu Related to Backtracking Functions
    void backtracking_algorithm();

    // ============ Triangular Approximation Functions ============== //
    /// @brief Program Option to show a menu the Menu Related to Backtracking Functions
    void triangular_approximation();

    // ============ Other Heuristics ============== //
    /// @brief Program Option to show a menu the Menu Related to Backtracking Functions
    void other_heuristics();

    // ============ TSP in Real World Functions ============== //
    /// @brief Program Option to show a menu the Menu Related to Backtracking Functions
    void tsp_in_real_world();

private:
    /// @brief Variable used to Implement File Handler System and its Functions
    FileHandler fhs_;
};


#endif //INTERFACE_H
