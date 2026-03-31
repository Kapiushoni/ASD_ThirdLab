#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr), current_size(0) {}

LinkedList::~LinkedList() {
    clear();
}

// Вставка: якщо ключ уже є - оновлюємо дані, якщо немає - додаємо в початок (це найшвидше)
void LinkedList::insertOrUpdate(long long key, Data value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.key == key) {
            current->data.value = value; // Оновлюємо, якщо такий iPhone вже є
            return;
        }
        current = current->next;
    }
    // Якщо не знайшли — додаємо в початок (O(1))
    head = new Node(key, value, head);
    current_size++;
}

// Пошук за ключем: повертаємо вказівник на вузол, щоб HashTable могла його прочитати
HashNode* LinkedList::find(long long key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.key == key) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}

// Видалення за ключем
bool LinkedList::removeByKey(long long key) {
    if (head == nullptr) return false;

    if (head->data.key == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        current_size--;
        return true;
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data.key == key) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            current_size--;
            return true;
        }
        current = current->next;
    }
    return false;
}

int LinkedList::size() {
    return current_size;
}

void LinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    current_size = 0;
}