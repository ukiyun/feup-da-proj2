#include "../include/Interface.h"
#include "../include/Utils.h"
#include <iomanip>
#include <unistd.h>

using namespace std;

void Interface::open() {
    while (true) {
        if (!displayMainMenu()) {
            break;
        }
    }
}

bool Interface::displayMainMenu() {
    cout << '\n';
    usleep(800000); // sleep in microseconds
    cout << char(218) << string(4, char(196)) << " Travelling Salesman Problem " << string(3, char(196)) << char(191) << endl;
    cout << "|                                    |\n";
    cout << "|      1. Backtracking Algorithm     |\n";
    cout << "|        2. Other Heuristics         |\n";
    cout << "|              3. Exit               |\n";
    cout << "|       4. Show Toy Graph Data       |\n";
    cout << "|    5. Show Real World Graph Data   |\n";
    cout << "|  6. Show Fully Connected Graph Data|\n";
    cout << "|                                    |\n";
    cout << char(192) << string(36, char(196)) << char(217) << endl;
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "\n";

    try {
        switch (stoi(choice)) {
            case 1:
                this->backtracking_algorithm();
                break;
            case 2:
                this->other_heuristics();
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                return false;
            case 4:
                this->choose_toy_graph(1);
                break;
            case 5:
                this->choose_real_world_graph(2);
                break;
            case 6:
                this->choose_fully_connected_graph(3);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } catch (invalid_argument &choice) {
        cout << "Invalid Choice. Please try Again" << endl;
    }

    return true;
}

void Interface::backtracking_algorithm() {
    int mode = choose_graph_type();
    Graph selectedGraph;
    switch (mode) {
        case 1:
            choose_toy_graph(1);
            selectedGraph = fhs_.get_toy_graph();
            break;
        case 2:
            choose_real_world_graph(1);
            selectedGraph = fhs_.get_real_world_graph();
            break;
        case 3:
            choose_fully_connected_graph(1);
            selectedGraph = fhs_.get_fully_connected_graph();
            break;
        case 4:
            displayMainMenu();
            return;
        default:
            return;
    }

    cout << "Executing Backtracking Algorithm..." << endl;
    float result = Utils::backtracking(selectedGraph);
    cout << "The minimum path length found by the backtracking algorithm is: " << result << endl;
    cout << "Press any key to return to the main menu...";
    cin.ignore();
    cin.get();
}

int Interface::choose_graph_type() {
    usleep(650000); // sleep in microseconds
    cout << char(218) << string(5, char(196)) << " Choose Which Graph to Use " << string(4, char(196)) << char(191) << endl;
    cout << "|                                    |\n";
    cout << "|           1. Toy Graphs            |\n";
    cout << "|        2. Real-World Graphs        |\n";
    cout << "|   3. Extra Fully Connected Graphs  |\n";
    cout << "|            4. Go Back              |\n";
    cout << "|                                    |\n";
    cout << char(192) << string(36, char(196)) << char(217) << endl;
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "\n";

    try {
        switch (stoi(choice)) {
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 3;
            case 4:
                return 4;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } catch (invalid_argument &choice) {
        cout << "Invalid Choice. Please try Again" << endl;
    }

    return 0;
}

void Interface::choose_toy_graph(int mode) {
    usleep(650000); // sleep in microseconds
    cout << char(218) << string(4, char(196)) << " Choose the Toy Graph to Use " << string(3, char(196)) << char(191) << endl;
    cout << "|                                    |\n";
    cout << "|          1. Shipping Graph         |\n";
    cout << "|          2. Stadiums Graph         |\n";
    cout << "|          3. Tourism Graph          |\n";
    cout << "|             4. Go Back             |\n";
    cout << "|                                    |\n";
    cout << char(192) << string(36, char(196)) << char(217) << endl;
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "\n";

    try {
        switch (stoi(choice)) {
            case 1:
                fhs_.read_ToyGraph_csv("shipping.csv");
                show_selected_toy_csv();
                break;
            case 2:
                fhs_.read_ToyGraph_csv("stadiums.csv");
                show_selected_toy_csv();
                break;
            case 3:
                fhs_.read_ToyGraph_csv("tourism.csv");
                show_selected_toy_csv();
                break;
            case 4:
                switch (mode) {
                    case 1:
                        this->backtracking_algorithm();
                        break;
                    case 2:
                        this->other_heuristics();
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                choose_toy_graph(mode);
        }
    } catch (invalid_argument &choice) {
        cout << "Invalid Choice. Please try Again" << endl;
    }
}

void Interface::choose_real_world_graph(int mode) {
    usleep(650000); // sleep in microseconds
    cout << char(218) << string(4, char(196)) << " Choose the Real World Graph " << string(3, char(196)) << char(191) << endl;
    cout << "|                                    |\n";
    cout << "|             1. Graph 1             |\n";
    cout << "|             2. Graph 2             |\n";
    cout << "|             3. Graph 3             |\n";
    cout << "|             4. Go Back             |\n";
    cout << "|                                    |\n";
    cout << char(192) << string(36, char(196)) << char(217) << endl;
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "\n";

    try {
        switch (stoi(choice)) {
            case 1:
                fhs_.read_RealWorld_csv("../Code/datasets/Real-world-Graphs/graph1/nodes.csv", "../Code/datasets/Real-world-Graphs/graph1/edges.csv");
                show_selected_real_world_csv();
                break;
            case 2:
                fhs_.read_RealWorld_csv("../Code/datasets/Real-world-Graphs/graph2/nodes.csv", "../Code/datasets/Real-world-Graphs/graph2/edges.csv");
                show_selected_real_world_csv();
                break;
            case 3:
                fhs_.read_RealWorld_csv("../Code/datasets/Real-world-Graphs/graph3/nodes.csv", "../Code/datasets/Real-world-Graphs/graph3/edges.csv");
                show_selected_real_world_csv();
                break;
            case 4:
                switch (mode) {
                    case 1:
                        this->backtracking_algorithm();
                        break;
                    case 2:
                        this->other_heuristics();
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } catch (invalid_argument &choice) {
        cout << "Invalid Choice. Please try Again" << endl;
    }
}

void Interface::choose_fully_connected_graph(int mode) {
    usleep(650000); // sleep in microseconds
    cout << char(218) << string(3, char(196)) << " Choose the Extra Graph to Use " << string(2, char(196)) << char(191) << endl;
    cout << "|                                    |\n";
    cout << "|            1. 25 Nodes             |\n";
    cout << "|            2. 50 Nodes             |\n";
    cout << "|            3. 75 Nodes             |\n";
    cout << "|            4. 100 Nodes            |\n";
    cout << "|            5. 200 Nodes            |\n";
    cout << "|            6. 300 Nodes            |\n";
    cout << "|            7. 400 Nodes            |\n";
    cout << "|            8. 500 Nodes            |\n";
    cout << "|            9. 600 Nodes            |\n";
    cout << "|            10. 700 Nodes           |\n";
    cout << "|            11. 800 Nodes           |\n";
    cout << "|            12. 900 Nodes           |\n";
    cout << "|            13. Go Back             |\n";
    cout << "|                                    |\n";
    cout << char(192) << string(36, char(196)) << char(217) << endl;
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "\n";

    try {
        switch (stoi(choice)) {
            case 1:
                fhs_.read_FullyConnected_csv("edges_25.csv");
                show_selected_fully_connected_csv();
                break;
            case 2:
                fhs_.read_FullyConnected_csv("edges_50.csv");
                show_selected_fully_connected_csv();
                break;
            case 3:
                fhs_.read_FullyConnected_csv("edges_75.csv");
                show_selected_fully_connected_csv();
                break;
            case 4:
                fhs_.read_FullyConnected_csv("edges_100.csv");
                show_selected_fully_connected_csv();
                break;
            case 5:
                fhs_.read_FullyConnected_csv("edges_200.csv");
                show_selected_fully_connected_csv();
                break;
            case 6:
                fhs_.read_FullyConnected_csv("edges_300.csv");
                show_selected_fully_connected_csv();
                break;
            case 7:
                fhs_.read_FullyConnected_csv("edges_400.csv");
                show_selected_fully_connected_csv();
                break;
            case 8:
                fhs_.read_FullyConnected_csv("edges_500.csv");
                show_selected_fully_connected_csv();
                break;
            case 9:
                fhs_.read_FullyConnected_csv("edges_600.csv");
                show_selected_fully_connected_csv();
                break;
            case 10:
                fhs_.read_FullyConnected_csv("edges_700.csv");
                show_selected_fully_connected_csv();
                break;
            case 11:
                fhs_.read_FullyConnected_csv("edges_800.csv");
                show_selected_fully_connected_csv();
                break;
            case 12:
                fhs_.read_FullyConnected_csv("edges_900.csv");
                show_selected_fully_connected_csv();
                break;
            case 13:
                switch (mode) {
                    case 1:
                        this->backtracking_algorithm();
                        break;
                    case 2:
                        this->other_heuristics();
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } catch (invalid_argument &choice) {
        cout << "Invalid Choice. Please try Again" << endl;
    }
}

void Interface::other_heuristics() {
    int mode = choose_graph_type();
    Graph selectedGraph;
    switch (mode) {
        case 1:
            choose_toy_graph(1);
            selectedGraph = fhs_.get_toy_graph();
            break;
        case 2:
            choose_real_world_graph(1);
            selectedGraph = fhs_.get_real_world_graph();
            break;
        case 3:
            choose_fully_connected_graph(1);
            selectedGraph = fhs_.get_fully_connected_graph();
            break;
        case 4:
            displayMainMenu();
            return;
        default:
            return;
    }

    cout << "Executing Other Heuristics..." << endl;
    float result = Utils::nearest_neighbor(selectedGraph);
    cout << "The minimum path length found by the nearest neighbor heuristic is: " << result << endl;
    cout << "Press any key to return to the main menu...";
    cin.ignore();
    cin.get();
}

void Interface::show_selected_toy_csv() {
    cout << char(218)<< string(24, char(196)) << " Toy CSV " << string(23, char(196)) << char(191) << endl;
    cout << "|" << string(56, char(196)) << "|" << endl;
    cout << "| Origin | Dest. | Distance | Origin Label | Dest. Label |\n";
    cout << "|                                                        |\n";

    vector<ToyGraph> toyGraphs = this->fhs_.get_toy_graph_vector();

    for (auto toy: toyGraphs) {
        cout << "|  " << setw(4) << toy.getOrigin() << "  |  ";
        cout << setw(3) << toy.getDestination() << "  |  ";
        cout << setw(6) << toy.getDistance()<< "  |  ";
        cout << setw(10) << toy.getOriginLabel()<< "  |  ";
        cout << setw(9) << toy.getDestinationLabel() << "  |  " << endl;
    }

    cout << "|" << string(56, char(196)) << "|" << endl;
    cout << "|                      1. Main Menu                      |\n";
    cout << "|                 2. Graph Visualization                 |\n";
    cout << char(192) << string(56, char(196)) << char(217) << endl;
    cout << "Enter your choice" << endl;

    string choice;
    cin >> choice;
    cout << "\n";

    try {
        switch (stoi(choice)) {
            case 1:
                displayMainMenu();
                break;
            case 2:
                show_selected_toy_graph();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } catch (invalid_argument) {
        cout << "Invalid choice. Please try again." << endl;
    }
}

void Interface::show_selected_real_world_csv() {
    cout << char(218)<< string(6, char(196)) << " Real World CSV " << string(5, char(196)) << char(191) << endl;
    cout << "|" << string(27, char(196)) << "|" << endl;
    cout << "| Id | Longitude | Latitude |\n";
    cout << "|                           |\n";

    vector<MyNode> realWorldGraph = this->fhs_.get_real_world_graph_vector();

    for (auto real: realWorldGraph) {
        cout << "|  " << setw(4) << real.getNodeId() << "  |  ";
        cout << setw(3) << real.getNodeLongitude()   << "  |  ";
        cout << setw(5) << real.getNodeLatitude()    << "  |  " << endl;
    }
    cout << "|                           |\n";
    cout << "|" << string(27, char(196)) << "|" << endl;
    cout << "|       1. Main Menu        |\n";
    cout << "|   2. Graph Visualization  |\n";
    cout << char(192) << string(27, char(196)) << char(217) << endl;
    cout << "Enter your choice" << endl;

    string choice;
    cin >> choice;
    cout << "\n";

    try {
        switch (stoi(choice)) {
            case 1:
                displayMainMenu();
                break;
            case 2:
                show_selected_real_world_graph();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } catch (invalid_argument) {
        cout << "Invalid choice. Please try again." << endl;
    }
}

void Interface::show_selected_fully_connected_csv() {
    cout << char(218)<< string(3, char(196)) << " Fully Connected CSV " << string(3, char(196)) << char(191) << endl;
    cout << "|" << string(27, char(196)) << "|" << endl;
    cout << "| Origin | Dest. | Distance |\n";
    cout << "|                           |\n";

    vector<ToyGraph> fullyConnectedGraph = this->fhs_.get_fully_connected_graph_vector();

    for (auto extra: fullyConnectedGraph) {
        cout << "|  " << setw(4) << extra.getOrigin() << "  |  ";
        cout << setw(3) << extra.getDestination() << "  |  ";
        cout << setw(5) << extra.getDistance()<< "  |  " << endl;
    }
    cout << "|                           |\n";
    cout << "|" << string(27, char(196)) << "|" << endl;
    cout << "|       1. Main Menu        |\n";
    cout << "|   2. Graph Visualization  |\n";
    cout << char(192) << string(27, char(196)) << char(217) << endl;
    cout << "Enter your choice" << endl;

    string choice;
    cin >> choice;
    cout << "\n";

    try {
        switch (stoi(choice)) {
            case 1:
                displayMainMenu();
                break;
            case 2:
                show_selected_fully_connected_graph();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } catch (invalid_argument) {
        cout << "Invalid choice. Please try again." << endl;
    }
}

void Interface::show_selected_toy_graph() {
    cout << char(218)<< string(22, char(196)) << " Toy Graph " << string(22, char(196)) << char(191) << endl;
    cout << "|" << string(55, char(196)) << "|" << endl;
    cout << "|            NodeID ( Longitude , Latitude )            |\n";
    cout << "|" << string(55, char(196)) << "|" << endl;

    vector<MyNode *> all_nodes_Vector = this->fhs_.get_toy_graph().get_nodes_vector();
    for (int i = 0; i< all_nodes_Vector.size(); i++) {
        cout <<  "| "<< setw(20)<< "Node " << setw(5)<< all_nodes_Vector[i]->getNodeId() << " ( " << all_nodes_Vector[i]->getNodeLongitude() << " , " << all_nodes_Vector[i]->getNodeLatitude() << " )" << setw(21) <<" | ";
        cout << "\n";
    }

    cout << "|" << string(55, char(196)) << "|" << endl;
    cout << "| Number of Edges | Edges ( Origin , Dest. , Distance ) |\n";
    cout << "|" << string(55, char(196)) << "|" << endl;
    for (int j=0; j< all_nodes_Vector.size();j++) {
        vector<Edge *> edgeSet = all_nodes_Vector[j]->get_adjacent_edges_vector();

        cout <<  "| "<< setw(20)<< "Node " << setw(5)<< all_nodes_Vector[j]->getNodeId() << " ( " << all_nodes_Vector[j]->getNodeLongitude() << " , " << all_nodes_Vector[j]->getNodeLatitude() << " )" << setw(21) <<" | " << endl;
        cout << "|" << string(55, char(196)) << "|" << endl;

        if (edgeSet.size()== 0) {
            cout << "|              Node has no Outgoing Edges               |\n";
            cout << "|" << string(55, char(196)) << "|" << endl;
        }
        for (int k = 0; k< edgeSet.size();k++) {
            cout <<  "| "<< setw(19)<< "Edge " << k << setw(5)<< " ( " << edgeSet[k]->getEdgeOrigin()->getNodeId() << " , " << edgeSet[k]->getEdgeDestination()->getNodeId() << " , " << edgeSet[k]->getEdgeDistance() << " )" << setw(16) <<" | ";
            cout << "\n";
        }

        cout << "|" << string(55, char(196)) << "|" << endl;
    }
    cout << "|                                                       |\n";
    cout << "|                      1. Main Menu                     |\n";
    cout << char(192) << string(55, char(196)) << char(217) << endl;
    cout << "Enter your choice" << endl;

    string choice;
    cin >> choice;
    cout << "\n";

    try {
        switch (stoi(choice)) {
            case 1:
                displayMainMenu();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } catch (invalid_argument) {
        cout << "Invalid choice. Please try again." << endl;
    }
}

void Interface::show_selected_real_world_graph() {
    cout << char(218)<< string(18, char(196)) << " Real World Graph " << string(19, char(196)) << char(191) << endl;
    cout << "|" << string(55, char(196)) << "|" << endl;
    cout << "|            NodeID ( Longitude , Latitude )            |\n";
    cout << "|" << string(55, char(196)) << "|" << endl;

    vector<MyNode *> all_nodes_Vector = this->fhs_.get_real_world_graph().get_nodes_vector();
    for (int i = 0; i< all_nodes_Vector.size(); i++) {
        cout <<  "| "<< setw(20)<< "Node " << setw(5)<< all_nodes_Vector[i]->getNodeId() << " ( " << all_nodes_Vector[i]->getNodeLongitude() << " , " << all_nodes_Vector[i]->getNodeLatitude() << " )" << setw(21) <<" | ";
        cout << "\n";
    }

    cout << "|" << string(55, char(196)) << "|" << endl;
    cout << "| Number of Edges | Edges ( Origin , Dest. , Distance ) |\n";
    cout << "|" << string(55, char(196)) << "|" << endl;
    for (int j=0; j< all_nodes_Vector.size();j++) {
        vector<Edge *> edgeSet = all_nodes_Vector[j]->get_adjacent_edges_vector();

        cout <<  "| "<< setw(20)<< "Node " << setw(5)<< all_nodes_Vector[j]->getNodeId() << " ( " << all_nodes_Vector[j]->getNodeLongitude() << " , " << all_nodes_Vector[j]->getNodeLatitude() << " )" << setw(21) <<" | " << endl;
        cout << "|" << string(55, char(196)) << "|" << endl;

        if (edgeSet.size()== 0) {
            cout << "|              Node has no Outgoing Edges               |\n";
            cout << "|" << string(55, char(196)) << "|" << endl;
        }
        for (int k = 0; k< edgeSet.size();k++) {
            cout <<  "| "<< setw(19)<< "Edge " << k << setw(5)<< " ( " << edgeSet[k]->getEdgeOrigin()->getNodeId() << " , " << edgeSet[k]->getEdgeDestination()->getNodeId() << " , " << edgeSet[k]->getEdgeDistance() << " )" << setw(16) <<" | ";
            cout << "\n";
        }

        cout << "|" << string(55, char(196)) << "|" << endl;
    }
    cout << "|                                                       |\n";
    cout << "|                      1. Main Menu                     |\n";
    cout << char(192) << string(55, char(196)) << char(217) << endl;
    cout << "Enter your choice" << endl;

    string choice;
    cin >> choice;
    cout << "\n";

    try {
        switch (stoi(choice)) {
            case 1:
                displayMainMenu();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } catch (invalid_argument) {
        cout << "Invalid choice. Please try again." << endl;
    }
}

void Interface::show_selected_fully_connected_graph() {
    cout << char(218)<< string(20, char(196)) << " Fully Connected Graph " << string(21, char(196)) << char(191) << endl;
    cout << "|" << string(55, char(196)) << "|" << endl;
    cout << "|            NodeID ( Longitude , Latitude )            |\n";
    cout << "|" << string(55, char(196)) << "|" << endl;

    vector<MyNode *> all_nodes_Vector = this->fhs_.get_fully_connected_graph().get_nodes_vector();
    for (int i = 0; i< all_nodes_Vector.size(); i++) {
        cout <<  "| "<< setw(20)<< "Node " << setw(5)<< all_nodes_Vector[i]->getNodeId() << " ( " << all_nodes_Vector[i]->getNodeLongitude() << " , " << all_nodes_Vector[i]->getNodeLatitude() << " )" << setw(21) <<" | ";
        cout << "\n";
    }

    cout << "|" << string(55, char(196)) << "|" << endl;
    cout << "| Number of Edges | Edges ( Origin , Dest. , Distance ) |\n";
    cout << "|" << string(55, char(196)) << "|" << endl;
    for (int j=0; j< all_nodes_Vector.size();j++) {
        vector<Edge *> edgeSet = all_nodes_Vector[j]->get_adjacent_edges_vector();

        cout <<  "| "<< setw(20)<< "Node " << setw(5)<< all_nodes_Vector[j]->getNodeId() << " ( " << all_nodes_Vector[j]->getNodeLongitude() << " , " << all_nodes_Vector[j]->getNodeLatitude() << " )" << setw(21) <<" | " << endl;
        cout << "|" << string(55, char(196)) << "|" << endl;

        if (edgeSet.size()== 0) {
            cout << "|              Node has no Outgoing Edges               |\n";
            cout << "|" << string(55, char(196)) << "|" << endl;
        }
        for (int k = 0; k< edgeSet.size();k++) {
            cout <<  "| "<< setw(19)<< "Edge " << k << setw(5)<< " ( " << edgeSet[k]->getEdgeOrigin()->getNodeId() << " , " << edgeSet[k]->getEdgeDestination()->getNodeId() << " , " << edgeSet[k]->getEdgeDistance() << " )" << setw(16) <<" | ";
            cout << "\n";
        }

        cout << "|" << string(55, char(196)) << "|" << endl;
    }
    cout << "|                                                       |\n";
    cout << "|                      1. Main Menu                     |\n";
    cout << char(192) << string(55, char(196)) << char(217) << endl;
    cout << "Enter your choice" << endl;

    string choice;
    cin >> choice;
    cout << "\n";

    try {
        switch (stoi(choice)) {
            case 1:
                displayMainMenu();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } catch (invalid_argument) {
        cout << "Invalid choice. Please try again." << endl;
    }
}
