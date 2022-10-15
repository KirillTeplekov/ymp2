#pragma once
#include <string>

typedef int Data;

struct Node {
    Data data;
    Node* next;
};

typedef Node* TList;

void init(TList& list);
bool isEmpty(TList list);
void print(TList list);
void createAsStack(TList& list, int count);
void createAsQueue(TList& list, int count);
void addToHead(TList& list, Data value);
void addAfterNode(TList list, Data value);
void deleteFromHead(TList& list);
void deleteAfterNode(TList list);
