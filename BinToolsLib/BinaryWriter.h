//
// Created by stas on 15.11.19.
//

#ifndef LABBINARY_BINARYWRITER_H
#define LABBINARY_BINARYWRITER_H

#include <iostream>
#include <fstream>
#include <vector>

template <typename T>
class BinaryWriter {
public:
    explicit BinaryWriter(const std::string &file_name);
    ~BinaryWriter();
    void Write(const T& object);
    void Write(const std::vector<T>& objects);
    void Close();
private:
    std::ofstream file_out;
};

template<typename T>
BinaryWriter<T>::BinaryWriter(const std::string &file_name)  :
    file_out(std::ofstream(file_name, std::ios::binary))
{

}

template<typename T>
BinaryWriter<T>::~BinaryWriter() {
    Close();
}

template<typename T>
void BinaryWriter<T>::Write(const T &object) {
    file_out.write((char*)&object, sizeof(object));
}

template<typename T>
void BinaryWriter<T>::Write(const std::vector<T> &objects) {
    for(const auto& object : objects){
        Write(object);
    }
}

template<typename T>
void BinaryWriter<T>::Close() {
    file_out.close();
}


#endif //LABBINARY_BINARYWRITER_H
