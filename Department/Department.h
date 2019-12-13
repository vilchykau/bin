//
// Created by stas on 15.11.19.
//

#ifndef LABBINARY_DEPARTMENT_H
#define LABBINARY_DEPARTMENT_H

#include <cstring>
#include <iostream>
#include <string>

struct Department{
    int code;
    char name[50]{};

    Department(){
        code = 0;
        strcpy(name, "");
    }
};

std::ostream& operator<<(std::ostream& ostream, const Department& department);
std::istream& operator>>(std::istream& istream, Department& department);

#endif //LABBINARY_DEPARTMENT_H
