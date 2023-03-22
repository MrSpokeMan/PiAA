#include "QueDs.h"
#include <iostream>

QueDs::QueDs()
{
	head = nullptr;
	tail = nullptr;
}

void QueDs::add(int data)
{
	Node* newNode = new Node(data);
	// jeżeli kolejka jest pusta to tail i head przypisać do nowego węzła
	if (tail == nullptr) {
		tail = newNode;
		head = newNode;
	}
	else { // jeśli już istnieją jakieś miejsca w kolejce to zmienić tylko tail na nowy node i next tego noda dać na to gdzie wcześniej był tail
		tail->next = newNode;
		tail = newNode;
	}

}

// usuwanie elementu, który pierwszy wylądował w kolejce
void QueDs::remove()
{
	Node* toDelete = head;
	head = head->next;
	if (head == nullptr) {
		tail = nullptr;
	}
	delete toDelete;
}

void QueDs::display()
{
	Node* show = head;
	if (head == nullptr)
		std::cout << "Kolejka jest pusta!\n";
	while (show != nullptr) {
		std::cout << show->data << " ";
		show = show->next;
	}
	std::cout << std::endl;
}

void QueDs::removeAll()
{
	Node* toDelete = head;
	while (head != nullptr) {
		Node* toDelete = head;
		head = head->next;
		delete toDelete;
	}
	tail = nullptr;
}
