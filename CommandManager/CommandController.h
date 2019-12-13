//
// Created by stas on 10.12.2019.
//

#ifndef PG_COMMANDMANAGER_COMMANDCONTROLLER_H_
#define PG_COMMANDMANAGER_COMMANDCONTROLLER_H_

#include "ICommand.h"
#include "CommandRegistration.h"
#include "CommandParser.h"
#include <string>

class CommandController {
public:
    CommandController();
    void Execute(const std::string& string);
private:
    std::vector<std::shared_ptr<ICommand>> cmds;
};

#endif //PG_COMMANDMANAGER_COMMANDCONTROLLER_H_
