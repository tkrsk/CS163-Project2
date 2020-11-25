#include "block.h"

using namespace std;

//Constructor
Block::Block(){
	cust_name = nullptr;
	cust_email = nullptr;
}



Block::Block(char* name, char* email){
	cust_name = new char[strlen(name) + 1];
	cust_email = new char[strlen(email) + 1];

	strcpy(cust_name, name);
	strcpy(cust_email, email);
}



//Destructor
Block::~Block(){
	if(cust_name != nullptr) delete [] cust_name;
	if(cust_email != nullptr) delete [] cust_email;
}



//Accessors
char* Block::get_name(){
	return cust_name;
}



char* Block::get_email(){
	return cust_email;
}
