//
// Created by stas on 10.12.2019.
//

#ifndef PG_COMMANDMANAGER_HELPCOMMAND_H_
#define PG_COMMANDMANAGER_HELPCOMMAND_H_

#include "../ICommand.h"

class HelpCommand :public ICommand{
public:
    HelpCommand();
    void Execute(const CommandInfo& info) override;
    Pattern* GetPattern() override;
private:
    Pattern pattern;
};

#endif //PG_COMMANDMANAGER_HELPCOMMAND_H_
