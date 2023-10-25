#include <iostream>
using namespace std;
const int numStudents = 5;
const int numSubjects = 5;
void calstudenttotal(int marks[][numSubjects], int studentTotals[]) {
    for (int i = 0; i < numStudents; i++) {
        int total = 0;
        for (int j = 0; j < numSubjects; j++) {
            total += marks[i][j];
        }
        studentTotals[i] = total;
    }
}
void calsubaverage(int marks[][numSubjects], double subjectAverages[]) {
    for (int j = 0; j < numSubjects; j++) {
        double sum = 0.0;
        for (int i = 0; i < numStudents; i++) {
            sum += static_cast<double>(marks[i][j]);
        }
        subjectAverages[j] = sum / numStudents;
    }
}

int main() {
    // Example 2D array of marks (5 students and 5 subjects)
    int marks[numStudents][numSubjects] = {
        {85, 90, 78, 92, 88},
        {70, 80, 75, 60, 92},
        {92, 88, 82, 78, 96},
        {65, 72, 68, 76, 89},
        {88, 94, 90, 85, 77}
    };

    int studentTotals[numStudents];
    double subjectAverages[numSubjects];
    calstudenttotal(marks, studentTotals);
    cout << "Total marks of every student:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << studentTotals[i] << " ";
    }
    cout << endl;
    calsubaverage(marks, subjectAverages);
    cout << "Average marks of every subject:" << endl;
    for (int j = 0; j < numSubjects; j++) {
        cout << subjectAverages[j] << " ";
    }
    cout << endl;

    return 0;
}
