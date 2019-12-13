//
// Created by stas on 14.11.19.
//

#ifndef LABBINARY_PERSON_H
#define LABBINARY_PERSON_H

#include <string>
#include <iostream>
#include <cstring>


struct Person{
    explicit Person();

    int id;
    char name[30];
    char position[20];
    char degree[20];
    int department_id;
};

std::ostream& operator<<(std::ostream& stream, const Person& person);
std::istream& operator>>(std::istream& stream, Person& person);


#endif //LABBINARY_PERSON_H
