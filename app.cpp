//Taka Masagatani
//CS260
//Fall 2020
//Project 2
//cpp file for main program
//app.cpp

#include "app.h"

using namespace std;

int main(int argc, char** argv, char** envp){
	int init = 3;
	Manager program(init);
	
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
			program.peek();
		}

		else if(command == 2){
			program.waiting();
		}

		else if(command == 3){
			program.enqueue();
		}

		else if(command == 4){
			program.dequeue();
		}

		else if(command == 5){
			program.speek();
		}
		
		else if(command == 6){
			program.check();
		}

		else if(command == 7){
			program.pop();
		}

		cout << "(1) Show next group.\n(2) Show all groups waiting\n(3) Add new group to waitlist\n(4) Seat next group" << endl;
		cout << "(5) Show most recent customer to sign up\n(6) Show all customers who have not received an email yet\n(7) Send email to most recent customer to sign up" << endl;
		cout << "What would you like to do?" << endl;
		cin >> command;
		cin.ignore();
	}
	cout << "Good Bye!" << endl;
}
