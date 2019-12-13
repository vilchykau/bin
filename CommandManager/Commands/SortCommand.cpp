//
// Created by stas on 13.12.2019.
//

#include "SortCommand.h"
#include "../../Department/DepartmentSorter.h"
#include "../../Person/PersonSorter.h"

S_CMD_EXE(SortCommand){
    const std::string& type = info.Params.at("type");
    const std::string& file_name = info.Params.at("file");

    if(type == "d"){
        DepartmentSorter sorter(file_name);
        sorter.Sort();
    }else{
        PersonSorter sorter(file_name);
        sorter.Sort();
    }
}