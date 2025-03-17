#include <iostream>
#include <string>

using namespace std;


class Person {
protected:
    string name;
public:
    void setPersonDetails() {
        cout << "Enter Name: ";
        getline(cin, name);
    }

    virtual void display() {
        cout << "Name: " << name << endl;
    }

    virtual ~Person() {} 
};



class Student : public Person {
private:
    string course;
    int marks;
    int year;
public:
    void setStudentDetails() {
        setPersonDetails(); // Set name from base class
        cout << "Enter Course: ";
        getline(cin, course);
        cout << "Enter Marks: ";
        cin >> marks;
        cout << "Enter Year: ";
        cin >> year;
        cin.ignore(); 
    }

    void display() override {
        cout << "\nStudent Details:" << endl;
        cout << "Student Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};


class Employee : public Person {
private:
    string department;
    double salary;
public:
    void setEmployeeDetails() {
        setPersonDetails(); 
        cout << "Enter Department: ";
        getline(cin, department);
        cout << "Enter Salary: ";
        cin >> salary;
        cin.ignore(); // Ignore newline character after numeric input
    }

    void display() override {
        cout << "\nEmployee Details:" << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Person* p1 = new Student();
    Person* p2 = new Employee();

    cout << "Enter Student Details:" << endl;
    static_cast<Student*>(p1)->setStudentDetails();

    cout << "\nEnter Employee Details:" << endl;
    static_cast<Employee*>(p2)->setEmployeeDetails();

    // Display details
    p1->display();
    p2->display();

    // Cleanup
    delete p1;
    delete p2;

    return 0;
}