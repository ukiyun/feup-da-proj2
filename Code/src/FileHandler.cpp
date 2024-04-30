#include "../include/FileHandler.h"

void FileHandler::choose_toy_graph(int mode) {
    usleep(650000);     // sleep in microseconds
    cout << char(218)<< string(4, char(196)) << " Choose the Toy Graph to Use " << string(3, char(196)) << char(191) << endl;
    cout << "|                                    |\n";
    cout << "|          1. Shipping Graph         |\n";
    cout << "|          2. Stadiums Graph         |\n";
    cout << "|          3. Tourism Graph          |\n";
    cout << "|             4. Go Back             |\n";
    cout << "|                                    |\n";
    cout << char(192) << string(36, char(196)) << char(217) << endl;
    string choice;
    cout<<"Enter your choice: ";
    cin >> choice;

    cout << "\n";

    // Display the menu based on the prompt from the user

    try{
        switch (stoi(choice)) {
            case 1:
                // shipping csv
                break;
            case 2:
                // stadiums csv
                break;
            case 3:
                // tourism csv
                break;
            case 4:
                Interface a;
                switch(mode){
                    case 1:
                        a.backtracking_algorithm();
                        break;
                    case 2:
                        a.triangular_approximation();
                        break;
                    case 3:
                        a.other_heuristics();
                        break;
                    case 4:
                        a.tsp_in_real_world();
                        break;
                    default:
                        break;
                }
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    catch (invalid_argument &choice){
        cout << "Invalid Choice. Please try Again" << endl;
    }
}

void FileHandler::choose_real_world_graph(int mode) {
    usleep(650000);     // sleep in microseconds
    cout << char(218)<< string(4, char(196)) << " Choose the Real World Graph " << string(3, char(196)) << char(191) << endl;
    cout << "|                                    |\n";
    cout << "|             1. Graph 1             |\n";
    cout << "|             2. Graph 2             |\n";
    cout << "|             3. Graph 3             |\n";
    cout << "|             4. Go Back             |\n";
    cout << "|                                    |\n";
    cout << char(192) << string(36, char(196)) << char(217) << endl;
    string choice;
    cout<<"Enter your choice: ";
    cin >> choice;

    cout << "\n";

    // Display the menu based on the prompt from the user

    try{
        switch (stoi(choice)) {
            case 1:
                // graph 1
                break;
            case 2:
                // graph 2
                break;
            case 3:
                // graph 3
                break;
            case 4:
                Interface a;
                switch(mode){
                    case 1:
                        a.backtracking_algorithm();
                        break;
                    case 2:
                        a.triangular_approximation();
                        break;
                    case 3:
                        a.other_heuristics();
                        break;
                    case 4:
                        a.tsp_in_real_world();
                        break;
                    default:
                        break;
                }
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    catch (invalid_argument &choice){
        cout << "Invalid Choice. Please try Again" << endl;
    }
}

void FileHandler::choose_fully_connected_graph(int mode) {
    usleep(650000);     // sleep in microseconds
    cout << char(218)<< string(3, char(196)) << " Choose the Extra Graph to Use " << string(2, char(196)) << char(191) << endl;
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
    cout<<"Enter your choice: ";
    cin >> choice;

    cout << "\n";

    // Display the menu based on the prompt from the user

    try{
        switch (stoi(choice)) {
            case 1:
                // 25 nodes
                break;
            case 2:
                // 50 nodes
                break;
            case 3:
                // 75 nodes
                break;
            case 4:
                // 100 nodes
                break;
            case 5:
                // 200 nodes
                break;
            case 6:
                // 300 nodes
                break;
            case 7:
                // 400 nodes
                break;
            case 8:
                // 500 nodes
                break;
            case 9:
                // 600 nodes
                break;
            case 10:
                // 700 nodes
                break;
            case 11:
                // 800 nodes
                break;
            case 12:
                // 900 nodes
                break;
            case 13:
                Interface a;
                switch(mode){
                    case 1:
                        a.backtracking_algorithm();
                        break;
                    case 2:
                        a.triangular_approximation();
                        break;
                    case 3:
                        a.other_heuristics();
                        break;
                    case 4:
                        a.tsp_in_real_world();
                        break;
                    default:
                        break;
                }
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    catch (invalid_argument &choice){
        cout << "Invalid Choice. Please try Again" << endl;
    }
}
