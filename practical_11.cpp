#include <iostream>
#include <fstream>

using namespace std;

class Student {
private:
    int rollNo;
    string name;
    string studentClass;
    int year;
    float totalMarks;

public:
    // Constructor to initialize student details
    Student(int r, string n, string c, int y, float marks) 
        : rollNo(r), name(n), studentClass(c), year(y), totalMarks(marks) {}

    // Default constructor for file reading
    Student() {}

    // Function to display student details
    void displayStudentDetails() {
        cout << "\nRoll No.: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nClass: " << studentClass;
        cout << "\nYear: " << year;
        cout << "\nTotal Marks: " << totalMarks << "\n";
    }

    // Function to write student data to a file
    void writeToFile(ofstream &outFile) {
        outFile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }

    // Function to read student data from a file
    void readFromFile(ifstream &inFile) {
        inFile.read(reinterpret_cast<char*>(this), sizeof(*this));
    }
};

int main() {
    const string filename = "students.dat";

    // Predefined student records
    Student students[5] = {
        {101, "Alice", "12A", 2024, 450.5},
        {102, "Bob", "12B", 2024, 480.0},
        {103, "Charlie", "12A", 2024, 470.0},
        {104, "David", "12C", 2024, 460.0},
        {105, "Eve", "12B", 2024, 490.5}
    };

    // Writing student records to the file
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    for (int i = 0; i < 5; ++i) {
        students[i].writeToFile(outFile);
    }
    outFile.close();

    // Reading student records from the file
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nRetrieving Student Records from File:\n";
    Student temp;
    while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(temp))) {
        temp.displayStudentDetails();
        cout << "---------------------------\n";
    }
    inFile.close();

    return 0;
}