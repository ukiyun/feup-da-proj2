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
#include <iomanip>

// Header Files
#include "FileHandler.h"
#include "Utils.h"

using namespace std;

/// @class Interface
/// @brief A Class Dedicated to the Program's Interface and User Interaction
class Interface {
public:
    /// @brief Main Function to Open the Program
    void open();

    ///@brief Function used to Display the Program's Main Menu
    bool displayMainMenu();

    /// @brief Function used to Choose which Type of Graph to Work With
    int choose_graph_type();

    /// @brief Function used to Choose which Toy Graph CSV to Work With
    void choose_toy_graph(int mode);

    /// @brief Function used to Choose which Real World Graph CSV to Work With
    void choose_real_world_graph(int mode);

    /// @brief Function used to Choose which Fully Connected Graph CSV to Work With
    void choose_fully_connected_graph(int mode);

    /// @brief Function used to Show a Menu to Ask the User what to do with the Chosen Graph
    vector<int> show_selection_menu(int mode);

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

    // ============ Testing ============== //

    /// @brief Program Option to show the CSV of Toy Graph
    void show_selected_toy_csv();

    /// @brief Program Option to show the CSV of Real World
    void show_selected_real_world_csv();

    /// @brief Program Option to show the CSV of Fully Connected
    void show_selected_fully_connected_csv();

    /// @brief Program Option to show the Toy Graph
    void show_selected_toy_graph();

    /// @brief Program Option to show the Real World Graph
    void show_selected_real_world_graph();

    /// @brief Program Option to show the Fully Connected Graph
    void show_selected_fully_connected_graph();

private:
    /// @brief Variable used to Implement File Handler System and its Functions
    FileHandler fhs_;
};


#endif //INTERFACE_H
