// linked_list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <climits>
#include <stack>

using namespace std;

// Class Declaration.
class Linked_List {
private:
	struct Node {
		int data;
		Node *next;
	};

	Node *curr, *temp, *head;

public:
	Linked_List();
	~Linked_List();
	void insert(int data, int position);
	void delete_node(int position);
	void print_List();
	void ispalindrome();
	void find_k_node(int node_index);
	void insert_new_node_in_sorted_list(int newdata);
	void printin_reverse_order();
};

class double_list {
private:
	struct dNode {
		int data;
		dNode *prev;
		dNode *next;
	};

	dNode *current, *temp2, *Head;

public:
	double_list();
	~double_list();
	void insert_node(int data, int position);
	void delete_dnode(int position);
	void print_dnode();
};

class circular_list {
private:
	struct cNode {
		int data;		
		cNode *next;
	};

	cNode *circular_current, *circular_temp2, *circular_Head;

public:
	circular_list();
	~circular_list();
	void insert_node_begin(int data);
	void insert_node_end(int data);
	void delete_dnode_begin();
	void delete_dnode_end();
	void print_dnode();
	void findlists_is_cyclic();

};

circular_list::circular_list() {
	circular_current = NULL;
	circular_temp2 = NULL;
	circular_Head = NULL;
}

circular_list::~circular_list() {
	
}

double_list::double_list() {
	current = NULL;
	temp2 = NULL;
	Head = NULL;
}

double_list::~double_list() {

}


Linked_List::Linked_List() {
	curr = NULL;
	temp = NULL;
	head = NULL;
}

Linked_List::~Linked_List() {

	curr = head;

	while (curr != NULL)
	{	
		temp = curr->next;		
		delete curr;
		curr = temp;
	}
	head = NULL;
}

void Linked_List::insert(int data, int position) {
	
	Node *newnode = new Node();
	newnode->data = data;
	newnode->next = NULL;
	int count=1;
	
	curr = head;

	if (!newnode) {
		cout << "Memory Error";
		return;
	}

	// Insert at the begining.
	if (position == 1) {
		newnode->next = head;
		head = newnode;
	}
	else {
		// Insert at any Position.
		while ((curr != NULL) && (count < position)) {
			count++;
			temp = curr;
			curr = curr->next;
		}
		temp->next = newnode;
		newnode->next = curr;
	}

	return;
}

void double_list::insert_node(int data, int position) {

	dNode *newnode = new dNode();
	newnode->data = data;

	int count = 1;

	// At the begining.
	if (position == 1) {

		if (Head) {
			newnode->next = Head;
			newnode->prev = NULL;
			Head->prev = newnode;
			Head = newnode;
			return;
		}
		else {
			newnode->next = NULL;
			newnode->prev = NULL;
			Head = newnode;
			return;
		}
	}
	else {

		current = Head;

		while ((current != NULL) && (count < position)) {
			count++;
			temp2 = current;
			current = current->next;
		}

		if (current == NULL) {
			cout << "Position Not Found" << endl;
		}		

		newnode->next = current;
		newnode->prev = temp2;	

		if (temp2->next)
			current->prev = newnode;
		
		temp2->next = newnode;
	}

}

void circular_list::insert_node_begin(int data) {

	cNode *newnode = new cNode();
	newnode->data = data;
	circular_current = circular_Head;
	while (circular_current->next != circular_Head) {
		circular_current = circular_current->next;
	}
	newnode->next = newnode;

	if (circular_Head == NULL) {
		circular_Head = newnode;
	}
	else {
		circular_current->next = newnode;
		newnode->next = circular_Head;			
	}
}

void Linked_List::delete_node(int position) {

	if (head == NULL) {
		cout << "List is Empty";
		return;
	}

	int count = 1;

	if (position == 1) {

		temp = head;
		head = temp->next;
		delete temp;
		return;
	}
	else {

		curr = head;

		while ((curr != NULL) && (count < position)) {

			temp = curr;
			curr = curr->next;
			count++;
		}

		if (curr == NULL) {
			cout << "Position Does not Exists" << endl;
		}
		else {

			temp->next = curr->next;
			delete curr;
		}
	}
}

