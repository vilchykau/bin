//
// Created by stas on 19.11.2019.
//

#include "PersonSorter.h"

PersonSorter::PersonSorter(const std::string &file_name): file_name(file_name) {

}

PersonSorter::~PersonSorter() {
    Close();
}

Person PersonSorter::GetAt(int pos) {
    Person person;
    file.seekg(pos * sizeof(Person), std::ios::basic_ios::beg);
    file.read((char*)&person, sizeof(person));
    return person;
}

void PersonSorter::SetAt(const Person &person, int pos) {
    file.seekg(pos * sizeof(Person), std::ios::basic_ios::beg);
    file.write((char*)&person, sizeof(person));
}

void PersonSorter::Close() {
    file.close();
}

void PersonSorter::Open() {
    file = std::fstream(file_name, std::ios::in | std::ios::out | std::ios::binary);
    file.seekg(0, std::ios::basic_ios::end);
    array_size = file.tellg()/ sizeof(Person);
}

void PersonSorter::Sort() {
    Open();

    for (int i = 0; i < array_size-1; i++)
        for (int j = 0; j < array_size-i-1; j++)
            if (GetAt(j).department_id > GetAt(j+1).department_id)
                Swap(j, j+1);

    Close();
}

void PersonSorter::Swap(int a_pos, int b_pos) {
    Person person_a = GetAt(a_pos);
    Person person_b = GetAt(b_pos);

    SetAt(person_b, a_pos);
    SetAt(person_a, b_pos);
}
