// Ryan Darden 
// CMPS 2433 - Stringfellow
// Programming Assignment 1
// 9/24/25

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Purpose: Opens files
// Requires: Access to input and output files and streams
// Returns: n/a
void openFiles(ifstream& infile, ofstream& outfile);


// Purpose: to compute & return the integer corresponding to
// the gray number that appears in position k of the n-bit Gray Code using bit manipulation.
// Requires: Position and number of bits
// Returns: the gray code integer
int computeGrayInt(int n, int k);

// Purpose: that when given a gray code, computes its
// position k in the n-bit Gray Code.
// Requires: Gray code
// Returns: The position of the gray code
int computeGrayPosition(int g);

int main()
{
	ifstream infile;
	ofstream outfile;
	openFiles(infile, outfile);

	char type;
	int n, k;
	int count = 0;
	
	infile >> count;	//Get count of test cases

	outfile << "Ryan Darden" << endl;

	for (int i = 0; i < count; i++) {	//Loop for each test case
		infile >> type;
		if (type == 'A') {		//Type A: Find gray code at position k
			infile >> n >> k;
			int gray = computeGrayInt(n, k);
			outfile << gray << endl;
		}
		else if (type == 'B') {		//Type B: Find position of gray code g
			int g = 0;
			infile >> g;
			int pos = computeGrayPosition(g);
			outfile << pos << endl;
		}
		else {		//Invalid type
			outfile << "Invalid Type";
			break;
		}
	}
}


void openFiles(ifstream& infile, ofstream& outfile)
{
	string inFileName;
	string outFileName;
	cout<<"Enter the input file name: ";
	cin>>inFileName;
	infile.open(inFileName); // open input file
	cout<<"Enter the output file name: ";
	cin>> outFileName;
	outfile.open(outFileName);//open out putfile
}


int computeGrayInt(int n, int k) {
	int gray = k ^ (k >> 1); 		// Formula for computing gray code from binary number
	return gray;
}

int computeGrayPosition(int g) {
	int k = 0;

	for (; g > 0; g >>= 1) {		// Loop until g is 0, shifting g right each iteration
		k ^= g;
	}
	cout << k;
	return k;
}