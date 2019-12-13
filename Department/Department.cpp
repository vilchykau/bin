//
// Created by stas on 15.11.19.
//

#include "Department.h"

std::ostream& operator<<(std::ostream& ostream, const Department& department){
    std::cout << department.code << " " << department.name;
    return ostream;
}

std::istream& operator>>(std::istream& istream, Department& department){
    char code[5];
    istream.getline(code, sizeof(code), ',');
    department.code = std::atoi(code);

    std::string str_name;
    std::getline(istream, str_name);
    strcpy(department.name, str_name.c_str());

    return istream;
}