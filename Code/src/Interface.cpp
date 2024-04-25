#include "../include/Interface.h"

void Interface::open() {
    while(true){
        if(!displayMainMenu()){
            break;
        }
    }
}

bool Interface::displayMainMenu() {
    return false;
}
