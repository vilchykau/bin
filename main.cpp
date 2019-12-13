#include <iostream>
#include <vector>
//13 13
#include "CommandManager/CommandController.h"

int main(){
    std::string line;
    CommandController command_controller;
    while(std::getline(std::cin, line)){
        command_controller.Execute(line);
    }
    return 0;
}