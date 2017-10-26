/*
 * OrderedLinkedList.h
 *
 *  Created on: Oct 16, 2017
 *      Author: ferdinandtembo
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_
#include <iostream>
#include "LinkedList.h"
using namespace std;


template <class T>
class OrderedLinkedList : public LinkedList<T>{

public:
	OrderedLinkedList();
	void display();
	void display(node<T>* item);
	void insert(T& item);
	Passenger* search(const Passenger& passenger);
	void deletePassenger(Passenger& pass);
	Passenger* deletePassenger();
	~OrderedLinkedList();

};




template <class T>
void OrderedLinkedList<T> ::  deletePassenger(Passenger& pass){

	this->deleteNote(pass);
}


template <class T>
Passenger* OrderedLinkedList<T> ::  search(const Passenger& pass){

	if(this->head == NULL){
		return NULL;
	}
	else{
		node<T> *cp = this->head;
		while(cp!=NULL){
			if(cp->data == pass){
				return &cp->data;
			}
			cp = cp->next;
		}
		return NULL;
	}
}

template <class T>
OrderedLinkedList<T> :: OrderedLinkedList(){

}

template <class T>
void OrderedLinkedList<T> :: display(){


	if(this->head == NULL){
		return ;
	}

	node<T> * cp = this->head;
	while(cp != NULL){
		cout<<cp->data<<endl;
		cp = cp->next;
	}
}

template <class T>
void OrderedLinkedList<T> :: display(node<T>* item){

	if(item == NULL){
		return ;
	}

	node<T> * cp = item;
	while(cp != NULL){
		cout<<cp->data<<endl;
		cp = cp->next;
	}
}

template <class T>
void OrderedLinkedList<T> :: insert(T& item){


	if(this->head==NULL){
		this->inserFirst(item);
		return ;
	}
	node<T> *newnode = new node<T>;
	newnode->data = item;
	newnode->next = NULL;
	node<T>* cp = this->head;
	node<T>* cp2 = NULL;
	while( cp != NULL){
		if(cp->data > newnode->data){

			if(cp2 != NULL){
				newnode->next = cp;
				this->display(newnode);
				cp2->next = newnode;
				cp = cp2;
			}
			else{
				this->head = newnode;
				this->head->next = cp;
			}

			break;

		}
		else if(cp->next == NULL){
			cp->next = newnode;
			break;
		}
		else{

			cp2 = cp;
			cp = cp->next;
		}
	}
}






template <class T>
OrderedLinkedList<T> :: ~OrderedLinkedList(){

}


#endif /* ORDEREDLINKEDLIST_H_ */
