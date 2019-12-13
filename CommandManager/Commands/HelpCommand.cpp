//
// Created by stas on 10.12.2019.
//

#include <iostream>
#include "HelpCommand.h"

void HelpCommand::Execute(const CommandInfo &info) {
    std::cout << "HelpCommand\n";
}
Pattern* HelpCommand::GetPattern() {
    return &pattern;
}

HelpCommand::HelpCommand():pattern("help"){

}
