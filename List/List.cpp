#include "List.h"
#include <iostream>

List::List()
	:head(nullptr), tail(nullptr), size(0)
{}

List::~List()
{
	clear();
}

List::List(const List& other)
	:head(nullptr), tail(nullptr), size(0)
{
	if (other.size == 0)
		return;

	Node* current = other.head;
	Node* prevNode = nullptr;
	Node* curNode = nullptr;
	while (current)
	{
		prevNode = curNode;
		curNode = new Node(prevNode, current->value);

		size == 0 ? head = curNode : prevNode->next = curNode;

		tail = curNode;
		current = current->next;
		size++;
	}
}

void List::push_back(int value)
{
	if (head && tail)
	{
		Node* new_node = new Node(tail, value);
		tail->next = new_node;
		tail = new_node;
	}
	else
	{
		Node* new_node = new Node(value);
		head = new_node;
		tail = new_node;
	}
	size++;
}

void List::push_front(int value)
{
	if (head && tail)
	{
		Node* new_node = new Node(value, head);
		head->prev = new_node;
		head = new_node;
	}
	else
	{
		Node* new_node = new Node(value);
		tail = new_node;
		head = new_node;
	}
	size++;
}



void List::clear()
{
	if (size = 0)
		return;

	Node* current = tail;
	Node* temp;
	while (current)
	{
		temp = current->prev;
		delete current;
		current = temp;
	}
	tail = nullptr;
	head = nullptr;
	size = 0;
}

int List::operator[](int index)
{
	Node* current = head;
	for (size_t i = 0; i < index; i++)
	{
		current = current->next;

	}
	return current->value;
}

void List::insert(int index, int value)
{
	Node* current = head;
	Node* new_node = new Node(value);
	for (int i = 0; i < index; i++);
}

int List::back() 
{
	if (tail)
	{
		return tail -> value;
}
}

int List::front()
{
	return 0;
}

void List::show() const
{
	Node* current = head;
	while (current)
	{
		std::cout << current->value << ' ';
		current = current->next;
	}
	std::cout << std::endl;
}