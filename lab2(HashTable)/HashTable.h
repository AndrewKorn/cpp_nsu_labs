#pragma once
#include <string>
#include <list>
#include <vector>

struct Student {
    unsigned age;
    unsigned weight;
};

typedef std::string Key;
typedef Student Value;

class HashTable {
private:
    static const int default_size = 10;
    int count;
    int size;
    std::vector<std::list<std::pair<Key, Value>>> table;

    int HashFunction(const Key& k) const;
    void Refresh();

public:
    HashTable();
    ~HashTable();

    HashTable(const HashTable& b);
    HashTable(HashTable&& b);


    HashTable& operator=(const HashTable& b);
    HashTable& operator=(HashTable&& b);

    // Обменивает значения двух хэш-таблиц.
    void Swap(HashTable& b);

    // Очищает контейнер.
    void Clear();
    // Удаляет элемент по заданному ключу.
    bool Erase(const Key& k);
    // Вставка в контейнер. Возвращаемое значение - успешность вставки.
    bool Insert(const Key& k, const Value& v);

    // Проверка наличия значения по заданному ключу.
    bool Find(const Key& k) const;

    // Возвращает значение по ключу. Небезопасный метод.
    // В случае отсутствия ключа в контейнере, следует вставить в контейнер
    // значение, созданное конструктором по умолчанию и вернуть ссылку на него.
    Value& operator[](const Key& k);

    // Возвращает значение по ключу. Бросает исключение при неудаче.
    Value& At(const Key& k);
    const Value& At(const Key& k) const;

    int Size() const;
    int GetCount();
    bool IsEmpty() const;

    friend bool operator==(const HashTable&a, const HashTable& b);
    friend bool operator!=(const HashTable& a, const HashTable& b);

    void PrintTable();
};

bool operator==(const HashTable& a, const HashTable& b);
bool operator!=(const HashTable& a, const HashTable& b);