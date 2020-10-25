//Taka Masagatani
//CS260
//Fall 2020
//Project 2
//Header file for queue's linkedlist nodes
//node.h
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

	Customer* get_cust();

//Mutator
	void set_next(Node* parm);

//Customer Info Initialization
	void add_customer();

//Print
	void print();

private:
	Customer* customer;
	Node* next;

	//My go-to cstring building function
	char* strbuild(); 
};
