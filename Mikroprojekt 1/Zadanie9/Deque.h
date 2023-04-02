#pragma once
#include "Node.h"

class Deque
{
	int size;
	Node* head;
	Node* tail;
public:
	Deque();
	int Size(); // rozmiar 
	bool isEmpty(); // czy jest pusta
	int first();
	int last();
	void addFirst(int data);
	void deleteFirst();
	void addLast(int data);
	void deleteLast();
};