#pragma once
#include "Structures.h"

struct Node {
    HashNode data; // Зберігаємо пару Ключ + Iphone
    Node* next;
    Node(long long k, Data v, Node* n = nullptr) : data{k, v}, next(n) {}
};

struct LinkedList {
    Node* head;
    int current_size;

    LinkedList();
    ~LinkedList();

    // Основні методи для хеш-таблиці
    void insertOrUpdate(long long key, Data value);
    HashNode* find(long long key);
    bool removeByKey(long long key);
    
    int size();
    void clear();
};