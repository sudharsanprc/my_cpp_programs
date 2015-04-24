// Anagram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void anagram(string input){
	sort(input.begin(), input.end());
	do
		cout << input << endl;
	while (next_permutation(input.begin(), input.end()));
}

void combinations(int depth, char *b, int start, char *a) {

	int len = strlen(a);

	for (int x = start; x<len; x++) {

		b[depth] = a[x];
		b[depth + 1] = '\0';
		cout << b << endl;
		if (x < len - 1) {
			combinations(depth + 1, b, start + 1, a);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	string arr = "Adavaitha";
	anagram(arr);

	char a[] = "Perception";

	int length = strlen(a);

	int start = 0;
	int depth = 0;
	char b[100];

//	combinations(depth, b, start, a);
	cin.get();
	return 0;
}
