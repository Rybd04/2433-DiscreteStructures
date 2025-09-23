#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void openFiles(ifstream& infile, ofstream& outfile)
{
	string inFileName;
	string outFileName;
	// cout<<"Enter the input file name: ";
	// cin>>inFileName;
	inFileName = "SampleInput.txt";
	infile.open(inFileName); // open input file
	// cout<<"Enter the output file name: ";
	// cin>> outFileName;
	outFileName = "SampleOutput.txt";
	outfile.open(outFileName);//open out putfile
}

int computeGrayInt(int n, int k) {
	int position = k ^ (k >> 1);
	cout << position;
	cout << endl;
	return position;
}


int computeGrayPosition(int g) {
	int k = 0;

	for (; g > 0; g >>= 1) {
		k ^= g;
	}
	return k;
}

int main()
{
	ifstream infile;
	ofstream outfile;
	openFiles(infile, outfile);

	char type;
	int n, k;
	int count = 0;

	outfile << "Ryan Darden";

	infile >> count;

	for (int i = 0; i < count; i++) {
		infile >> type;
		if (type == 'A') {
			infile >> n >> k;
			int gray = computeGrayInt(n, k);
		}
		else if (type == 'B') {
			int g = 0;
			infile >> g;
			int pos = computeGrayPosition(g);
			cout << pos << endl;
		}
		else {
			outfile << "Invalid Type";
			break;
		}
	}
}