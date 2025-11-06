// Ryan Darden 
// CMPS 2433 - Stringfellow
// Programming Assignment 3
// 11/7/2025

#include <fstream>
#include <string>
#include <iostream>
using namespace std;
#include <iomanip>

// Purpose: Opens files
// Requires: Access to input and output files and streams
// Returns: n/a
void openFiles(ifstream& infile, ofstream& outfile);

// Purpose: Prints the header to the output file
// Requires: output file stream
// Returns: n/a
void printHeader(ofstream& outfile);

// Purpose: Fills in the matrix using the boundary fill algorithm
// Requires: starting x and y coordinates, current level, matrix, number of rows and columns
// Returns: n/a
void boundaryFill(int x, int y, int level, int** matrix, int rows, int cols);

// Purpose: Creates a matrix from the input file
// Requires: input file stream, number of rows and columns
// Returns: pointer to the created matrix
int** createMatrix(ifstream& infile, int rows, int cols);

// Purpose: Gets the values for rows, columns, and starting coordinates from the input file
// Requires: input file stream, output file stream, references to rows, columns, xStart, and yStart
// Returns: n/a
void getValues(ifstream& infile, ofstream& outfile, int& rows, int& cols, int& xStart, int& yStart);

// Purpose: Gets the number of matrices to process from the input file
// Requires: input file stream, output file stream
// Returns: number of matrices
int matrixNum(ifstream& infile, ofstream& outfile);

// Purpose: Prints the matrix to the console
// Requires: matrix, number of rows and columns
// Returns: n/a
void printMatrix(int** matrix, int rows, int cols, ofstream& outfile);

int main()
{
    // Variable Declarations
    ifstream infile;
    ofstream outfile;
    int rows;
    int cols;
    int xStart;
    int yStart;
    int numMatrix;
    int** matrix;
    int level = 0;

    openFiles(infile, outfile);
    printHeader(outfile);

    // Get number of matrices
    numMatrix = matrixNum(infile, outfile);

    for (int i = 0; i < numMatrix; i++)
    {
        // Get matrix values
        getValues(infile, outfile, rows, cols, xStart, yStart);

        // Create matrix
        matrix = createMatrix(infile, rows, cols);

        // Perform boundary fill
        boundaryFill(xStart, yStart, level, matrix, rows, cols);

        // Print matrix to console
        printMatrix(matrix, rows, cols, outfile);
    }
    
    infile.close();
    outfile.close();
}

// Opens input and output files
void openFiles(ifstream& infile, ofstream& outfile)
{
    string inFileName;
    string outFileName;
    cout << "Enter the input file name: ";
    cin >> inFileName;
    infile.open(inFileName); // open input file
    cout << "Enter the output file name: ";
    cin >> outFileName;
    outfile.open(outFileName);//open out putfile
}

// Prints header to output file
void printHeader(ofstream& outfile)
{
    outfile << "Ryan Darden" << endl;
    outfile << "Program 3 Boundary Fill" << endl;
}

// Gets number of matrices from input file
int matrixNum(ifstream& infile, ofstream& outfile)
{
    int numMatrix;
    infile >> numMatrix;
    return numMatrix;
}

// Gets values for rows, columns, and starting coordinates
void getValues(ifstream& infile, ofstream& outfile, int& rows, int& cols, int& xStart, int& yStart)
{
    infile >> rows;
    infile >> cols;

    infile >> xStart;
    infile >> yStart;
}

// Creates matrix from input file
int** createMatrix(ifstream& infile, int rows, int cols)
{
    // Dynamically allocate 2D array
    int** matrix = new int* [rows];

    // Fill matrix with values from input file
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            infile >> matrix[i][j];
        }
    }

    return matrix;
}

// Boundary fill algorithm
void boundaryFill(int x, int y, int level, int** matrix, int rows, int cols)
{

    // Base Cases
    if (x < 0 || x >= rows || y < 0 || y >= cols)
        return;

    // If the current cell is not 0, return
    if (matrix[x][y] != 0)
        return;

    // Fill the current cell with the next level
    matrix[x][y] = ++level;

    // Recursive calls in all four directions
    if (y + 1 < cols && matrix[x][y + 1] == 0)        // right
        boundaryFill(x, y + 1, level, matrix, rows, cols);

    if (x + 1 < rows && matrix[x + 1][y] == 0)        // down
        boundaryFill(x + 1, y, level, matrix, rows, cols);

    if (y - 1 >= 0 && matrix[x][y - 1] == 0)          // left
        boundaryFill(x, y - 1, level, matrix, rows, cols);

    if (x - 1 >= 0 && matrix[x - 1][y] == 0)          // up
        boundaryFill(x - 1, y, level, matrix, rows, cols);
}

// Prints matrix to output file
void printMatrix(int** matrix, int rows, int cols, ofstream& outfile)
{
    outfile << endl;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            outfile << setw(4) << matrix[i][j] << " ";
        }
            outfile << endl;
    }
}