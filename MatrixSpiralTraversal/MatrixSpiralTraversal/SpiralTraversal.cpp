/**************************************************************************************
** Author: James Pool
** Website: https://jlevinpool.github.io/
** GitHub: https://github.com/jlevinpool/SpiralTraversal
** Date: 22 August 2016 (Start)
**
** Program Filename: SpiralTraversal.cpp
** Description: Non-recursive spiral traversal of a 2D matrix - Static and Dynamic
**************************************************************************************/

#include <iostream>
#include <stdio.h>

#define ROWS 3
#define COLS 4

/* Function Prototypes */
template <size_t nRows, size_t nCols> void spiralTraversalStatic(int (&array2D)[nRows][nCols]);
void spiralTraversalDynamic(int *array2D, size_t nRows, size_t nCols);

int main() {
	int arrStatic[ROWS][COLS] = { {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11} };  // Statically Declared Array
	int *arrDynamic;  // Dynamically Created Array (Flattened 2D array)
	int value = 0;  // Value for Dynamic Array

	/* Allocate Dynamic Array */
	// Reference: http://www.cplusplus.com/reference/new/bad_alloc/
	try {
		arrDynamic = new int[ROWS * COLS];  // Flattened 2D Array: Indexing Array[r][c] = Flat[COL * r + c]
	}
	catch (std::bad_alloc &ba) {
		std::cerr << "Error: Dynamic Array - " << ba.what() << '\n';
		return 1;
	}

	/* Populate Dynamic Array*/
	for (size_t i = 0; i < ROWS; i++) {
		for (size_t j = 0; j < COLS; j++) {
			arrDynamic[COLS * i + j] = value;  // Populate cell with value
			value++;
		}
	}

	/* Run Spiral Traversals */
	spiralTraversalStatic(arrStatic);
	spiralTraversalDynamic(arrDynamic, ROWS, COLS);

	/* Clean up Dynamic Array */
	delete[] arrDynamic;

	return 0;
}

/**************************************************************************************
**									spiralTraversalStatic
** Description: Prints a spiral traversal of the passed 2D matrix
** Input: pointer to 2D array (statically sized)
** Return: (none)
**************************************************************************************/
template <size_t nRows, size_t nCols> void spiralTraversalStatic(int(&array2D)[nRows][nCols]) {
	printf("--- Spiral Traversal: Static Array ---\nOriginal Array:\n");

	for (size_t i = 0; i < nRows; i++) {
		for (size_t j = 0; j < nCols; j++) {
			//std::cout << array2D[i][j] << " ";  // Print array contents
			printf("%*d", 4, array2D[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

/**************************************************************************************
**									spiralTraversalDynamic
** Description: Prints a spiral traversal of the passed 2D matrix
** Input: pointer to 2D array (dynamically sized)
** Return: (none)
**************************************************************************************/
void spiralTraversalDynamic(int *array2D, size_t nRows, size_t nCols) {
	printf("--- Spiral Traversal: Dynamic Array ---\nOriginal Array:\n");

	for (size_t i = 0; i < nRows; i++) {
		for (size_t j = 0; j < nCols; j++) {
			printf("%*d", 4, array2D[nCols * i + j]);  // Print array contents
		}
		printf("\n");
	}

	printf("\n");
}