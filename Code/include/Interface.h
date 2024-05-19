#ifndef INTERFACE_H
#define INTERFACE_H

#include "FileHandler.h"
#include "Graph.h"
#include <iostream>
#include <vector>

using namespace std;

class Interface {
public:
    void open();
    bool displayMainMenu();
    void backtracking_algorithm();
    void other_heuristics();
    void show_selected_toy_csv();
    void show_selected_real_world_csv();
    void show_selected_fully_connected_csv();
    void show_selected_toy_graph();
    void show_selected_real_world_graph();
    void show_selected_fully_connected_graph();

private:
    int choose_graph_type();
    void choose_toy_graph(int mode);
    void choose_real_world_graph(int mode);
    void choose_fully_connected_graph(int mode);
    FileHandler fhs_;
};

#endif // INTERFACE_H
