//
// Created by stas on 19.11.2019.
//

#ifndef LABBINARY_MERGED_H
#define LABBINARY_MERGED_H

#include <iostream>
#include <cstring>

#include "Person.h"

struct Merged{
    explicit Merged(){
        id = 0;
        strcpy(name, "");
        strcpy(position, "");
        stpcpy(degree, "");
        stpcpy(this->department_name, "");
    };
    Merged(const Person& person, char department_name[50]){
        id = person.id;
        strcpy(name, person.name);
        strcpy(position, person.position);
        stpcpy(degree, person.degree);
        stpcpy(this->department_name, department_name);
    };
    int id;
    char name[30];
    char position[20];
    char degree[20];
    char department_name[50];
};

std::ostream& operator<<(std::ostream& stream, const Merged& merged);

#endif //LABBINARY_MERGED_H
