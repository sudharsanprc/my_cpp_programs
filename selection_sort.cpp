// selection_sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void selection_sort(int a[], int no_of_elements) {

	int min, j, temp;

	for (int x = 0; x < (no_of_elements - 1); x++) {

		min = x;

		for (j = x + 1; j < no_of_elements; j++) {

			if (a[j] < a[min]) {
				min = j;
			}
			temp = a[x];
			a[x] = a[min];
			a[min] = temp;
		}
	}
}

void bubble_sort(int a[], int n) {

	int temp;
	bool flag = 0;
	for (int x = 0; x < n - 1; x++) {

		for (int j = x + 1; j < n; j++) {

			if (a[j] < a[x]) {
				temp = a[j];
				a[j] = a[x];
				a[x] = temp;
			}
		}
	}

}

void bubble_sort_refined(int a[], int n) {

	int temp;
	bool flag = 1;
	for (int x = n - 1; (x >= 0 && flag); x--) {

		flag = 0;

		for (int j = 0; j <= (x - 1); j++) {

			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
		}
	}

}

void insertion_sort(int a[], int n) {

	int value, position;

	for (int i = 1; i <= n - 1; i++) {

		value = a[i];
		position = i;

		while ((position > 0) && (a[position - 1] > value)) {

			a[position] = a[position - 1];
			//a[position - 1] = value;
			position--;
		}

		a[position] = value;
	}

}

void merge(int a[], int left_end, int mid, int right_end) {

	int temp[5];
	int k = left_end;
	int i = left_end;
	int j = mid + 1;

	// Compare with left and right sub list and copy the elements.

	while ((i <= mid) && (j <= right_end)) {
		if (a[i] < a[j]) {
			temp[k] = a[i];
			k++;
			i++;
		}
		else {
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= right_end) {
		temp[k] = a[j];
		k++;
		j++;
	}

	for (int x = left_end; x < k; x++) {
		a[x] = temp[x];
	}
}

void mergesort(int a[], int left, int right) {
	int mid;

	// Calculate the mid Value

	if (left < right) {

		mid = (left+right)/2;		
		mergesort(a,left,mid);
		mergesort(a,mid+1,right);		
		merge(a,left, mid, right);
	}

}




int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 5, 3, 2, 4, 1 };
	//selection_sort(a, 5);
	//bubble_sort(a, 5);
	//bubble_sort_refined(a, 5);
	//insertion_sort(a, 5);
	mergesort(a,0,4);
	//Print the elements

	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}

	cin.clear();
	cin.get();

	return 0;
}


