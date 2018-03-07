#pragma once
#include <iostream>

template <class T>
struct TNode
{
	T dat;
	TNode<T>* next = NULL;
};

template <class T>
class Linked_List {
private:
	TNode<T> *begnode = NULL;
	TNode<T> *headnode = NULL;
	bool empty;
public:
	TNode<T> *it = NULL;
	Linked_List();
	~Linked_List();
	bool SetIterator(size_t pos);    //set iterator  to chosen node
	T ReturnVal();                   //return value of the node and set iterator to the next one
	bool PushBack(T data);           //add node to the end of the list
	bool Insert(size_t pos, T data); //add node to the chosen place of list
	bool DelElement(size_t pos);     //delete chosen node
	size_t Numb();                   //reurn number of nodes
	TNode<T>* End();                 //return pointer to the last node
};

template<class T>
Linked_List<T>::Linked_List()
{
	this->begnode = NULL;
	this->headnode = this->begnode;
	empty = true;
	this->it = this->begnode;
}

template<class T>
Linked_List<T>::~Linked_List()
{
	TNode<T>*node;
	while (begnode != NULL) {
		node = this->begnode;
		this->begnode = (this->begnode)->next;
		delete (node);
	}
}

template<class T>
inline bool Linked_List<T>::SetIterator(size_t pos)
{
	this->it = this->begnode;
	for (size_t i = 0; i < pos - 1; i++)
		this->it = (this->it)->next;
	return false;
}

template<class T>
T Linked_List<T>::ReturnVal()
{
	TNode<T> *node = this->it;
	this->it = it->next;
	return T(node->dat);
}

template<class T>
bool Linked_List<T>::PushBack(T data)
{
	TNode<T>* tmp = new TNode<T>();
	tmp->dat = data;
	if (empty) {
		empty = false;
		this->begnode = tmp;
		this->headnode = tmp;
		this->it = tmp;
		return false;
	}
	(this->headnode)->next = tmp;
	this->headnode = tmp;
	return false;
}

template<class T>
bool Linked_List<T>::Insert(size_t pos, T data)
{
	TNode<T>*node = new TNode<T>();
	node->dat = data;
	if (pos == 1) {
		node->next = this->begnode;
		begnode = node;
		return true;
	}
	else {
		TNode<T>* tmp = this->begnode;
		for (size_t i = 0; i < pos - 2 && tmp->next; i++)
			tmp = tmp->next;
		node->next = tmp->next;
		tmp->next = node;
		if (node->next == NULL)
			this->headnode = node;
		return true;
	}
	return false;
}

template<class T>
bool Linked_List<T>::DelElement(size_t pos)
{
	TNode<T>*tmp = this->begnode;
	if (pos == 1) {
		this->begnode = (this->begnode)->next;
		delete tmp;
		return true;
	}
	else {
		for (size_t i = 0; i < pos - 2; i++) {
			if (tmp->next == NULL)
				return false;
			tmp = tmp->next;
		}
		TNode<T>*del = tmp->next;
		tmp->next = (tmp->next)->next;
		delete del;
		if (tmp->next == NULL)
			this->headnode = tmp;
		return true;
	}
	return false;
}

template<class T>
size_t Linked_List<T>::Numb()
{
	TNode<T>* tmp = this->begnode;
	size_t k = 1;
	while (tmp != this->headnode)
	{
		k++;
		tmp = tmp->next;
	}
	return k;
}

template<class T>
TNode<T>* Linked_List<T>::End()
{
	return (this->headnode);
}
