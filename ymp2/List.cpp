#include "List.h"
#include <iostream>
#include <fstream>

void init(TList& list) {
    list = nullptr;
}

bool isEmpty(TList list) {
    return list == nullptr;
}

void print(TList list) {
    TList p = list;
    while (p != nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

void createAsStack(TList& list, int count) {
    init(list);
    for (int i = 0; i < count; i++) {
        addToHead(list, i);
    }
}

void createAsQueue(TList& list, int count) {
    init(list);
    for (int i = count - 1; i >= 0; i--)
        addToHead(list, i);
}

void addToHead(TList& head, Data value) {
    TList p = new Node;
    p->data = value;
    p->next = head;
    head = p;
}

void addAfterNode(TList list, Data value) {
    TList p = new Node;
    p->data = value;
    p->next = list->next;
    list->next = p;
}

void deleteFromHead(TList& list) {
    TList current = list;
    list = list->next;
    current->next = nullptr;
    delete current;
}

void deleteAfterNode(TList list) {
    TList temp = list->next;
    list->next = temp->next;
    delete temp;
}