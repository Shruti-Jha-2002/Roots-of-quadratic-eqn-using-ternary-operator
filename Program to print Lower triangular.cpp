Program to print Lower triangular

//code

#include<iostream>

using namespace std;

void lower(int matrix[3][3], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (i < j)
			{
				cout << "0" << " ";
			}
			else
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int matrix[3][3] = {{1, 2, 3},
						{4, 5, 6},
						{7, 8, 9}};
	int row = 3, col = 3;
	
	cout << "Lower triangular matrix: \n";
	lower(matrix, row, col);
		
	return 0;
}
