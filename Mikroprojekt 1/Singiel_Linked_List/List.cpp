#include "List.h"
#include <iostream>

List::List()
{
	head = nullptr;
}

void List::addElement(int data)
{
	Node* newNode = new Node(data); // stworzenie nowego węzła i przypisanie do niego wartości
	if (head == nullptr) {
		head = newNode;
		// jeżeli jest to pierwszy node w liście to przypisujemy do head wskaźnik z nowego Noda
	}
	else {
		// przypisanie lokalizacji heada listy do węzła
		Node* last = head;
		// iterowanie do momentu aż przed chwilą stworzony węzeł dojdzie do ostatniego elementu
		while (last->next != nullptr) {
			last = last->next;
		}
		// po przejściu do końca przypisanie wskaźnika ostatniego elementu na nowego noda
		last->next = newNode;
	}
}

void List::removeElement(int data)
{
	// jeżeli lista jest pusta
	if (head == nullptr) {
		std::cout << "Lista jest pusta\n";
	}
	// jeżeli element, który chcemy usunąć jest pierwszy na liście
	if (head->data == data) {
		head = head->next;
	}
	Node* toDelete = head;
	// iterowanie po całej liście w poszukiwaniu elementu, który chcemy usunąć
	while (toDelete->next != nullptr) {
		// jeżeli wartość z noda następnego od tego, w którym aktualnie się znajdujemy jest równa wartości poszukiwanej to przekaż ptr next naszego aktualnego elementy na ptr ptra nexta
		if (toDelete->next->data == data) {
			toDelete->next = toDelete->next->next;
		}
		// jak nie spełni warunktu to przekaż wartość następnego nexta na node, który służy do poszukiwania elementu
		toDelete = toDelete->next;
	}
}

void List::displayList()
{
	Node* show = head; // przypisanie do zmiennej, którą będziemy pokazywać, pierwszego elementu
	if (head == nullptr)
		std::cout << "Lista jest pusta!\n";
	while (show != nullptr) {
		std::cout << show->data << " "; // pokazanie wartości przypisanej do tego węzła, na który ma wskaźnik zmienna show
		show = show->next; // zmienienie wskaźnika w zmiennej show na wskaśźnik w następnym węźle
	}
	std::cout << std::endl;
}

void List::removeAll()
{
	while (head != nullptr) {
		Node* toDelete = head; // przypisanie komórki z pamięci, którą chcemy usunąć do pierwszego elementu (head)
		head = head->next; // przekazanie głowy na następny element (skrócenie listy)
		delete toDelete; // usuniecie komorki z pamieci
	}
}
