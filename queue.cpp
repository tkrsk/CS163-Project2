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



//Public Data initialization
void Queue::waitlist_init(){
	waitlist_init("waitlist.txt");
}



//Private Data initialization
void Queue::waitlist_init(char* file){
	ifstream infile;

	infile.open(file);
	
	while(infile.peek() != '~'){
		Node* add = new Node;
		
		char* group = nullptr;; 
		group = strhelper(infile);
		if(infile.peek() == '\n') infile.get();
	
		add->set_group(group);

		delete [] group;

		int size, special, signup;
				
		infile >> size;
		infile.ignore();

		add->set_size(size);

		infile >> special;
		infile.ignore();

		char* seat = nullptr;

		if(special == 1){
			seat = strhelper(infile);
			if(infile.peek() == '\n') infile.get();
			
			add->set_seat(seat);

			delete [] seat;
		}
		
		infile >> signup;
		infile.ignore();

		char* name = nullptr;
		char* email = nullptr;

		if(signup == 1){
			name = strhelper(infile);
			if(infile.peek() == '\n') infile.get();
			
			email = strhelper(infile);
			if(infile.peek() == '\n') infile.get();
	
			add->set_signup(name, email);

			delete [] name;
			delete [] email;
		}

		enqueue(add);
	}

}



//Public Enqueue
void Queue::enqueue(){
	Node* add = new Node; //New group of customers

	add->add_customer();
	
	enqueue(add);
}



//Private Enqueue
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
	if(head == tail){
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else{
		Node* curr = head->get_next(); //Placeholder node

		delete head;
	
		head = curr;
		
		tail->set_next(head);
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
		cout << "---" << endl;
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



char* Queue::strhelper(ifstream& ifile){
	char buffer = '\0'; //Buffer char to append to end of cstring
	char * string = nullptr; //Buffer cstring to return to where function was called

	while(ifile.peek() != ';'){
		buffer = ifile.get();
		
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
	ifile.ignore(); //clear buffer stream
	
	return string;
}
