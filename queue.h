//Taka Masagatani
//CS260
//Fall 2020
//Project 2
//Header file for queue adt
//queue.h

#pragma once

#include <iostream>
#include <cstring>

#include "node.h"

using namespace std;

class Queue{
public:
//Constructor
	Queue();

//Destructor
	~Queue();

//Accessor
	int get_count();
	Node* get_head();

//Peek
	void peek();

//Public enqueue function
	void enqueue();

//Public dequeue function
	void dequeue();

//Public display function
	void display();

//Sign up check
	bool signup();

//Get sign up values
	char* get_name();
	char* get_email();

private:
	Node* head;
	Node* tail;
	int line;

//Enqueue
	void enqueue(Node* parm);

//Dequeue
	bool dequeue(Node* parm);

//Display
	void display(Node* parm);
};
