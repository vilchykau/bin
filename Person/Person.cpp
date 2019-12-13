//
// Created by stas on 14.11.19.
//

#include "Person.h"

Person::Person() {
    id = 0;
    strcpy(name, "");
    strcpy(position, "");
    strcpy(degree, "");
    department_id = 0;
}


std::ostream& operator<<(std::ostream& stream, const Person& person){
    stream << person.id << ","
           << person.name << ","
           << person.position << ","
           << person.degree << ","
           << person.department_id;
    return stream;
}

std::istream& operator>>(std::istream& stream, Person& person){
    person = Person();
    char id[20], department_code[5];

    stream.getline(id, sizeof(id), ',');
    stream.getline(person.name, sizeof(person.name), ',');
    stream.getline(person.position, sizeof(person.position), ',');
    stream.getline(person.degree, sizeof(person.degree), ',');
    stream >> department_code;

    person.id = std::atoi(id);
    person.department_id = std::atoi(department_code);
    return stream;
};


/*person = Person();
    char add[10];
    stream >> person.id >> person.name >> add >> person.position >> person.degree >> person.department_id;
    strcat(person.name, " ");
    strcat(person.name, add);
    return stream;*/