void double_list::delete_dnode(int position) {

	if (Head == NULL) {
		cout << "List is Empty";
		return;
	}

	current = Head;
	temp2 = Head;
	int count = 1;

	if (position == 1) {
		Head = current->next;

		if (Head) {
			Head->prev = NULL;
		}
		delete temp2;
		return;
	}

	while ((current->next != NULL) && (count < position)) {

		temp2 = current;
		current = current->next;
		count++;
	}

	if (current == NULL) {  // At the end of  the Node.
		cout << "Position does not Exists"<<endl;
	}	

	temp2->next = current->next;
	temp2 = current->prev;

	if (current->next)  // Deleted middle element;
		current->next->prev = temp2;

	delete current;
	return;
}

void Linked_List::print_List() {

	Node *temp;
	temp = head;

	cout << "Print Linked List Elements:" << endl;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}	

	cout << endl;
}

void double_list::print_dnode() {

	dNode *temp2;
	temp2 = Head;

	cout << "Print Double Linked List Elements:" << endl;
	while (temp2 != NULL) {
		cout << temp2->data << " ";
		temp2 = temp2->next;
	}

	cout << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	Linked_List listobj;
	double_list dlobj;
	circular_list cobj;
	
	cout << "+-------------------------------------------------+" << endl;
	cout << "Linked List Operations" << endl;
	cout << "1.Insertion [ Begining, Middle, End ]" << endl;
	cout << "2.Deletion [ Begining, Middle, End ]" << endl;
	cout << "3.Double Linked List Insertion [ Begining, Middle, End ]" << endl;
	cout << "+-------------------------------------------------+" << endl;
	cout << "enter the options" << endl;
	int option = -1;
//	int data, position;
	cin >> option;
	switch (option) {
	case 1:
	{
		cout << "Linked List insertion. Enter the Data and Positon to be Inserted"<<endl;		
		listobj.insert(12, 1);
		listobj.print_List();
		listobj.insert(13, 1);
		listobj.print_List();
		listobj.insert(33, 1);
		listobj.print_List();
		listobj.insert(42, 1);
		listobj.print_List();
		listobj.insert(12, 1);
		listobj.print_List();
		listobj.insert(20, 4);
		listobj.print_List();
		listobj.insert(111, 20);
		listobj.print_List();

	//	cout << endl << "Check the List is Palindrome" << endl;;
	//	listobj.ispalindrome();

	//	listobj.find_k_node(3);

	//	listobj.insert_new_node_in_sorted_list(4);
	//	listobj.print_List();
	//	listobj.insert_new_node_in_sorted_list(21);
	//	listobj.print_List();

		listobj.printin_reverse_order();
	//	listobj.print_List();
		break;
	}
	case 2:
	{
		cout << "Linked List deletion. Enter the Data and Positon to be Deleted"<<endl;
		listobj.insert(5, 1);
		listobj.print_List();
		listobj.insert(7, 1);
		listobj.print_List();
		listobj.insert(8, 1);
		listobj.print_List();
		listobj.insert(10, 1);
		listobj.print_List();
		listobj.insert(11, 1);
		listobj.print_List();
		listobj.delete_node(20);
		listobj.print_List();


		break;
	}
	
	case 3:
	{
		cout << "Double Linked List Insertion" << endl;
		dlobj.insert_node(11, 1);
		dlobj.print_dnode();
		dlobj.insert_node(22, 1);
		dlobj.print_dnode();
		dlobj.insert_node(33, 1);
		dlobj.print_dnode();
		dlobj.insert_node(44, 1);
		dlobj.print_dnode();
		dlobj.insert_node(55, 1);
		dlobj.print_dnode();
		dlobj.insert_node(66, 1);
		dlobj.print_dnode();
		dlobj.insert_node(99, 4);
		dlobj.print_dnode();
		dlobj.insert_node(101, 8);
		dlobj.print_dnode();
		dlobj.delete_dnode(8);
		dlobj.print_dnode();
		dlobj.delete_dnode(4);
		dlobj.print_dnode();
		break;
	}
	case 4: 
	{
		cout << "Circular Linked List" <<endl;
	/*	cobj.insert_node_end(5);
		cobj.print_dnode();
		cobj.insert_node_end(7);
		cobj.print_dnode();
		cobj.insert_node_end(8);
		cobj.print_dnode();
		cobj.insert_node_end(10);
		cobj.print_dnode();
		cobj.insert_node_end(11);
		cobj.print_dnode();
		cobj.findlists_is_cyclic();*/
	}
	default:
		cout << "Unknown option. Exit";
	}
	
	cin >> option;
	return 0;
}

