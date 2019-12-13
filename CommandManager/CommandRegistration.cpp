//
// Created by stas on 10.12.2019.
//

#define REG_CMD(NAME) cmds.push_back(std::shared_ptr<ICommand>{new NAME})

#include "CommandRegistration.h"
#include "Commands/HelpCommand.h"
#include "Commands/ReadCommand.h"
#include "Commands/ConvertCommand.h"
#include "Commands/SortCommand.h"

void CommandRegistration::Register(std::vector<std::shared_ptr<ICommand>> &cmds) {
    REG_CMD(HelpCommand);
    REG_CMD(ReadCommand);
    REG_CMD(ConvertCommand);
    REG_CMD(SortCommand);
}
