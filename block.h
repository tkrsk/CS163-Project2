#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class Block{
public:
//Constructor
	Block();
	Block(char* name, char* email);

//Destructor
	~Block();

//Accessors
	char* get_name();
	char* get_email();

private:
	char* cust_name;
	char* cust_email;
};
