//
// Created by stas on 10.12.2019.
//

#ifndef PG_COMMANDMANAGER_COMMANDINFO_H_
#define PG_COMMANDMANAGER_COMMANDINFO_H_

#include <string>
#include <vector>
#include <map>
#include <sstream>

struct Pattern{
    Pattern(const std::string& string){
        std::stringstream ss(string);
        std::string word;
        ss >> word;
        CommandName = word;
        while(ss >> word){
            word.erase(word.begin());
            word.erase(--word.end());
            Params.push_back(word);
        }
    }
    int NumberOfParams = 0;
    std::string CommandName;
    std::vector<std::string> Params;
};

struct CommandInfo{
    std::string Name;
    std::vector<std::string> Flags;
    std::map<std::string, std::string> Params;
};

#endif //PG_COMMANDMANAGER_COMMANDINFO_H_
