//Taka Masagatani
//CS260
//Fall 2020
//Project 2
//Header file for queue and stack functions for app
//manager.h

#include <iostream>
#include <cstring>
#include <fstream>

#include "customer.h"
#include "node.h"
#include "queue.h"
#include "stack.h"

using namespace std;

class Manager{
public:
//Constructor
	Manager();
	Manager(int parm);

//Destructor
	~Manager();

//UI function
	void start();

//Queue Managing functions
	void data_init(); //Reads in data file to queue
	void enqueue(); //Allows user the add to queue
	void dequeue(); //This function will dequeue and push to stack
	void peek(); //Function to show next in line
	void waiting(); //Display everyone in line

//Stack Managing functions
	void pop(); //This will remove top of stack and append to file.
	void check(); //Show all items in stack
	void speek(); //Show top item of stack

private:
	Stack* promos;
	Queue* waitlist;
};
