//
// Created by stas on 10.12.2019.
//

#ifndef PG_COMMANDMANAGER_COMMANDPARSER_H_
#define PG_COMMANDMANAGER_COMMANDPARSER_H_

#include <string>
#include <vector>
#include <map>


#include "CommandInfo.h"

struct RawCommand{
    std::string Name;
    std::vector<std::string> Flags;
    std::vector<std::string> Params;
};

class CommandParser {
public:
    bool IsHit(const Pattern& pattern);
    CommandInfo GetInfo(const Pattern& pattern);
    explicit CommandParser(const std::string& cmd);
private:
    RawCommand raw_command;
};

#endif //PG_COMMANDMANAGER_COMMANDPARSER_H_
