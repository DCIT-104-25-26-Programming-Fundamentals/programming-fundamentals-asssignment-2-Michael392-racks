// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 10;


void inputMatrix(int mat[MAX][MAX], int rows, int cols, const string& name) {
    cout << "\n--- Enter elements for Matrix " << name << " (" << rows << "x" << cols << ") ---" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}


void displayMatrix(const int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}


void transposeMatrix(const int src[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = src[i][i] = src[i][j]; 
        }
    }
}

void addMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}


void multiplyMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int rA, int cA, int cB) {
    
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            result[i][j] = 0; 
            for (int k = 0; k < cA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int choice;
    cout << "============================================" << endl;
    cout << "          MATRIX OPERATIONS MENU            " << endl;
    cout << "============================================" << endl;
    cout << "1. Transpose a Matrix (Part A)" << endl;
    cout << "2. Add Two Matrices (Part B)" << endl;
    cout << "3. Multiply Two Matrices (Part C)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        
        int rows, cols;
        cout << "Enter number of rows (max 10): ";
        cin >> rows;
        cout << "Enter number of columns (max 10): ";
        cin >> cols;

        if (rows <= 0 || rows > MAX || cols <= 0 || cols > MAX) {
            cout << "Error: Invalid matrix dimensions." << endl;
            return 1;
        }

        int A[MAX][MAX], result[MAX][MAX];
        inputMatrix(A, rows, cols, "A");

        transposeMatrix(A, result, rows, cols);

        cout << "\nOriginal Matrix:" << endl;
        displayMatrix(A, rows, cols);

        cout << "\nTransposed Matrix:" << endl;
        
        displayMatrix(result, cols, rows);

    } else if (choice == 2) {
        
        int rows, cols;
        cout << "Enter number of rows for both matrices (max 10): ";
        cin >> rows;
        cout << "Enter number of columns for both matrices (max 10): ";
        cin >> cols;

        if (rows <= 0 || rows > MAX || cols <= 0 || cols > MAX) {
            cout << "Error: Invalid matrix dimensions." << endl;
            return 1;
        }

        int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
        inputMatrix(A, rows, cols, "A");
        inputMatrix(B, rows, cols, "B");

        addMatrices(A, B, result, rows, cols);

        cout << "\nMatrix A:" << endl;
        displayMatrix(A, rows, cols);

        cout << "\nMatrix B:" << endl;
        displayMatrix(B, rows, cols);

        cout << "\nResultant Matrix (A + B):" << endl;
        displayMatrix(result, rows, cols);

    } else if (choice == 3) {
        
        int rA, cA, rB, cB;
        cout << "Enter number of rows for Matrix A: ";
        cin >> rA;
        cout << "Enter number of columns for Matrix A: ";
        cin >> cA;

        cout << "Enter number of rows for Matrix B: ";
        cin >> rB;
        cout << "Enter number of columns for Matrix B: ";
        cin >> cB;

        
        if (cA != rB) {
            cout << "Error: Matrix multiplication impossible! Columns of A (" 
                 << cA << ") must equal Rows of B (" << rB << ")." << endl;
            return 1;
        }

        if (rA <= 0 || rA > MAX || cA <= 0 || cA > MAX || cB <= 0 || cB > MAX) {
            cout << "Error: Dimensions exceed maximum allowed size (10)." << endl;
            return 1;
        }

        int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
        inputMatrix(A, rA, cA, "A");
        inputMatrix(B, rB, cB, "B");

        multiplyMatrices(A, B, result, rA, cA, cB);

        cout << "\nMatrix A:" << endl;
        displayMatrix(A, rA, cA);

        cout << "\nMatrix B:" << endl;
        displayMatrix(B, rB, cB);

        cout << "\nResultant Matrix (A x B):" << endl;
        displayMatrix(result, rA, cB);

    } else {
        cout << "Invalid choice program terminating." << endl;
    }

    return 0;
}