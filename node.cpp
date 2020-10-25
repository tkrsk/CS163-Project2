//Taka Masagatani
//CS260
//Fall 2020
//Project 2
//cpp file for queue's linkedlist nodes
//node.cpp
#include "node.h"

using namespace std;

//Constructor
Node::Node(){
	next = nullptr;
}



//Desturctor
Node::~Node(){
	delete customer;
	next = nullptr;
}



//Accessors
Node* Node::get_next(){
	return next;
}



bool Node::signup(){
	return customer->is_signing();
}



char* Node::get_name(){
	return customer->get_customer();
}



char* Node::get_email(){
	return customer->get_email();
}



Customer* Node::get_cust(){
	return customer;
}



//Mutator
void Node::set_next(Node* parm){
	next = parm;
}



//New customer creation function
void Node::add_customer(){
	customer = new Customer;
	cout << "Please enter a name for the group:" << endl;
	char* name = strbuild(); //Name for group of customers
	customer->set_name(name);

	int size = 0; //Int for party size
	cout << "How many will be in your party?" << endl;
	cin >> size;
	
	while (!cin.good()){ //Checks for valid integer input
    	cin.clear();
	    cin.ignore();
		cout << "Please enter a valid number!" << endl;
		cout << "How many will be in your party?" << endl;
		cin >> size;
	}
	customer->set_size(size);

	bool special = false; //Check if party requires special seating
	int answer = 0; //Answer int
	
	cout << "Will you require special seating?\n(1)Yes\n(2)No" << endl;
	cin >> answer;

	while(!cin.good() && answer != 1 && answer != 2){
		cin.clear();
		cin.ignore();
		cout << "Please enter 1 or 2." << endl;
		cout << "Will you require special seating?\n(1)Yes\n(2)No" << endl;
		cin >> answer;
	}

	cin.ignore(); //Get rid of hanging newline
	
	if(answer == 1){
		cout << "Please tell me what kind of special seating your party requires:" << endl;
		char* seating = strbuild(); //Special seating type
		
		customer->set_seat(seating);

		delete [] seating;

		special = true;	
	}
	customer->set_spec(special);
	
	bool signup = false;
	answer = 0;
	
	cout << "Do you want to sign up for future promotions?\n(1)Yes\n(2)No" << endl;
	cin >> answer;

	while(!cin.good() && answer != 1 && answer != 2){ //Checks for valid integer input
		cin.clear();
		cin.ignore();
		cout << "Please enter 1 or 2." << endl;
		cout << "Do you want to sign up for future promotions?\n(1)Yes\n(2)No" << endl;
		cin >> answer;
	}

	cin.ignore(); //Get rid of hanging newline
	
	if(answer == 1){
		cout << "Please enter your name:" << endl;
		char* cust = strbuild();
		customer->set_cust(cust);

		cout << "Please enter the email we can reach you at for future promotions:" << endl;
		char* email = strbuild();
		customer->set_email(email);
		
		delete [] cust;
		delete [] email;

		signup = true;
	}
	customer->set_signup(signup);
}



void Node::print(){
	customer->get_info();
}



//My go-to cstring building function to save lines of code in other functions
char* Node::strbuild(){
	char buffer = '\0'; //Buffer char to append to end of cstring
	char * string = nullptr; //Buffer cstring to return to where function was called

	while(cin.peek() != '\n'){
		buffer = cin.get();
		
		if(string == nullptr){
			
			string = new char[2];
			
			string[0] = buffer;
			
			string[1] = '\0';
		}
		else{
			char * temp = new char[strlen(string) + 2]; //Temporary cstring to change output string to right size CArray
			
			strcpy(temp, string);
			
			temp[strlen(temp)] = buffer;
			
			temp[strlen(string) + 1] = '\0';
			
			delete [] string;
			
			string = temp;
		}
	}
	cin.ignore(); //clear buffer stream
	
	return string;
}
