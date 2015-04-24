// lonely_number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <array>

using namespace std;

//int lonely_integer(std::vector<int> pairs);

int lonely_integer(std::vector<int> elements) {
	
	int value = -1;
	int counter = 0;

	std::array<int, 99> numbers;
	
	numbers.fill(0);
	
	int yy = 0;

	for (int x = 0; x<elements.size(); x++) {

		yy = numbers[elements[x]];

		numbers[elements[x]] = ++yy;
	}


	for (int &x : numbers) {
		if (x == 1) {
			break;
		}
		counter++;
	}

	return counter;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int no_of_elements;
	vector<int> pairs;
	int number;
	int value;
	value = -1;

	cin >> no_of_elements;
	
	assert(no_of_elements >= 1 && no_of_elements < 100);
	int temp = no_of_elements % 2;
	assert(temp != 0);

	for (int x = 0; x < no_of_elements; x++) {

		cin >> number;
		if (x == 0) {
			value = number;
		}
		else {
			value = value ^ number;
		}		
		//pairs.push_back(number);
	}



/*	for (int x = 0; x<pairs.size(); x++) {		

		if (x == 0){
			value = pairs[x];			
		}
		else {
			value = value ^ pairs[x];
		}
				
	}*/

//	int value = lonely_integer(pairs);

	cin.clear();
	cin.sync();
	
	cout <<value<<endl;

	cin.get();
	
	
	return 0;
}

