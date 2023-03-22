#pragma once
#include "Node.h"

class List
{
public:
	Node* head;
	List();
	void addElement(int data);
	void removeElement(int data);
	void displayList();
	void removeAll();
};

