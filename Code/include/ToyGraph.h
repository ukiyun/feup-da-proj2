#ifndef TOYGRAPH_H
#define TOYGRAPH_H

// C++ libraries
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/// @class ToyGraph
/// @brief A Class Dedicated to the Handling of ToyGraphs
class ToyGraph {
public:
    /// @brief A Constructor for the Toy Graph With Labels
    /// @param origin Integer with the Origin
    /// @param destination Integer with the Destination
    /// @param distance Integer with the Distance
    /// @param label_origin String with the Label of the Origin
    /// @param label_destination String with the Label of the Destination
    ToyGraph(int origin, int destination, double distance, string label_origin = "", string label_destination="");

    /// @brief A Default Empty Constructor for the Delivery Site
    ToyGraph()=default;

    /// @brief A Function used to get the Origin
    /// @return Returns the Integer of the Origin
    int getOrigin() const;

    /// @brief A Function used to get the Destination
    /// @return Returns the Integer of the Destination
    int getDestination() const;

    /// @brief A Function used to get the Distance
    /// @return Returns the Integer of the Distance
    double getDistance() const;

    /// @brief A Function used to get the Origin Label
    /// @return Returns the Integer of the Origin Label
    string getOriginLabel() const;

    /// @brief A Function used to get the Destination Label
    /// @return Returns the Integer of the Destination Label
    string getDestinationLabel() const;

private:
    /// @brief Toy Graph Origin Node
    int origin_;

    /// @brief Toy Graph Destination Node
    int destination_;

    /// @brief Toy Graph Distance between Origin Node and Destination Node
    double distance_;

    /// @brief Toy Graph Label of the Origin Node
    string label_origin_ = "";             // Automatically Assume that There is no Origin Label

    /// @brief Toy Graph Label of the Destination Node
    string label_destination_ = "";        // Automatically Assume that There is no Destination Label
};


#endif //TOYGRAPH_H
