/*
**************************************
** This program solves an equation  **
** using Gaussian Elimination method**
** This solution works on c++11     **
**************************************
*/


#include <iostream>
using namespace std;

//The column size is declared as 4, solving 3 by 3 matrices in the augmented form
const int MAX_COLUMN_SIZE = 4;

//This function helps us display the matrix
void display(double arr[][MAX_COLUMN_SIZE], int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout<<arr[i][j]<<"    ";
		}
		cout<<endl;
	}
	
}

//This function helps us swap two rows of a matrix when we have dividing by zero case
void swap(double arr[][MAX_COLUMN_SIZE], int swappedRow, int rows, int columns)
{
	int swappingRow = swappedRow + 1;
	while (swappingRow < rows)
	{
		if (arr[swappingRow][swappedRow] != 0)
		{
			for (int i = 0; i < columns; i++)
			{
				double temp = arr[swappedRow][i];
				arr[swappedRow][i] = arr[swappingRow][i];
				arr[swappingRow][i] = temp;
			}
			break;
		}
	}
}

//This function changes matrixes to REF form using Gaussian Elimination
void toREF(double arr[][MAX_COLUMN_SIZE], int rows, int columns)
{
	for (int n = 0; n < rows - 1; n++)
	{ 
		if (arr[n][n] == 0)
		{
			swap(arr, n, rows, columns);
		}
		if (arr[n][n] == 0)
		{
			continue;
		}
		
		//from the next row to the end row, we do pivoting process
		for (int i = n + 1; i < rows; i++) 
		{
			double ratio = arr[i][n]/arr[n][n];  
			
			//for each column in the specific row
			for (int j = 0; j < columns; j++) 
			{
				arr[i][j] -= ratio * arr[n][j];
			}
		}
	}
}

//This function helps us find out the solutions
void findSolution(double arr[][MAX_COLUMN_SIZE], int rows, int columns)
{
	//Assigning solutions array to hold the solutions for each variable
	double solutions[columns - 1];
	
	//j refers to the last variable initially
	int j = columns - 2;
	
	for (int i = rows - 1; i >= 0; i--)
	{
		//this variable keeps track of the sums in other variables in the same row
		double sumOfOtherVariables = 0;
		
		//This loop does back-substitution
		for (int k = j + 1; k < columns - 1; k++)
		{
			sumOfOtherVariables += solutions[k] * arr[i][k];
		}
		
		//The solution to the last variable
		solutions[j] = (arr[i][columns-1] - sumOfOtherVariables)/arr[i][j];
		
		//we decrement j in order to proceed to the next variable
		j--;
	}
	
	cout<<"The solutions are: "<<endl;
	cout<<"\t x : "<<solutions[0]<<endl;
	cout<<"\t y : "<<solutions[1]<<endl;
	cout<<"\t z : "<<solutions[2]<<endl;
}



int main()
{
	//Example usage
    double input[3][4] = {
    	{4, -1, 2, 15}, 
		{-1, 2, 3, 5}, 
		{5, -7, 9, 8}
	};
//	double input[3][4] = {
//		{0,2,3,10},
//		{4,0,1,10},
//		{2,0,1,10}
//	};

	toREF(input, 3, 4);
	display(input, 3, 4);
	findSolution(input, 3, 4);
	return 0;
}
