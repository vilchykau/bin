//
// Created by stas on 11.12.2019.
//

#include <algorithm>

#include "ConvertCommand.h"
#include "../../BinToolsLib/BinaryWriter.h"
#include "../../Department/Department.h"
#include "../../Person/Person.h"

void ReplaceFileName(std::string& file_name, const std::string& target){
    file_name.erase(file_name.begin() + file_name.find_last_of('.'), file_name.end());
    file_name += "." + target;
}

template<typename T>
void Convert(const std::string &in_file_name,
                             const std::string &out_file_name) {
    std::ifstream ifstream(in_file_name);
    T object;
    BinaryWriter<T> writer(out_file_name);

    while(ifstream >> object) {
        writer.Write(object);
    }
}

void TxtToBin(const CommandInfo& info){
    const char& type = info.Params.at("type")[1];
    const std::string& in_file_name = info.Params.at("file");
    std::string out_file_name = info.Params.at("file");

    ReplaceFileName(out_file_name, "bin");

    if(type == 'd'){
        Convert<Department>(in_file_name, out_file_name);
    }else{
        Convert<Person>(in_file_name, out_file_name);
    }
}

S_CMD_EXE(ConvertCommand){
    if(info.Params.at("type")[0] == 'b'){
        TxtToBin(info);
    }else if(info.Params.at("type")[0] == 't'){
      //  BinToTxt(info);
    }
}
