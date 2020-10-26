//Taka Masagatani
//CS260
//Fall 2020
//Project 2
//cpp file for stack adt
//stack.cpp
#include "stack.h"

using namespace std;

Stack::Stack(){
	capacity = init_size;
	
	top = 0;
	
	stack = new Block*[capacity];
	
	for(int i = 0; i < capacity; i++){
		stack[i] = nullptr;
	}
}



Stack::Stack(int size){
	capacity = size;
	
	top = 0;

	stack = new Block*[capacity];

	for(int i = 0; i < capacity; i++){
		stack[i] = nullptr;
	}
}



//Destructor
Stack::~Stack(){
	destroy();
}



void Stack::destroy(){
	for(int i = 0; i < top; i++) {
		if(stack[i]) delete stack[i];
	}
	if(stack) delete [] stack;
}



//Expand function
void Stack::expand(){
	capacity *= GROWTH;
	Block ** temp = new Block*[capacity];
	for(int i = 0; i < top; i++){
		temp[i] = stack[i];
	}
	delete [] stack;
	stack = temp;
}



//Pop function
bool Stack::pop(){
	if(is_empty()){
		return false;
	}

	write(stack[top - 1]);
	
	delete stack[top - 1];

	top--;

	return true;
}



//Push function
void Stack::push(char* name, char* email){
	Block* temp = new Block(name, email);

	if(capacity == top){
		expand();
	}
	stack[top] = temp;
	
	top++;
}



//Peek function
void Stack::peek(){
	if(is_empty() == false){
		cout << "Name: " << stack[top - 1]->get_name() << endl;
		cout << "Email: " << stack[top - 1]->get_email() << endl;
	}
	else{
		cout << "No one waiting to receive emails!" << endl;
	}
} 



//Display function
void Stack::display(){
	if(is_empty() == false){
		cout << "Customers not yet emailed: " << capacity << endl;
		for(int i = 0; i < top; i++){
			cout << "\n-" << i + 1 << "-" << endl;
			cout << "Name: " << stack[i]->get_name() << endl;
			cout << "Email: " << stack[i]->get_email() << endl;
			cout << "---\n" << endl;
		}
	}
	else{
		cout << "No one waiting to receive emails!" << endl;
	}
}



//Function to write to data file
void Stack::write(Block* parm){
	ofstream output;
	output.open("newsletter.txt", ios_base::app);
	
	output << "Name: " << parm->get_name() << endl;
	output << "Email: " << parm->get_email() << endl;
	output << endl;
}



//Function to check for stack underflow
bool Stack::is_empty(){
	return top == 0;
}
