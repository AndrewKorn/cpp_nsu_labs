#pragma once
#include <iostream>
#include <string>
class HashTable {
private:

public:
    HashTable();
    ~HashTable();

    HashTable(const HashTable& b);
    HashTable(HashTable&& b);

    HashTable& operator = (const  HashTable& b);
    HashTable& operator = (HashTable&& b);

    void Swap(HashTable& b);
    void Clear();
    bool Erase(const std::string key);
    bool Insert();
};