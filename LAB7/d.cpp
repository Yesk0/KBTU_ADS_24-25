#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

double gradeToGPA(const string& grade) {
    static const map<string, double> gradeScale = {
        {"A+", 4.00}, {"A", 3.75}, {"B+", 3.50},
        {"B", 3.00}, {"C+", 2.50}, {"C", 2.00},
        {"D+", 1.50}, {"D", 1.00}, {"F", 0.00}
    };
    return gradeScale.at(grade);
}

struct Student {
    string lastName;
    string firstName;
    double gpa;

    bool operator<(const Student& other) const {
        if (gpa != other.gpa) return gpa < other.gpa;
        if (lastName != other.lastName) return lastName < other.lastName;
        return firstName < other.firstName;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Student> students;

    for (int i = 0; i < n; ++i) {
        string lastName, firstName;
        int m;
        cin >> lastName >> firstName >> m;

        double totalPoints = 0.0;
        int totalCredits = 0;

        for (int j = 0; j < m; ++j) {
            string grade;
            int credits;
            cin >> grade >> credits;
            totalPoints += gradeToGPA(grade) * credits;
            totalCredits += credits;
        }

        double gpa = totalCredits > 0 ? totalPoints / totalCredits : 0;
        students.push_back({lastName, firstName, gpa});
    }

    sort(students.begin(), students.end());

    for (const auto& student : students) {
        cout << student.lastName << " " << student.firstName << " " 
             << fixed << setprecision(3) << student.gpa << endl;
    }

    return 0;
}