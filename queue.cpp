//Taka Masagatani
//CS260
//Fall 2020
//Project 2
//cpp file for queue adt
//queue.cpp
#include "queue.h" 

using namespace std;
//Constructor
Queue::Queue(){
	head = nullptr;
	tail = nullptr;
	line = 0;
}



//Destructor
Queue::~Queue(){
	while(head != nullptr){
		Node* temp = head->get_next();
		delete head;
		head = temp;
	}
	tail = nullptr;
	line = 0;
}



//Accessor
int Queue::get_count(){
	return line;
}



Node* Queue::get_head(){
	return head;
}



//Enqueue
void Queue::enqueue(){
	Node* add = new Node; //New group of customers

	add->add_customer();
	
	enqueue(add);
}



void Queue::enqueue(Node* parm){
	if(head == nullptr){
		head = parm;
	}
	else if(tail == nullptr){
		tail = parm;

		head->set_next(parm);
		
		tail->set_next(head);
	}
	else{
		Node* curr = head; //Temporary node for traversal
	
		while(curr != tail){
			curr = curr->get_next();
		}
		
		Node* temp = tail; //Temporary node for shifting
		
		temp->set_next(parm);
		
		tail = parm;
		
		parm->set_next(head);
	}

	line++;
}



//Dequeue
void Queue::dequeue(){
	if(head != nullptr) dequeue(head);
	else{
		cout << "No one is currently waiting!" << endl;
	}
}



bool Queue::dequeue(Node* parm){
	if(head->get_next() != nullptr){
		Node* curr = head->get_next();

		delete parm;
	
		head = curr;
		
		tail->set_next(curr);

		if(tail == head) tail = nullptr;
	}		
	else{
		delete head;

		head = nullptr;
	}
		line--;
		
}



//Peek
void Queue::peek(){
	if(head != nullptr) head->print();	
	else{
		cout << "No one is currently waiting!" << endl;
	}
}



//Display
void Queue::display(){
	if(head != nullptr) display(head);
	else{
		cout << "No one is currently waiting!" << endl;
	}
}



void Queue::display(Node* parm){
	if(parm == tail){ //Checks if last item in list
		parm->print();
		return;
	}
	else if(parm->get_next() == nullptr){ //Checks if only 1 item is in list
		parm->print();
		return;
	}
	parm->print();
	display(parm->get_next());
}



bool Queue::signup(){
	return head->signup();
}



char* Queue::get_name(){
	return head->get_name();
}



char* Queue::get_email(){
	return head->get_email();
}
