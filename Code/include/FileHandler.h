#ifndef FILEHANDLER_H
#define FILEHANDLER_H

// C++ Libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

// Header Files
#include "Interface.h"
#include "ToyGraph.h"

using namespace std;


/// @class FileHandler
/// @brief A Class Dedicated to the Handling of the Files and Functions related to those
class FileHandler {
public:

    // ============ Toy Graph Functions ============== //
    /// @brief Function used to Choose which Toy Graph to Work With
    void choose_toy_graph(int mode);
    vector<ToyGraph> get_toy_graph_vector();

    void read_ToyGraph_csv(string filePath);
    void parse_ToyGraph_csv(string currentLine);


    // ============ Real World Graph Functions ============== //
    /// @brief Function used to Choose which Real World Graph to Work With
    void choose_real_world_graph(int mode);
    vector<int> get_real_world_graph_vector();

    void read_RealWorld_csv(string NodeFilePath, string EdgeFilePath);
    void parse_RealWorld_csv(string currentLine);

    // ============ Extra Fully Connected Graph Functions ============== //
    /// @brief Function used to Choose which Fully Connected Graph to Work With
    void choose_fully_connected_graph(int mode);
    vector<ToyGraph> get_fully_connected_graph_vector();

    void read_FullyConnected_csv(string filePath);
    void parse_FullyConnected_csv(string currentLine);

private:
    /// @brief Vector with the Toy Graph Nodes
    vector<ToyGraph> toy_graph_;

    /// @brief Vector with the Real World Graph Nodes
    vector<int> real_world_; // still dont know datatype inside vector

    /// @brief Vector with the Extra Fully Connected Graph Nodes
    vector<ToyGraph> fully_connected_;
};


#endif //FILEHANDLER_H
