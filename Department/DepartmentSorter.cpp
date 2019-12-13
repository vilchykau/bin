//
// Created by stas on 18.11.19.
//

#include "DepartmentSorter.h"
#include "../BinToolsLib/BinaryReader.h"
#include "../BinToolsLib/BinaryWriter.h"

DepartmentSorter::DepartmentSorter(const std::string &new_file_name): file_name(new_file_name) {

}

void DepartmentSorter::Sort() {
    std::vector<Department> deps;
    GetDepartments(file_name, deps);
    SortDepartments(deps);
    WriteDepartments(file_name, deps);
}

void DepartmentSorter::GetDepartments(const std::string& file_name, std::vector<Department>& deps){
    BinaryReader<Department> reader(file_name);
    reader.Read(deps);
    reader.Close();
}

void DepartmentSorter::SortDepartments(std::vector<Department> &deps) {
    std::sort(begin(deps), end(deps), [](const Department & a, const Department & b) -> bool{
        return a.code < b.code;
    });
}

void DepartmentSorter::WriteDepartments(const std::string& file_name, const std::vector<Department>& deps){
    BinaryWriter<Department> writer(file_name);
    writer.Write(deps);
    writer.Close();
}
