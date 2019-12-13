//
// Created by stas on 10.12.2019.
//

#ifndef PG_COMMANDMANAGER_ICOMMAND_H_
#define PG_COMMANDMANAGER_ICOMMAND_H_

#include "CommandInfo.h"

class ICommand{
public:
    virtual void Execute(const CommandInfo& info){};
    virtual Pattern* GetPattern(){ return nullptr;};
};

#define S_CMD_CLASS(NAME, PATTERN) class NAME :public ICommand{\
public:\
NAME();\
void Execute(const CommandInfo& info) override;\
Pattern* GetPattern() override;\
private:\
Pattern pattern{PATTERN};\
};

#define S_CMD_EXE(Name) Name::Name(){}\
Pattern *Name::GetPattern() {\
    return &pattern;\
}\
void Name::Execute(const CommandInfo &info)


#endif //PG_COMMANDMANAGER_ICOMMAND_H_
