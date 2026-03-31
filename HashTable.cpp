#include "HashTable.h"

HashTable::HashTable(int initialCapacity, float loadFactor) 
    : M(initialCapacity), currentSize(0), maxLoadFactor(loadFactor) {
    bucketsArray = new LinkedList[M];
}

HashTable::~HashTable() {
    delete[] bucketsArray;
}

int HashTable::size() {
    return currentSize;
}

float HashTable::getLoadFactor() {
    return (float)currentSize / M;
}

void HashTable::insert(long long key, Data value) {
    // 1. Перевіряємо завантаженість. Якщо вона завелика - розширюємося.
    if (getLoadFactor() > maxLoadFactor) {
        rehash();
    }

    // 2. Рахуємо індекс для вставки
    int index = hashFunction(key);

    // 3. Запам'ятовуємо старий розмір списку, щоб зрозуміти, чи додався новий елемент
    int oldListSize = bucketsArray[index].size();
    bucketsArray[index].insertOrUpdate(key, value);
    int newListSize = bucketsArray[index].size();

    // Якщо список став довшим — значить, ми додали новий унікальний ключ
    if (newListSize > oldListSize) {
        currentSize++;
    }
}

Data* HashTable::find(long long key) {
    int index = hashFunction(key);
    HashNode* node = bucketsArray[index].find(key);
    
    if (node != nullptr) return &(node->value);
    return nullptr;
}

void HashTable::erase(long long key) {
    int index = hashFunction(key);
    if (bucketsArray[index].removeByKey(key)) {
        currentSize--;
    }
}

// Динамічне розширення (Оптимізована версія)
void HashTable::rehash() {
    int oldM = M;
    LinkedList* oldArray = bucketsArray;

    // 1. Збільшуємо розмір масиву вдвічі
    M = oldM * 2;
    bucketsArray = new LinkedList[M];
    
    // 2. Тимчасово скидаємо лічильник елементів, бо ми їх перерахуємо заново
    currentSize = 0; 

    // 3. Переносимо дані зі старої таблиці в нову
    for (int i = 0; i < oldM; i++) {
        Node* current = oldArray[i].head;
        while (current != nullptr) {
            // Рахуємо НОВИЙ індекс з урахуванням нового розміру M
            int newIndex = hashFunction(current->data.key);
            
            // Вставляємо безпосередньо в бакет нового масиву.
            // Ми використовуємо insertOrUpdate зі списку, але минаємо метод insert() самої таблиці.
            // Це позбавляє нас від перевірки loadFactor на кожному кроці перенесення.
            bucketsArray[newIndex].insertOrUpdate(current->data.key, current->data.value);
            
            currentSize++; // Збільшуємо лічильник для нової таблиці
            current = current->next;
        }
    }

    // 4. Очищуємо пам'ять, яку займав старий масив списків
    delete[] oldArray;
}