// Problems

// Print the linked list elements in reverse order.

void Linked_List::printin_reverse_order() {

	curr = NULL;
	temp = NULL;
	
	while (head) {
		curr = head->next;		
		head->next = temp;
		temp = head;
		head = curr;
	}

	// The temp pointer will be in last node. 
	// As point points to previous node, untill it reaches NULL, print the elements.

	cout << "Print Linked List Elements:" << endl;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}

// Insert the new node in the sorted ordered List
void Linked_List::insert_new_node_in_sorted_list(int newdata) {

	Node *newnode = new Node;
	newnode->data = newdata;
	newnode->next = NULL;

	curr = head;

	while ((curr != NULL) && (curr->data < newnode->data)) {
		temp = curr;
		curr = curr->next;
	}

	temp->next = newnode;
	newnode->next = curr;
}

void Linked_List::find_k_node(int node_index) {

	Node *nodeptr = NULL;
	curr = head;
	
	// Step 1: Move the current pointer till the node index count.
	for (int x = 1; x < node_index; x++) {

		if (curr)
		curr = curr->next;
	}
	
	while (curr)
	{
		if (nodeptr == NULL) {
			nodeptr = head;
		}
		else {
			nodeptr = nodeptr->next;
		}

		curr = curr->next;
	}

	if (nodeptr)
		cout << "The node Index data value" << nodeptr->data << endl;
	else
		cout << "The node not available" << endl;

}

void Linked_List::ispalindrome() {
	Node *slowptr, *fastptr;
	slowptr = fastptr = head;
	bool bstatus = true;

	stack<int> mystack;

	// Push all the elements into stack till we reach middle of the list

	while ((fastptr!=NULL) && (fastptr->next != NULL) )
	{
		mystack.push(slowptr->data);
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	}

	// If the list is odd, move one node forward. 
	// Just to make the center Node to compare.
	if (fastptr) {
		slowptr = slowptr->next;
	}

	while (slowptr != NULL) {

		int x = mystack.top();
		mystack.pop();

		if (x != slowptr->data) {			
			bstatus = false;
			break;
		}
		slowptr = slowptr->next;
	}

	if (bstatus == false) {
		cout << "The Linked is not Palindrome";
	}
	else {
		cout << "The List is palindrome"<<endl;
	}
}

void circular_list::findlists_is_cyclic() {

	cNode *slowptr, *fastptr;
	slowptr = fastptr = circular_Head;
	bool iscyclic = 0;

	while ((fastptr) && (fastptr->next)) {		
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
		if (slowptr == fastptr) {
			iscyclic = 1;
			break;
		}
	}

	if (iscyclic) {

		slowptr = circular_Head;

		while (slowptr != fastptr) {
			slowptr = slowptr->next;
			fastptr = fastptr->next;			
		}
		cout << "The Cyclic Node Data" << slowptr->data;
	}
	else {

		cout << "List is Not Cyclic" << endl;
	}

}
