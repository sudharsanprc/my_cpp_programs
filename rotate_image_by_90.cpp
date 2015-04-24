// rotate_image_90.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	int a[4][4];

	// Dimension of matrix;
	int N = 4;

	// Fill the elements into the Matrix

	int count = 0;

	for (int iRow = 0; iRow < 4; iRow++){

		for (int iCol = 0; iCol < 4; iCol++) {
			a[iRow][iCol] = ++count;
			cout << a[iRow][iCol]<<"  ";
		}
		cout << endl;
	}

	count = 0;

	cout << endl << endl;

	// Rotate the matrix by each pixel

	int temp = -1;

	for (int X = 0; X< N / 2; X++) {

		for (int Y = 0; Y < (N + 1) / 2; ++Y) {
			// Copy the top most element (0,0)
			temp = a[X][Y];
			
			//Move left to top		( (3,0) -> (0,0) )
			a[X][Y] = a[N - 1 - Y][X];

			// Move bottom to left	((3,3) -> (3,0))	
			a[N - 1 - Y][X] = a[N - 1 - X][N - 1 - Y];
			
			// Move Right to bottom((0,3) -> (3,3))
			a[N - 1 - X][N - 1 - Y] = a[Y][N - 1 - X];

			// Move temp to Right

			a[Y][N - 1 - X] = temp;

		}
	}

	for (int iRow = 0; iRow < 4; iRow++){

		for (int iCol = 0; iCol < 4; iCol++) {			
			cout << a[iRow][iCol] << "  ";
		}
		cout << endl;
	}

	cout << "";

	cin.clear();
	cin.get();

	return 0;
}

