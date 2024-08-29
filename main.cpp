#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Course {
    string name;
    double gradePoints; 
    int credits;
};

double calculateGPA(const vector<Course>& courses) {
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (const auto& course : courses) {
        totalGradePoints += course.gradePoints * course.credits;
        totalCredits += course.credits;
    }

    if (totalCredits == 0) return 0; 
    return totalGradePoints / totalCredits;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);

    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter the name of course " << i + 1 << ": ";
        cin.ignore(); 
        getline(cin, courses[i].name);

        cout << "Enter the grade points for " << courses[i].name << " (e.g., 4.0 for A): ";
        cin >> courses[i].gradePoints;

        cout << "Enter the number of credits for " << courses[i].name << ": ";
        cin >> courses[i].credits;
    }

    double gpa = calculateGPA(courses);
    cout << fixed << setprecision(2); 
    cout << "Your CGPA is: " << gpa << endl;

    return 0;
}
