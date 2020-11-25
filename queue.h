#pragma once

#include <iostream>
#include <cstring>
#include <fstream>

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

//Public data init
	void waitlist_init();

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

//Private data init
	void waitlist_init(char* file);

//Private Enqueue
	void enqueue(Node* parm);

//Private Dequeue
	bool dequeue(Node* parm);

//Display
	void display(Node* parm);

//String builder helper function
	char* strhelper(ifstream& ifile);
};
