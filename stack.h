//Taka Masagatani
//CS260
//Fall 2020
//Project 2
//Header file for stack adt
//stack.h

#pragma once

#include <iostream>
#include <cstring>
#include <fstream>

#include "queue.h"
#include "block.h"

using namespace std;

class Stack{
public:
//Constructor
	Stack();
	Stack(int parm);

//Destructor
	~Stack();

//Accessors

//Expand
	void expand();

//Pop
	bool pop();

//Push
	void push(char* name, char* email);

//Peek
	void peek();

//Display
	void display();

//Write to database
	void write(Block* parm);

//Check for stack underflow
	bool is_empty();

private:
	int capacity,
		top;
	const static int init_size = 3;
	const static int GROWTH = 2;
	
	Block** stack;

	
//Destroy function	
	void destroy();
};
