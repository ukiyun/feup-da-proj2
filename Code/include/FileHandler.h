#ifndef FILEHANDLER_H
#define FILEHANDLER_H

// C++ Libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>

// Header Files
#include "ToyGraph.h"
#include "Graph.h"

using namespace std;

/// @class FileHandler
/// @brief A Class Dedicated to the Handling of the Files and Functions related to those
class FileHandler {
public:
    // ============ Toy Graph Functions ============== //
    vector<ToyGraph> get_toy_graph_vector();
    Graph get_toy_graph();

    void read_ToyGraph_csv(string fileName);
    void parse_ToyGraph_csv(string currentLine);

    // ============ Real World Graph Functions ============== //
    vector<MyNode> get_real_world_graph_vector();
    Graph get_real_world_graph();

    void read_RealWorld_csv(string NodeFilePath, string EdgeFilePath);

    void parse_RealWorld_Nodes_csv(string currentLine);
    void parse_RealWorld_Edges_csv(string currentLine);

    // ============ Extra Fully Connected Graph Functions ============== //
    vector<ToyGraph> get_fully_connected_graph_vector();
    Graph get_fully_connected_graph();

    void read_FullyConnected_csv(string filePath);
    void parse_FullyConnected_csv(string currentLine);

    // ============ Adding Nodes to Graph ========================= //

    void add_nodes_to_graph(Graph * graph);

private:
    /// @brief Vector with the Toy Graph Nodes
    vector<ToyGraph> toy_graph_nodes_;

    /// @brief Vector with the Real World Graph Nodes
    vector<MyNode> real_world_nodes_;

    /// @brief Vector with the Extra Fully Connected Graph Nodes
    vector<ToyGraph> fully_connected_nodes_;

    /// @brief Graph with the Toy Graph data
    Graph toy_graph_;

    /// @brief Graph with the Real World Graph data
    Graph real_world_graph_;

    /// @brief Graph with the Extra Fully Connected Graph data
    Graph fully_connected_graph_;
};

#endif //FILEHANDLER_H
