//
// Created by stas on 10.12.2019.
//

#include "CommandParser.h"

#include <sstream>

CommandParser::CommandParser(const std::string &cmd) {
    raw_command = {};
    std::stringstream ss(cmd);
    std::string word;
    ss >> word;
    raw_command.Name = word;
    while(ss >> word){
        if(word[0] == '-'){
            raw_command.Flags.push_back(word);
        }else{
            raw_command.Params.push_back(word);
        }
    }
}

bool CommandParser::IsHit(const Pattern &pattern) {
    return pattern.CommandName == raw_command.Name && pattern.Params.size() == raw_command.Params.size();
}

CommandInfo CommandParser::GetInfo(const Pattern &pattern) {
    CommandInfo info;
    info.Name = raw_command.Name;
    info.Flags = raw_command.Flags;
    for(int i = 0; i < pattern.Params.size(); ++i){
        info.Params[pattern.Params[i]] = raw_command.Params[i];
    }
    return info;
}
