#include <iostream>
#include <gtest/gtest.h>
#include "../HashTable.h"


class HashTableFixture : public ::testing::Test {
protected:
    HashTable ht;
    HashTable empty_ht;
    virtual void SetUp() {
        for (unsigned int i = 0; i < 10; ++i) {
            ht.Insert(std::to_string(i), {i, i});
        }
    }
};

TEST_F(HashTableFixture, CopyConstructor) {
    HashTable copy(ht);
    EXPECT_EQ(ht, copy);
    EXPECT_NE(0, ht.GetCount());
}

TEST_F(HashTableFixture, MoveConstructor) {
    HashTable copy(ht);
    HashTable move(std::move(ht));
    EXPECT_EQ(copy, move);
    EXPECT_EQ(0, ht.GetCount());
}

TEST_F(HashTableFixture, CopyOperator) {
    HashTable copy = ht;
    EXPECT_EQ(ht, copy);
    EXPECT_NE(0, ht.GetCount());
}

TEST_F(HashTableFixture, MoveOperator) {
    HashTable copy(ht);
    HashTable move = std::move(ht);
    EXPECT_EQ(copy, move);
    EXPECT_EQ(0, ht.GetCount());
}

TEST_F(HashTableFixture, Swap) {
    HashTable ht_copy = ht;
    HashTable empty_ht_copy = empty_ht;
    ht.Swap(empty_ht);
    EXPECT_EQ(ht, empty_ht_copy);
    EXPECT_EQ(empty_ht, ht_copy);
}

TEST_F(HashTableFixture, Clear) {
    EXPECT_NE(0, ht.GetCount());
    ht.Clear();
    EXPECT_EQ(0, ht.GetCount());
}

TEST_F(HashTableFixture, Erase) {
    for (unsigned i = 0; i < 10; ++i) {
        EXPECT_EQ(1, ht.Erase(std::to_string(i)));
        EXPECT_EQ(0, ht.Erase(std::to_string(i + 10)));
    }
}

TEST_F(HashTableFixture, Insert) {
    int count = ht.GetCount();
    for (unsigned i = 0; i < 10; ++i) {
        EXPECT_EQ(0, ht.Insert(std::to_string(i), {i, i}));
        EXPECT_EQ(1, ht.Insert(std::to_string(i + 10), {i, i}));
        EXPECT_EQ(count + 1, ht.GetCount());
        count = ht.GetCount();
    }
}

TEST_F(HashTableFixture, Find) {
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(1, ht.Find(std::to_string(i)));
        EXPECT_EQ(0, ht.Find(std::to_string(i + 10)));
    }
}

TEST_F(HashTableFixture, At) {
    for (unsigned i = 0; i < 10; ++i) {
        EXPECT_EQ(i, ht.At(std::to_string(i)).weight);
        EXPECT_EQ(i, ht.At(std::to_string(i)).age);
        EXPECT_EQ(0,ht.Find(std::to_string(i + 10)));
        EXPECT_THROW(ht.At(std::to_string(i + 10)), std::runtime_error);
    }
}

TEST_F(HashTableFixture, operatorAt) {
    for (unsigned i = 0; i < 10; ++i) {
        EXPECT_EQ(i, ht[std::to_string(i)].weight);
        EXPECT_EQ(i, ht[std::to_string(i)].age);
    }
    EXPECT_EQ(0, ht.Find(std::to_string(10)));
    EXPECT_EQ(0, ht[std::to_string(10)].weight);
    EXPECT_EQ(0, ht[std::to_string(10)].age);
}

TEST_F(HashTableFixture, IsEmpty) {
    EXPECT_NE(0, ht.GetCount());
    EXPECT_EQ(0, empty_ht.GetCount());
    EXPECT_TRUE(empty_ht.IsEmpty());
    EXPECT_FALSE(ht.IsEmpty());
}

TEST_F(HashTableFixture, operatorEQ) {
    HashTable new_ht;
    EXPECT_EQ(empty_ht, new_ht);
    EXPECT_NE(ht, new_ht);
    for (unsigned int i = 0; i < 10; ++i) {
        new_ht.Insert(std::to_string(i), {i, i});
    }
    EXPECT_EQ(ht, new_ht);
    EXPECT_NE(empty_ht, new_ht);
}