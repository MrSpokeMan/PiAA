#pragma once
#include "Node.h"

class QueDs
{
public:
	Node* head;
	Node* tail;
	QueDs();
	void add(int data); // dodawanie tylko na tail
	void remove(); // usuwanie tylko z head
	void display();
	void removeAll();
};

