//Taka Masagatani
//CS260
//Fall 2020
//Project 2
//Header file for customer class
//customer.h
#pragma once

#include <iostream>
#include <cstring>

using namespace std;
class Customer{
public:
//Constructor
	Customer();
	Customer(char* name, int size, bool special, bool signup);

//Destructor
	~Customer();

//Accessors
	char* get_name();
	int   get_size();
	bool  is_special();
	char* get_seat();
	bool  is_signing();
	char* get_customer();
	char* get_email();	

//Mutators
	void set_name(char* name);
	void set_size(int size);
	void set_spec(bool special);
	void set_seat(char* seat);
	void set_signup(bool signup);
	void set_cust(char* cust);
	void set_email(char* email);

//Print
	void get_info();

private:
	char* group_name;
	int	  group_size;
	bool  spec_seat;
	char* seat_type;
	bool  sign_up;
	char* cust_name;
	char* cust_email;
};
