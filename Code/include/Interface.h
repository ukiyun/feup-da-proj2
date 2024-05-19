#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>
#include <string>
#include "FileHandler.h"

using namespace std;

class Interface {
public:
    void open();
    bool displayMainMenu();
    int choose_graph_type();
    void choose_toy_graph(int mode);
    void choose_real_world_graph(int mode);
    void choose_fully_connected_graph(int mode);

    // Backtracking function
    void backtracking_algorithm();

    // Other functions
    void triangular_approximation();
    void other_heuristics();
    void tsp_in_real_world();

    // Testing functions
    void show_selected_toy_csv();
    void show_selected_real_world_csv();
    void show_selected_fully_connected_csv();
    void show_selected_toy_graph();
    void show_selected_real_world_graph();
    void show_selected_fully_connected_graph();

private:
    FileHandler fhs_; // Declare the FileHandler object
};

#endif // INTERFACE_H
