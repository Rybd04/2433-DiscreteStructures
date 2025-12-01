// Ryan Darden 
// CMPS 2433 - Stringfellow
// Programming Assignment 4
// 12/1/2025

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Purpose: Opens files
// Requires: Access to input and output files and streams
// Returns: n/a
void openFiles(ifstream& infile, ofstream& outfile);

// Purpose: Prints the header to the output file
// Requires: output file stream
// Returns: n/a
void printHeader(ofstream& outfile);

// Purpose: Finds the count of pairs from the input file
// Requires: input file stream
// Returns: count of pairs
int findCount(ifstream& infile);

// Purpose: Finds the letter pairs from the input file
// Requires: input file stream, count of pairs, vector to store equivalence classes
// Returns: n/a
void findLetters(ifstream& infile, int& count, 
    vector<vector<string>>& classes);

// Purpose: Adds a pair of letters to the equivalence classes
// Requires: vector to store equivalence classes, two letters
// Returns: n/a
void addPair(vector<vector<string>>& classes, const string& a, 
    const string& b);

// Purpose: Removes duplicate letters from each equivalence class
// Requires: vector to store equivalence classes
// Returns: n/a
void removeExtras(vector<vector<string>>& classes);

// Purpose: Prints the equivalence classes to the output file
// Requires: vector to store equivalence classes, output file stream
// Returns: n/a
void print(const vector<vector<string>>& classes, ofstream& outfile);

int main()
{
    // Variable Declarations
    ifstream infile;
    ofstream outfile;
    int count;
    vector<vector<string>> classes;

    // Function Calls
    openFiles(infile, outfile);
    printHeader(outfile);
    count = findCount(infile);
    findLetters(infile, count, classes);
    removeExtras(classes);
    print(classes, outfile);
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
    outfile << "Program 4 Equivalence Classes" << endl;
}

// Finds count of pairs from input file
int findCount(ifstream& infile)
{
    int count;
    infile >> count;
    return count;
}

// Finds letter pairs from input file
void findLetters(ifstream& infile, int& count, vector<vector<string>>& classes)
{
    // Read in pairs and add to equivalence classes
    for (int i = 0; i < count; i++)
    {
        string a, b;
        infile >> a >> b;
        addPair(classes, a, b);
    }
}

// Adds a pair of letters to the equivalence classes
void addPair(vector<vector<string>>& classes, const string& a, const string& b)
{
    int classA = -1;
    int classB = -1;

    // Find if either letter is already in an equivalence class
    for (int i = 0; i < classes.size(); i++)
    {
        for (const string& name : classes[i])
        {
            if (name == a)
                classA = i;
            if (name == b)
                classB = i;
        }
    }

    // Neither letter is in an equivalence class
    if (classA == -1 && classB == -1) 
    {
        classes.push_back({a,b});
        return;
    }

    // A exists, B does not
    if (classA != -1 && classB == -1) 
    {
        classes[classA].push_back(b);
        return;
    }

    // B exists, A does not
    if (classA == -1 && classB != -1) 
    {
        classes[classB].push_back(a);
        return;
    }

    // Both A and B exist in different classes, merge them
    if (classA != classB) {
        for (const string& s : classes[classB])
            classes[classA].push_back(s);
        classes.erase(classes.begin() + classB);
    }
}

// Removes duplicate letters from each equivalence class
void removeExtras(vector<vector<string>>& classes)
{
    for (auto& group : classes) 
    {
        sort(group.begin(), group.end());
        group.erase(unique(group.begin(), group.end()), group.end());
    }
}

// Prints the equivalence classes to the output file
void print(const vector<vector<string>>& classes, ofstream& outfile)
{
    for (int i = 0; i < classes.size(); i++)
    {
        outfile << "{";
        
        for (int j = 0; j < classes[i].size(); j++)
        {
            outfile << classes[i][j];
            if (j < classes[i].size() - 1)
                outfile << ", ";
        }
        
        outfile << "}" << endl;
    }

    outfile << endl;
}