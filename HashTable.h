#pragma once
#include "LinkedList.h"

class HashTable {
private:
    int M;                   // Поточний розмір масиву (кількість бакетів)
    int currentSize;         // Скільки елементів реально вставлено
    float maxLoadFactor;     // Поріг, після якого розширюємося (наприклад, 2.0 або 0.75)
    LinkedList* bucketsArray; // Масив списків

    // Хеш-функція (залишок від ділення)
    int hashFunction(long long key) {
        return key % M;
    }

    // Внутрішній метод для збільшення таблиці
    void rehash();

public:
    // Конструктор: початковий розмір M може бути невеликим (напр. 10)
    HashTable(int initialCapacity = 100, float loadFactor = 2.0);
    ~HashTable();

    void insert(long long key, Data value);
    Data* find(long long key);
    void erase(long long key);
    
    int size();
    float getLoadFactor();
};