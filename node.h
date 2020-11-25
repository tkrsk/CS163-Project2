#pragma once

#include <iostream>
#include <cstring>

#include "customer.h"

using namespace std;

class Node{
public:
//Constructor
	Node();

//Destructor
	~Node();

//Accessor
	Node* get_next();

	bool signup();
	
	char* get_name();
	
	char* get_email();

//Mutator
	void set_next(Node* parm);

	void set_group(char* group);

	void set_size(int size);

	void set_seat(char* seat);

	void set_signup(char* name, char* email);

//Customer Info Initialization
	void add_customer();

//Print
	void print();

private:
	Customer customer;
	Node* next;

//My go-to cstring building function
	char* strbuild(); 
};
