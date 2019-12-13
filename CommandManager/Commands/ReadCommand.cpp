//
// Created by stas on 10.12.2019.
//

#include <iostream>
#include "ReadCommand.h"

#include "../../Person/Person.h"
#include "../../Department/Department.h"
#include "../../Person/Merged.h"

#include "../../BinToolsLib/BinaryReader.h"

template <typename T>
void Read(const std::string& file_name){
    std::vector<T> objects;
    BinaryReader<T> reader(file_name);
    reader.Read(objects);

    bool is_first = true;

    for(const auto& object : objects){
        if(!is_first){
            std::cout << std::endl;
        }
        is_first = false;
        std::cout << object;
    }
}

S_CMD_EXE(ReadCommand){
    const std::string& type = info.Params.at("type");
    const std::string& file_name = info.Params.at("file");

    if(type == "p"){
        Read<Person>(file_name);
    }else if(type == "d"){
        Read<Department>(file_name);
    }else{
        Read<Merged>(file_name);
    }
}
