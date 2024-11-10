#include <iostream>
#include <string>
using namespace std;

// Base Student class
class Student {
protected:
    string name;
    int roll_no;

public:
    void getStudentInfo() {
        cout << "\nEnter student name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll_no;
    }

    void showStudentInfo() const {
        cout << "Name: " << name << ", Roll Number: " << roll_no << endl;
    }
};

// Marks class (inherited in multiple inheritance)
class Marks {
protected:
    int subjectMarks[3];
    int sportsMarks;

public:
    void getMarks() {
        cout << "Enter marks for Subject 1 out of 100: ";
        cin >> subjectMarks[0];
        cout << "Enter marks for Subject 2 out of 100: ";
        cin >> subjectMarks[1];
        cout << "Enter marks for Subject 3 out of 100: ";
        cin >> subjectMarks[2];
        cout << "Enter marks for Sports out of 100: ";
        cin >> sportsMarks;
    }

    void showMarks() const {
        cout << "Subject 1: " << subjectMarks[0] << endl;
        cout << "Subject 2: " << subjectMarks[1] << endl;
        cout << "Subject 3: " << subjectMarks[2] << endl;
        cout << "Sports: " << sportsMarks << endl;
    }
};

// Result class (multiple inheritance: inherits from Student and Marks)
class Result : public Student, public Marks {
protected:
    int totalMarks;
    float averageMarks;
    char grade;

    void calculateResult() {
        totalMarks = subjectMarks[0] + subjectMarks[1] + subjectMarks[2];
        averageMarks = totalMarks / 3.0;
        grade = (averageMarks >= 90) ? 'A' : (averageMarks >= 80) ? 'B' :
                (averageMarks >= 70) ? 'C' : (averageMarks >= 60) ? 'D' : 'F';
    }

public:
    void getResult() {
        getStudentInfo();
        getMarks();
        calculateResult();
    }

    void showResult() const {
        showStudentInfo();
        showMarks();
        cout << "Total Marks (Subjects only): " << totalMarks << endl;
        cout << "Average Marks: " << averageMarks << endl;
        cout << "Grade: " << grade << endl;
    }
};

// FinalResult class (hybrid inheritance)
class FinalResult : public Result {
protected:
    int finalTotal;
    float finalAverage;
    char finalGrade;

    void calculateFinalResult() {
        finalTotal = totalMarks + sportsMarks;
        finalAverage = finalTotal / 4.0;
        finalGrade = (finalAverage >= 90) ? 'A' : (finalAverage >= 80) ? 'B' :
                     (finalAverage >= 70) ? 'C' : (finalAverage >= 60) ? 'D' : 'F';
    }

public:
    void getFinalResult() {
        getResult();
        calculateFinalResult();
    }

    void showFinalResult() const {
        showResult();
        cout << "Total Marks (Including Sports): " << finalTotal << endl;
        cout << "Final Average: " << finalAverage << endl;
        cout << "Final Grade: " << finalGrade << endl;
    }
};

// Operator overloading and user-defined class
class StudentMarks {
private:
    int marks;

public:
    StudentMarks(int m = 0) : marks(m) {}

    StudentMarks& operator++() { // Pre-increment
        ++marks;
        return *this;
    }

    StudentMarks& operator--() { // Pre-decrement
        --marks;
        return *this;
    }

    bool operator!() const { // Logical NOT operator
        return marks == 0;
    }

    void display() const {
        cout << "Marks: " << marks << endl;
    }
};

// Main program
int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    FinalResult* students = new FinalResult[numStudents]; // Dynamic memory allocation

    for (int i = 0; i < numStudents; i++) {
        cout << "\nEntering data for student " << i + 1 << ":\n";
        students[i].getFinalResult();
    }

    for (int i = 0; i < numStudents; i++) {
        cout << "\nFinal result of student " << i + 1 << ":\n";
        students[i].showFinalResult();
    }

    StudentMarks m1(75);
    m1.display();

    ++m1;
    m1.display();

    if (!m1) {
        cout << "Marks are zero.\n";
    } else {
        cout << "Marks are not zero.\n";
    }

    --m1;
    m1.display();

    delete[] students; // Free allocated memory
    return 0;
}
