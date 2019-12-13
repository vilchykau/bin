//
// Created by stas on 21.11.2019.
//

#include "Merged.h"

std::ostream& operator<<(std::ostream& stream, const Merged& merged){
    std::cout << merged.id << " " << merged.name << " "
              << merged.position << " " << merged.degree << " "
              << merged.department_name;
}