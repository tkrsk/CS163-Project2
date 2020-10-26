//Taka Masagatani
//CS260
//Fall 2020
//Project 2
//cpp file for queue and stack managing functions for app
//manager.cpp

#include "manager.h"

using namespace std;

//Constructor
Manager::Manager(){
	promos = new Stack;
	waitlist = new Queue;
}



Manager::Manager(int parm){ 
	promos = new Stack(parm);
	waitlist = new Queue;
}



//Destructor
Manager::~Manager(){
	delete promos;
	delete waitlist;
}



//User interface function to clean clutter from app module
void Manager::start(){
	data_init();

	int command;

	cout << "(0) To Exit\n(1) Show next group.\n(2) Show all groups waiting\n(3) Add new group to waitlist\n(4) Seat next group" << endl;
	cout << "(5) Show most recent customer to sign up\n(6) Show all customers who have not received an email yet\n(7) Send email to most recent customer to sign up" << endl;
	cout << "What would you like to do?" << endl;
	cin >> command;
	while (!cin.good()){ //Checks for valid integer input
    	cin.clear();
	    cin.ignore();
		cout << "Please enter a valid number!" << endl;
		cin >> command;
	}
	cin.ignore();

	while(command > 0 && command <= 6){
		while (!cin.good()){ //Checks for valid integer input
    		cin.clear();
	    	cin.ignore();
			cout << "Please enter a valid number!" << endl;
			cin >> command;
		}
		if(command == 1){
			peek();
		}

		else if(command == 2){
			waiting();
		}

		else if(command == 3){
			enqueue();
		}

		else if(command == 4){
			dequeue();
		}

		else if(command == 5){
			speek();
		}
		
		else if(command == 6){
			check();
		}

		else if(command == 7){
			pop();
		}

		cout << "(1) Show next group.\n(2) Show all groups waiting\n(3) Add new group to waitlist\n(4) Seat next group" << endl;
		cout << "(5) Show most recent customer to sign up\n(6) Show all customers who have not received an email yet\n(7) Send email to most recent customer to sign up" << endl;
		cout << "What would you like to do?" << endl;
		cin >> command;
		cin.ignore();
	}
	cout << "Good Bye!" << endl;
}



//Queue data init function
void Manager::data_init(){
	waitlist->waitlist_init();
}



//Queue function to add to waitlist
void Manager::enqueue(){
	waitlist->enqueue();
}



//Queue function to show next in line
void Manager::peek(){
	waitlist->peek();	
}



//Queue function to show waitlist
void Manager::waiting(){
	cout << "Group(s) currently waiting: " << waitlist->get_count() << endl;
	
	waitlist->display();
}


//Queue and stack function to dequeue from queue and push to stack if customer wants to sign up for promos
void Manager::dequeue(){
	if(waitlist->get_head() == nullptr){
		cout << "There are no customers waiting to be seated!" << endl;
		return;
	}
	else if(waitlist->signup() == true){
		
		char* name = new char[strlen(waitlist->get_name()) + 1];
		char* email = new char[strlen(waitlist->get_email()) + 1];

		strcpy(name, waitlist->get_name());
		strcpy(email, waitlist->get_email());
		
		promos->push(name, email);
	
		delete [] name;
		delete [] email;
	}
	cout << "Seating next group!" << endl;

	waitlist->dequeue();
}



//Stack function to pop top of stack and append info to file
void Manager::pop(){
	bool popped = promos->pop();
	if(popped == true) cout << "Email sent!" << endl;
	else{
		cout << "No emails pending!" << endl;
	}
}



//Stack function that shows people that have yet to be emailed
void Manager::check(){
	promos->display();
}



//Stack function to show most recent item added to stack
void Manager::speek(){
	promos->peek();
}

