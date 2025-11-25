// Ryan Darden 
// CMPS 2433 - Stringfellow
// Programming Assignment 4
// 12/1/2025

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

int main()
{
    // Variable Declarations
    ifstream infile;
    ofstream outfile;

    openFiles(infile, outfile);
}

// Opens input and output files
void openFiles(ifstream& infile, ofstream& outfile)
{
    string inFileName;
    string outFileName;
    //cout << "Enter the input file name: ";
    //cin >> inFileName;
    inFileName = prog4.dat;
    infile.open(inFileName); // open input file
    //cout << "Enter the output file name: ";
    //cin >> outFileName;
    outFileName = out.out;
    outfile.open(outFileName);//open out putfile
}

// Prints header to output file
void printHeader(ofstream& outfile)
{

}