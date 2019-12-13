//
// Created by stas on 18.11.19.
//

#ifndef LABBINARY_DEPARTMENTSORTER_H
#define LABBINARY_DEPARTMENTSORTER_H

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Department.h"

class DepartmentSorter {
public:
    explicit DepartmentSorter(const std::string& new_file_name);
    void Sort();
private:
    void GetDepartments(const std::string& file_name, std::vector<Department>& deps);
    void SortDepartments(std::vector<Department> &deps);
    void WriteDepartments(const std::string& file_name, const std::vector<Department>& deps);
    std::string file_name;
};


#endif //LABBINARY_DEPARTMENTSORTER_H
