#include "Deque.h"
#include <iostream>

Deque::Deque()
{
	head = nullptr;
	tail = nullptr;
}

int Deque::Size()
{
	return size;
}

bool Deque::isEmpty()
{
	if (head == nullptr || tail == nullptr)
		return true;
	else
		return false;
}

int Deque::first()
{
	if (head == nullptr) {
		throw std::runtime_error("Deque jest pusta");
	}
	return head->data;
}

int Deque::last()
{
	if (tail == nullptr) {
		throw std::runtime_error("Deque jest pusta");
	}
	return tail->data;
}

void Deque::addFirst(int data)
{
	Node* newNode = new Node(data);
	if (head == nullptr) {
		head = tail = newNode;
	}
	else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	size++;
}

void Deque::deleteFirst()
{
	if (head == nullptr)
		throw std::runtime_error("Deque jest pusta");
	Node* toDelete = head;
	head = toDelete->next;
	if (head != nullptr)
		head->prev = nullptr;
	else
		tail = nullptr;
	delete toDelete;
	size--;
}

void Deque::addLast(int data)
{
	Node* newNode = new Node(data);
	if (tail == nullptr) {
		tail = head = newNode;
	}
	else {
		newNode->next = tail;
		tail->prev = newNode;
		tail = newNode;
	}
	size++;
}

void Deque::deleteLast()
{
	if (tail == nullptr)
		throw std::runtime_error("Deque jest pusta");
	Node* toDelete = tail;
	tail = toDelete->prev;
	if (tail != nullptr)
		tail->next = nullptr;
	else
		head = nullptr;

	delete toDelete;
	size--;
}