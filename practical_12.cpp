#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

void removeWhitespacesAndCopy(const string &sourceFile, const string &destinationFile) {
    ifstream inFile(sourceFile);
    ofstream outFile(destinationFile);

    if (!inFile) {
        cerr << "Error opening source file!" << endl;
        return;
    }
    if (!outFile) {
        cerr << "Error creating destination file!" << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        if (!isspace(ch)) { // Check if the character is NOT a whitespace
            outFile.put(ch);
        }
    }

    cout << "File copied successfully without whitespaces.\n";

    inFile.close();
    outFile.close();
}

int main() {
    string sourceFile, destinationFile;
    
    cout << "Enter source file name: ";
    cin >> sourceFile;
    cout << "Enter destination file name: ";
    cin >> destinationFile;

    removeWhitespacesAndCopy(sourceFile, destinationFile);

    return 0;
}