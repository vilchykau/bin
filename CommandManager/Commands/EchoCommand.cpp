//
// Created by stas on 11.12.2019.
//

#include <iostream>
#include "EchoCommand.h"

S_CMD_EXE(EchoCommand){
    std::cout << info.Params.at("info") << "\n";
}