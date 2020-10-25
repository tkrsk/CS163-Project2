//Taka Masagatani
//CS260
//Fall 2020
//Project 2
//cpp file for customer class
//customer.cpp
#include "customer.h"

using namespace std;

//Constructors
Customer::Customer(){
	group_name = nullptr;
	group_size = 0;
	spec_seat = false;
	seat_type = nullptr;
	sign_up = false;
	cust_name = nullptr;
	cust_email = nullptr;
}



//Destructor
Customer::~Customer(){
	if(group_name != nullptr){
		if(group_name[0] != '\0'){
	  		for(int idx = 0; group_name[(idx) + 1] != '\0'; idx++) group_name[idx] = '\0';
		}	
		delete [] group_name;
		group_name = nullptr;
	}

	group_size = 0;

	if(seat_type != nullptr){
		if(seat_type[0] != '\0'){
	  		for(int idx = 0; seat_type[(idx) + 1] != '\0'; idx++) seat_type[idx] = '\0';
		}	
		delete [] seat_type;
		seat_type = nullptr;
	}

	if(cust_name != nullptr){
		if(cust_name[0] != '\0'){
	  		for(int idx = 0; cust_name[(idx) + 1] != '\0'; idx++) cust_name[idx] = '\0';
		}	
		delete [] cust_name;
		cust_name = nullptr;
	}

	if(cust_email != nullptr){
		if(cust_email[0] != '\0'){
	  		for(int idx = 0; cust_email[(idx) + 1] != '\0'; idx++) cust_email[idx] = '\0';
		}	
		delete [] cust_email;
		cust_email = nullptr;
	}
}



//Accessors
char* Customer::get_name(){
	return group_name;
}



int Customer::get_size(){
	return group_size;
}



bool Customer::is_special(){
	return spec_seat;
}



char* Customer::get_seat(){
	return seat_type;
}



bool Customer::is_signing(){
	return sign_up;
}



char* Customer::get_customer(){
	return cust_name;
}



char* Customer::get_email(){
	return cust_email;
}



//Mutators
void Customer::set_name(char* name){
	group_name = new char[strlen(name) + 1];
	strcpy(group_name, name);
}



void Customer::set_size(int size){
	group_size = size;
}



void Customer::set_spec(bool special){
	spec_seat = special;
}



void Customer::set_seat(char* seat){
	seat_type = new char[strlen(seat) + 1];
	strcpy(seat_type, seat);
}



void Customer::set_signup(bool signup){
	sign_up = signup;
}



void Customer::set_cust(char* cust){
	cust_name = new char[strlen(cust) + 1];
	strcpy(cust_name, cust);
}



void Customer::set_email(char* email){
	cust_email = new char[strlen(email) + 1];
	strcpy(cust_email, email);
}



//Print
void Customer::get_info(){
	cout << "---" << endl;
	
	cout << "Group Name: " << group_name << endl;
	
	cout << "Party Size: " << group_size << endl;
	
	cout << "Special Seating: ";
	
	if(spec_seat == false) cout << "No" << endl;
	else{
		cout << "Yes" << endl;
		cout << "Seat Type: " << seat_type << endl;
	}

	cout << "Signed Up for Newsletter: ";

	if(sign_up == false) cout << "No" << endl;
	else{
		cout << "Yes" << endl;
		cout << "Name: " << cust_name << endl;
		cout << "Email: " << cust_email << endl;
	}

	cout << "---" << endl;
}
