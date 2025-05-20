//**************************************************************
// Matrix
//William Pierce
//***************************************************************
// This program creates a dynamically allocated 2D matrix to store
// Social Security Numbers for Tiny Ville residents. The matrix
// size is determined by user input. The SSNs are randomly
// generated between 1000 and 5999. The program includes:
// 1. A function to count SSNs in ranges 
// 2. A function to count genders 
// The output includes the matrix and summaries for SSNs and genders.
//
// To run: Compile and execute in Visual Studio. Do as the promops guides.
//*****************************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes (more details for each fx is giving at its definition)
int** createMatrix(int size);
void deleteMatrix(int** matrix, int size);
void printMatrix(int** matrix, int size);
void summarizeSSNs(int** matrix, int size);
void summarizeGenders(int** matrix, int size);

//*******************************************************************
// Function: main
// Parameters: None
// Returns: int - program termination
// Description: Prompts user for matrix size, creates and fills the
// matrix with random SSNs, calls functions to print matrix and
// summarizes.
//*******************************************************************
int main() {
    int size;

    // Get matrix size from user
    cout << "Enter the size of the square matrix: ";
    cin >> size;

    // Validate input
    if (size <= 0) {
        cout << "Invalid size. Please enter a positive integer." << endl;
        return 1;
    }

    // Create and fill matrix
    int** matrix = createMatrix(size);

    // Print matrix
    printMatrix(matrix, size);

    // Summarize SSNs
    summarizeSSNs(matrix, size);

    // Summarize genders
    summarizeGenders(matrix, size);

    // Deallocate matrix
    deleteMatrix(matrix, size);

    return 0;
}

//*******************************************************************
// Function: createMatrix
// Parameters: int size - the dimension of the square matrix
// Returns: int** - pointer to the dynamically allocated 2D matrix
// Description: Allocates a 2D matrix of given size and fills it with
// random SSNs between 1000 and 5999 as suggested in hw description.
//*******************************************************************
int** createMatrix(int size) {
    // Allocate array of pointers
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    // random number generator
    srand(time(0));

    // Fill matrix with random SSNs
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 1000 + (rand() % 5000); // Random number between 1000 and 5999
        }
    }
    return matrix;
}

//*******************************************************************
// Function: deleteMatrix
// Parameters: int** matrix - the 2D matrix to delete the dynamic memory
//             int size - the dimension of the square matrix
// Returns: void
// Description: Deallocates the dynamically allocated 2D matrix.
//*******************************************************************
void deleteMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

//*******************************************************************
// Function: printMatrix
// Parameters: int** matrix - the 2D matrix to print
//             int size - the dimension of the square matrix
// Returns: void
// Description: Prints the matrix in a formatted grid.
//*******************************************************************
void printMatrix(int** matrix, int size) {
    cout << "The Matrix:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

//*******************************************************************
// Function: summarizeSSNs
// Parameters: int** matrix - the 2D matrix containing SSNs
//             int size - the dimension of the square matrix
// Returns: void
// Description: Counts and displays the number of SSNs in each 1000s
// range (1000s, 2000s, etc.) and the total number of habitants.
//*******************************************************************
void summarizeSSNs(int** matrix, int size) {
    int counts[5] = { 0 }; // Array to store counts for 1000s, 2000s, ..., 5000s
    int total = size * size;

    // Count SSNs in each range
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int ssn = matrix[i][j];
            if (ssn >= 1000 && ssn < 2000) counts[0]++;
            else if (ssn >= 2000 && ssn < 3000) counts[1]++;
            else if (ssn >= 3000 && ssn < 4000) counts[2]++;
            else if (ssn >= 4000 && ssn < 5000) counts[3]++;
            else if (ssn >= 5000 && ssn < 6000) counts[4]++;
        }
    }

    // Print summary
    cout << "===============================================" << endl;
    cout << "The following summarizes the SSNs in Tiny Ville" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "SSN:" << (i + 1) << "000s=" << counts[i] << endl;
    }
    cout << "The total # of habitants in Tiny Ville is = " << total << endl;
    cout << "===============================================" << endl;
}

//*******************************************************************
// Function: summarizeGenders
// Parameters: int** matrix - the 2D matrix containing SSNs
//             int size - the dimension of the square matrix
// Returns: void
// Description: Counts and displays the number of women (even SSNs)
// and men (odd SSNs) in Tiny Ville, along with the total habitants.
//*******************************************************************
void summarizeGenders(int** matrix, int size) {
    int women = 0, men = 0;
    int total = size * size;

    // Count even (women) and odd (men) SSNs
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] % 2 == 0) {
                women++;
            }
            else {
                men++;
            }
        }
    }

    // Print summary
    cout << "===============================================" << endl;
    cout << "The following summarizes the Genders in Tiny Ville" << endl;
    cout << "The total # of habitants in Tiny Ville is = " << total << endl;
    cout << "Tiny Ville has = " << women << " women" << endl;
    cout << "Tiny Ville has = " << men << " men" << endl;
    cout << "===============================================" << endl;
}
