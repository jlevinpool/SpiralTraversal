/**************************************************************************************
** Author: James Pool
** Website: https://jlevinpool.github.io/
** GitHub: https://github.com/jlevinpool/SpiralTraversal
** Date: 22 August 2016
**
** Program Filename: SpiralTraversal.cpp
** Description: Non-recursive spiral traversal of a 2D matrix
**************************************************************************************/

#include <iostream>

/* Function Prototypes */
template <size_t nRows, size_t nCols> void spiralTraversal(int (&array2D)[nRows][nCols]);

int main() {
	int arr[3][3] = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };

	spiralTraversal(arr);

	return 0;
}

/**************************************************************************************
**									spiralTraversal
** Description: Prints a spiral traversal of the passed 2D matrix
** Input: pointer to 2D array (static sized)
** Return: (none)
**************************************************************************************/
template <size_t nRows, size_t nCols> void spiralTraversal(int(&array2D)[nRows][nCols]) {
	
	for (size_t i = 0; i < nRows; i++) {
		for (size_t j = 0; j < nCols; j++) {
			std::cout << array2D[i][j] << " ";  // Print array contents
		}
		std::cout << std::endl;
	}
}