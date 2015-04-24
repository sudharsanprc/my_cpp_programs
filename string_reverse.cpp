// string_operation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

/*

void strreverse( char *a) {

	char *temp = NULL;

	int len = strlen(a);
	temp = new char(len+1);
	temp = strcpy(temp,a);

	for (int count = 0; count < (len / 2); count++) {

		swap(temp[count], temp[len - count - 1]);
	}
	
	cout << *temp << endl;
}*/

int _tmain(int argc, _TCHAR* argv[])
{
	// your code goes here
	char a[50] = "Shiva Shamboo";
	char temp;
	int start = 0, end = 0, count = 0;
	int len;
	len = strlen(a);

	for (count = 0; count<len/2; count++) {
		swap(a[count], a[len - count - 1]);
	}

	cout << a;
	// Again reverse each individual word

	int temp_start;
	int temp_end;

	while (start<len) {

		if (a[end] != ' ' && a[end] != '\0') {
			end++;
		}
		else {
			
			temp_start = start;
			temp_end = end-1;
			for (count = temp_start; count < temp_end; count++) {
				temp = a[count];
				a[count] = a[temp_end];
				a[temp_end] = temp;
				temp_end--;
			}
			end++;
			start = end;
		}
	}

	cout << a;
	return 0;
}

