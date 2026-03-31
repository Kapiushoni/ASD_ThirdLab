#pragma once
#include "Structures.h"

enum SlotState { EMPTY, OCCUPIED, DELETED };

struct Slot {
    long long key;
    Data value;
    SlotState state = EMPTY;
};

class OpenHashTable {
private:
    int M;
    int currentSize;
    float maxLoadFactor;
    Slot* table;

    int hash(long long key, int i) {
        // Лінійне пробування: (h1(k) + i) % M
        return (key % M + i) % M;
    }

    void rehash();

public:
    OpenHashTable(int initialCapacity = 100, float loadFactor = 0.5); // LoadFactor має бути меншим для відкритої адресації
    ~OpenHashTable();

    void insert(long long key, Data value);
    Data* find(long long key);
    void erase(long long key);
    int size() { return currentSize; }
};