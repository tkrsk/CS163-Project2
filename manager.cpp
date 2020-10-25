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
	if(waitlist->signup() == true){
		/*Customer* temp = waitlist->get_head()->get_cust();

		char* name = new char[strlen(temp->get_customer()) + 1];
		char* email = new char[strlen(temp->get_email()) + 1];

		strcpy(name, temp->get_customer());
		strcpy(email, temp->get_email());
*/
		char* name = new char[strlen(waitlist->get_name())];
		char* email = new char[strlen(waitlist->get_email())];

		strcpy(name, waitlist->get_name());
		strcpy(email, waitlist->get_email());
		
		promos->push(name, email);
	
		delete [] name;
		delete [] email;
	}

	waitlist->dequeue();
}



//Stack function to pop top of stack and append info to file
void Manager::pop(){
	promos->pop();
}



//Stack function that shows people that have yet to be emailed
void Manager::check(){
	promos->display();
}



//Stack function to show most recent item added to stack
void Manager::speek(){
	promos->peek();
}

