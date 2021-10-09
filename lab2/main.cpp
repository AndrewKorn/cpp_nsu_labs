#include <iostream>
#include "HashTable.h"

int main() {
    HashTable HT;
    HashTable HT2;

    Student s = {14, 15};
    HT.Insert("A", s);
    HT.PrintTable();

    HT2 = std::move(HT);

    HT.PrintTable();
    HT2.PrintTable();
    return 0;
}
