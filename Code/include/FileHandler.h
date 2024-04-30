#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <vector>
#include "Interface.h"
using namespace std;


/// @class FileHandler
/// @brief A Class Dedicated to the Handling of the Files and Functions related to those
class FileHandler {
public:

    // ============ Toy Graph Functions ============== //
    /// @brief Function used to Choose which Toy Graph to Work With
    void choose_toy_graph(int mode);

    // ============ Real World Graph Functions ============== //
    /// @brief Function used to Choose which Real World Graph to Work With
    void choose_real_world_graph(int mode);

    // ============ Extra Fully Connected Graph Functions ============== //
    /// @brief Function used to Choose which Fully Connected Graph to Work With
    void choose_fully_connected_graph(int mode);

private:
    /// @brief Vector with the Toy Graph Nodes
    vector<int> toys_;
    /// @brief Vector with the Real World Graph Nodes
    vector<int> real_world_;
    /// @brief Vector with the Extra Fully Connected Graph Nodes
    vector<int> fully_connected_;
};


#endif //FILEHANDLER_H
