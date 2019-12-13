//
// Created by stas on 19.11.2019.
//

#ifndef LABBINARY_PERSONSORTER_H
#define LABBINARY_PERSONSORTER_H

#include <fstream>
#include <string>

#include "Person.h"

class PersonSorter {
public:
    explicit PersonSorter(const std::string& file_name);
    ~PersonSorter();
    Person GetAt(int pos);
    void SetAt(const Person& person, int pos);
    void Sort();
    void Close();
    void Open();
    void Swap(int a_pos, int b_pos);
private:
    std::string file_name;
    std::fstream file;
    int array_size;
};


#endif //LABBINARY_PERSONSORTER_H
