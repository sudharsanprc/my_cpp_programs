#include "stdafx.h"
#include <iostream>
#include <string>
#include <string>
#include <cctype>

using namespace std;

void replace(char *a) {
	int number_of_spaces = 0;
	string str_replace = "%20";

	int x = strlen(a);
	int y = str_replace.size();

	// Find number of spaces in string

	for (int i = 0; i < x; i++) {

		if (isspace(a[i])){
			number_of_spaces++;
		}
	}

	// Calculate the new length of the string

	int new_length = x + number_of_spaces * 2;

	// replace the string from backward

	a[new_length] = '\0';
	new_length--;

	for (int count = x - 1; count >= 0; count--) {

		if (isspace(a[count])){
			a[new_length--] = '0';
			a[new_length--] = '2';
			a[new_length--] = '%';

		}
		else {
			a[new_length--] = a[count];
		}
	}

	cout << "The new string " << a << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char a[100] = " i like ntv";

	replace(a);

	cin.get();

	return 0;
}
