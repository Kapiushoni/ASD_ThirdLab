#include "OpenHashTable.h"

OpenHashTable::OpenHashTable(int initialCapacity, float loadFactor) 
    : M(initialCapacity), currentSize(0), maxLoadFactor(loadFactor) {
    table = new Slot[M];
}

OpenHashTable::~OpenHashTable() {
    delete[] table;
}

void OpenHashTable::insert(long long key, Data value) {
    if ((float)currentSize / M > maxLoadFactor) rehash();

    for (int i = 0; i < M; i++) {
        int index = hash(key, i);
        if (table[index].state == EMPTY || table[index].state == DELETED || table[index].key == key) {
            if (table[index].state != OCCUPIED || table[index].key != key) currentSize++;
            table[index].key = key;
            table[index].value = value;
            table[index].state = OCCUPIED;
            return;
        }
    }
}

Data* OpenHashTable::find(long long key) {
    for (int i = 0; i < M; i++) {
        int index = hash(key, i);
        if (table[index].state == EMPTY) return nullptr;
        if (table[index].state == OCCUPIED && table[index].key == key) return &table[index].value;
    }
    return nullptr;
}

void OpenHashTable::erase(long long key) {
    for (int i = 0; i < M; i++) {
        int index = hash(key, i);
        if (table[index].state == EMPTY) return;
        if (table[index].state == OCCUPIED && table[index].key == key) {
            table[index].state = DELETED;
            currentSize--;
            return;
        }
    }
}

void OpenHashTable::rehash() {
    int oldM = M;
    Slot* oldTable = table;

    M *= 2;
    table = new Slot[M];
    currentSize = 0;

    for (int i = 0; i < oldM; i++) {
        if (oldTable[i].state == OCCUPIED) {
            insert(oldTable[i].key, oldTable[i].value);
        }
    }
    delete[] oldTable;
}