//
// Created by stas on 10.12.2019.
//

#include <iostream>
#include "CommandController.h"

CommandController::CommandController() {
    CommandRegistration::Register(cmds);
}

void CommandController::Execute(const std::string &string) {
    CommandParser parser(string);
    for(auto& cmd : cmds){
        if(parser.IsHit(*cmd->GetPattern())){
            cmd->Execute(parser.GetInfo(*cmd->GetPattern()));
            return;
        }
    }
    std::cerr << "Command not found \n";
}
