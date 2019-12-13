//
// Created by stas on 15.11.19.
//

#ifndef LABBINARY_BINARYREADER_H
#define LABBINARY_BINARYREADER_H

#include <string>
#include <vector>
#include <fstream>

template<typename T>
class BinaryReader {
public:
    explicit BinaryReader(const std::string &file_name);
    ~BinaryReader();
    void Read(T& object);
    void Read(std::vector<T>& objects);
    bool HasNext();
    void Close();
private:
    std::ifstream ifstream;
};

template<typename T>
BinaryReader<T>::BinaryReader(const std::string &file_name) :
        ifstream(std::ifstream(file_name, std::ios::binary)){

}

template<typename T>
BinaryReader<T>::~BinaryReader() {
    Close();
}

template<typename T>
void BinaryReader<T>::Read(T& object) {
    ifstream.read((char*)&object, sizeof(object));
}

template<typename T>
void BinaryReader<T>::Read(std::vector<T> &objects) {
    objects.resize(0);
    while (HasNext()){
        T person;
        Read(person);
        objects.push_back(person);
    }
}

template<typename T>
bool BinaryReader<T>::HasNext() {
    return ifstream.peek() != EOF;
}

template<typename T>
void BinaryReader<T>::Close() {
    ifstream.close();
}


#endif //LABBINARY_BINARYREADER_H
