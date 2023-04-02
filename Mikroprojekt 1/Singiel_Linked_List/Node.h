#pragma once
class Node // stworzenie struktury węzła (miejsce na warotść przechowywaną i wskaźnik dający referencję na kolejny węzeł)
{
public:
	int data;
	Node* next;
	Node(int data);
};

