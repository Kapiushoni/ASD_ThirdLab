#include <iostream>
#include <ctime>
#include <unordered_map>
#include "HashTable.h"
#include "Structures.h"

using namespace std;

// 1. Реалізація функції для генерації великих рандомних чисел (Пункт 1.1 лаби)
long long generateRandLong() {
    // Оскільки звичайний rand() часто обмежений 32767, 
    // ми комбінуємо кілька викликів для отримання великого числа
    long long value = rand();
    value = (value << 32) | (rand() << 16) | rand();
    if (value < 0) value *= -1; // Нам потрібні позитивні ключі
    return value;
}


bool testHashTable()
{
 const int iters = 500000;
 const int keysAmount = iters * 1;
 // generate random keys:
 long long* keys = new long long[keysAmount];
 long long* keysToInsert = new long long[iters];
 long long* keysToErase = new long long[iters];
 long long* keysToFind = new long long[iters];
 for (int i = 0; i < keysAmount; i++)
 {
 keys[i] = generateRandLong();
 }
 for (int i = 0; i < iters; i++)
 {
 keysToInsert[i] = keys[generateRandLong() % keysAmount];
 keysToErase[i] = keys[generateRandLong() % keysAmount];
 keysToFind[i] = keys[generateRandLong() % keysAmount];
 }
 // test my HashTable:
 HashTable hashTable;
 clock_t myStart = clock();
 for (int i = 0; i < iters; i++)
 {
 hashTable.insert(keysToInsert[i], Data());
 }
 int myInsertSize = hashTable.size();
 for (int i = 0; i < iters; i++)
 {
 hashTable.erase(keysToErase[i]);
 }
 int myEraseSize = hashTable.size();
 int myFoundAmount = 0;
 for (int i = 0; i < iters; i++)
 {
 if (hashTable.find(keysToFind[i]) != NULL)
 {
 myFoundAmount++;
 }
 }
 clock_t myEnd = clock();
 float myTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;
 // test STL hash table:
 unordered_map<long long, Data> unorderedMap;
 clock_t stlStart = clock();
 for (int i = 0; i < iters; i++)
 {
 unorderedMap.insert({keysToInsert[i], Data()});
 }
 int stlInsertSize = unorderedMap.size();
 for (int i = 0; i < iters; i++)
 {
 unorderedMap.erase(keysToErase[i]);
 }
 int stlEraseSize = unorderedMap.size();
 int stlFoundAmount = 0;
 for (int i = 0; i < iters; i++)
 {
 if (unorderedMap.find(keysToFind[i]) != unorderedMap.end())
 {
 stlFoundAmount++;
 }
 }
 clock_t stlEnd = clock();
 float stlTime = (float(stlEnd - stlStart)) / CLOCKS_PER_SEC;
 cout << "My HashTable:" << endl;
 cout << "Time: " << myTime << " , after insert: " << myInsertSize << " , after erase:" << myEraseSize << ", found: " << myFoundAmount << endl;
 cout << "STL unordered_map:" << endl;
 cout << "Time: " << stlTime << " , after insert: " << stlInsertSize << " , after erase:" << stlEraseSize << ", found: " << stlFoundAmount << endl << endl;
 delete[] keys;
 delete[] keysToInsert;
 delete[] keysToErase;
 delete[] keysToFind;
 if (myInsertSize == stlInsertSize && myEraseSize == stlEraseSize && myFoundAmount ==
stlFoundAmount)
 {
 cout << "The lab is completed" << endl;
 return true;
 }
 cerr << ":(" << endl;
 return false;
}



// ==========================================================

int main() {
    // Встановлюємо кодування для коректного відображення тексту в консолі (якщо Windows)
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    // Ініціалізація генератора випадкових чисел поточним часом
    srand(static_cast<unsigned int>(time(0)));

    cout << "--- Лабораторна робота №3: Дослідження хеш-таблиці ---" << endl;
    cout << "Виконав: Артур Галечян" << endl; // Твоє ім'я для звіту
    cout << "Варіант 5: Магазин iPhone" << endl << endl;

    cout << "Запуск тестування..." << endl;
    
    // Виклик тесту
    if (testHashTable()) {
        cout << "------------------------------------------------" << endl;
        cout << "Результат: Твоя хеш-таблиця працює вірно!" << endl;
    } else {
        cout << "------------------------------------------------" << endl;
        cout << "Результат: Є розбіжності з STL або помилка в логіці." << endl;
    }

    return 0;
}