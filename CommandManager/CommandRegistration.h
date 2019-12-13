//
// Created by stas on 10.12.2019.
//

#ifndef PG_COMMANDMANAGER_COMMANDREGISTRATION_H_
#define PG_COMMANDMANAGER_COMMANDREGISTRATION_H_

#include "ICommand.h"
#include <memory>
#include <vector>

class CommandRegistration {
public:
    static void Register(std::vector<std::shared_ptr<ICommand>>& cmds);
};

#endif //PG_COMMANDMANAGER_COMMANDREGISTRATION_H_
