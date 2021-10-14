#include "HashTable.h"
#include <string>
#include <iostream>

HashTable::HashTable() {
    size = default_size;
    count = 0;
    table.resize(default_size);
}

HashTable::~HashTable() {
    size = 0;
    count = 0;
    table.clear();
}

HashTable::HashTable(const HashTable& b) {
    size = b.size;
    count = b.count;
    table.resize(size);
    for (int i = 0; i < size; ++i) {
        table[i] = b.table[i];
    }
}

HashTable::HashTable(HashTable &&b) {
    size = b.size;
    count = b.count;
    table.resize(size);
    for (int i = 0; i < size; ++i) {
        table[i] = b.table[i];
    }
    b.Clear();
}

HashTable& HashTable::operator=(const HashTable& b) {
    this->Clear();
    size = b.size;
    count = b.count;
    table.resize(size);
    for (int i = 0; i < size; ++i) {
        table[i] = b.table[i];
    }
    return *this;
}

HashTable& HashTable::operator=(HashTable &&b) {
    this->Clear();
    size = b.size;
    count = b.count;
    table.resize(size);
    for (int i = 0; i < size; ++i) {
        table[i] = b.table[i];
    }
    b.Clear();
    return *this;
}

void HashTable::Swap(HashTable &b) {
    HashTable tmp(*this);
    *this = b;
    b = tmp;
}

void HashTable::Clear() {
    size = 0;
    count = 0;
    for (int i = 0; i < table.size(); ++i) {
        table[i].clear();
    }
}

bool HashTable::Erase(const Key &k) {
    int idx = HashFunction(k);
    for (auto i = table[idx].begin(); i != table[idx].end(); ++i) {
        if (i->first == k) {
            table[idx].erase(i);
            return true;
        }
    }
    return false;
}

bool HashTable::Insert(const Key &k, const Value &v) {
    int idx = HashFunction(k);
    for (auto& pair : table[idx]) {
        if (pair.first == k) {
            return false;
        }
    }
    table[idx].emplace_back(k, v);
    count += 1;
    if ((count / (double)size) > 0.75) {
        Refresh();
    }
    return true;
}

bool HashTable::Find(const Key &k) const {
    int idx = HashFunction(k);
    for (auto& pair : table[idx]) {
        if (pair.first == k) {
            return true;
        }
    }
    return false;
}

Value& HashTable::operator[](const Key &k) {
    int idx = HashFunction(k);
    for (auto& pair : table[idx]) {
        if (pair.first == k) {
            return pair.second;
        }
    }
    table[idx].emplace_back(k, Value());
    count += 1;
    return table[idx].back().second;
}

Value& HashTable::At(const Key &k) {
    int idx = HashFunction(k);
    for (auto& pair : table[idx]) {
        if (pair.first == k) {
            return pair.second;
        }
    }
    throw std::runtime_error("Key not found");
}

const Value& HashTable::At(const Key &k) const {
    int idx = HashFunction(k);
    for (auto& pair : table[idx]) {
        if (pair.first == k) {
            return pair.second;
        }
    }
    throw std::runtime_error("Key not found");
}

int HashTable::Size() const {
    return size;
}

int HashTable::GetCount()  {
    return count;
}

bool HashTable::IsEmpty() const {
    return (count == 0);
}

bool operator==(const HashTable& a, const HashTable& b) {
    if (a.size != b.size) {
        return false;
    }
    if (a.count != b.count) {
        return false;
    }
    for (int i = 0; i < a.Size(); i++) {
        auto iter_a = a.table[i].begin();
        auto iter_b = b.table[i].begin();
        while (iter_a != a.table[i].end() && iter_b != b.table[i].end()) {
            if ((iter_a->first != iter_b->first) || (iter_a->second.age != iter_b->second.age) || (iter_a->second.weight != iter_b->second.weight)) {
                return false;
            }
            else {
                iter_a ++;
                iter_b ++;
                continue;
            }
        }
    }
    return true;
}

bool operator!=(const HashTable& a, const HashTable& b) {
    if (a == b) {
        return false;
    }
    return true;
}

int HashTable::HashFunction(const Key& k) const {
    int result = 0;
    for (char c : k) {
        result += c;
    }
    return result % size;
}

void HashTable::Refresh() {
    HashTable new_table;
    new_table.size = size * 2;
    new_table.table.resize(new_table.size);
    for (int i = 0; i < size; ++i) {
        for (auto &pair : table[i]) {
            new_table.Insert(pair.first, pair.second);
        }
    }
    size = new_table.size;
    *this = new_table;
}

void HashTable::PrintTable() {
    for (int i = 0; i < table.size(); ++i) {
        std::cout << "[" << i << "]" << " ";
        for (auto& pair : table[i]) {
            std::cout << pair.first << " " << pair.second.age << " " << pair.second.weight << "; ";
        }
        std::cout << std::endl;
    }
    std::cout << "____________________________________________________" << std::endl;
}