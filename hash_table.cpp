// Hashtable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class hashtable {
private:

	static int const tablesize = 10;

	struct listnode {
		int data;
		int key;
		listnode *next;
	};

	listnode *Hashtable[tablesize];

public:
	hashtable();
	~hashtable();
	void addelement(int data);
	void searchelement(int data);
	void delete_element(int data);
	void print_element();
	int number_of_items(int index);
	int hashfun(int data);
	bool search(int data);
};

hashtable::hashtable() {

	for (int x = 0; x < tablesize; x++) {
		Hashtable[x] = new listnode;
		Hashtable[x]->data = NULL;
		Hashtable[x]->key = NULL;
		Hashtable[x]->next = NULL;
	}
}

hashtable::~hashtable() {

}

bool hashtable::search(int data) {

	int key = 0;
	bool found = false;
	key = hashfun(data);

	listnode *ptr = Hashtable[key];

	// 1. 0 Base Condition

	if (Hashtable[key]->data == data) {

		found = true;
	}
	else {

		while ((ptr->next != NULL)) {

			if (ptr->data == data) {
				found = true;
				break;
			}

			ptr = ptr->next;
		}

		if (ptr->data == data) {
			found = true;
		}

	}

	if (found == true) {

		cout << "Found the Data : " << data << endl;
		return true;
	}
	else {
		cout << "Unable to Found the Data : " << data << endl;
		return false;
	}

}


int hashtable::hashfun(int data) {

	hashtable hashobj;

	int  hindex = data % hashobj.tablesize;
	return hindex;
}

void hashtable::delete_element(int data) {

	int key = hashfun(data);

	listnode *delptr,*p1, *p2;

	// Case 1 - Tabele is empty

	if (Hashtable[key]->data == NULL) {
		cout << "Element not found in Hash Table" << endl;
		return;
	}

	// case 2 - Table index has one element and matching element

	if ((Hashtable[key]->data == data) && (Hashtable[key]->next == NULL)) {

		Hashtable[key]->data = NULL;
		Hashtable[key]->key = NULL;
		delete Hashtable[key];
		return;
	}

	// Case 3 - Table has multiple element and first element is matched.

	if ((Hashtable[key]->data == data) && (Hashtable[key]->next != NULL)) {

		listnode *ptr = Hashtable[key];
		delptr = ptr;
		ptr = ptr->next;
		delete delptr;		
		return;
	}
	else  {

		// Case 4 - Table has multiple element and match found . 

		p1 = Hashtable[key]->next;
		p2 = Hashtable[key];

		while ((p1 != NULL) && (p1->data != data)) {
			p2 = p1;
			p1 = p1->next;			
		}

		if (p1 != NULL) {
			delptr = p1;
			p1 = p1->next;
			p2->next = p1;
			delete delptr;
		}
		else {

			cout << "Match not found" << endl;
		}
	}

}

void hashtable::addelement(int data) {

	int index = hashfun(data);

	if (Hashtable[index]->data == NULL) {

		Hashtable[index]->data = data;
		Hashtable[index]->key = index;
		Hashtable[index]->next = NULL;
	}
	else {

		listnode *ptr = Hashtable[index];
		listnode *newnode = new listnode;
		newnode->data = data;
		newnode->key = index;
		newnode->next = NULL;

		while (ptr->next != NULL) {
			ptr = ptr->next;
		}

		ptr->next = newnode;
	}

}

int hashtable::number_of_items(int index) {

	int count = 0;

	if (Hashtable[index]->data == NULL) {

		return count;
	}
	else {

		listnode *ptr = Hashtable[index];

		count = 1;

		while (ptr->next != NULL) {
			count++;
			ptr = ptr->next;
		}
		return count;
	}

}

void hashtable::print_element() {

	for (int i = 0; i < tablesize; i++) {

		listnode *ptr = Hashtable[i];

		while (ptr->next != NULL) {

			cout << ptr->data << "  ";
			ptr = ptr->next;
		}

		cout << ptr->data << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	hashtable hashobj;
	int data = 5;
	hashobj.addelement(25);
	hashobj.addelement(60);
	hashobj.addelement(70);
	hashobj.addelement(80);
	hashobj.addelement(22);
	hashobj.addelement(47);
	hashobj.addelement(51);
	hashobj.addelement(32);
	int g = hashobj.number_of_items(0);
	hashobj.print_element();
	bool x = hashobj.search(80);
	x = hashobj.search(60);
	x = hashobj.search(70);
	x = hashobj.search(45);
	hashobj.delete_element(80);
	hashobj.print_element();
	cin.get();
	return 0;
}

