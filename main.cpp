#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    string firstName;
    string lastName;
    int year;
    string section;
    string course;
};

void AddStudent(Student studentList[], int& numStudents);
void CheckStudentList(Student studentList[], int numStudents);

int main() {
    int choice;
    Student studentList[MAX_STUDENTS];
    int numStudents = 0;

    do {
        cout << "\nMain Menu:\n1. Add Student\n2. Check Student List\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (numStudents < MAX_STUDENTS) {
                    AddStudent(studentList, numStudents);
                } else {
                    cout << "Maximum number of students reached.\n";
                }
                break;

            case 2:
                CheckStudentList(studentList, numStudents);
                break;

            case 3:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

void AddStudent(Student studentList[], int& numStudents) {
    cout << "Enter first name: ";
    cin >> studentList[numStudents].firstName;

    cout << "Enter last name: ";
    cin >> studentList[numStudents].lastName;

    cout << "Enter year: ";
    cin >> studentList[numStudents].year;

    cout << "Enter section: ";
    cin >> studentList[numStudents].section;

    cout << "Enter course: ";
    cin >> studentList[numStudents].course;

    numStudents++;
}

void CheckStudentList(Student studentList[], int numStudents) {
    const int STUDENTS_PER_PAGE = 5;
    int totalPages = (numStudents - 1) / STUDENTS_PER_PAGE + 1;
    int currentPage = 0;

    char option;
    do {
        system("cls");
        cout << "Page " << currentPage + 1 << " of " << totalPages << "\n";
        for (int i = currentPage * STUDENTS_PER_PAGE; i < min((currentPage + 1) * STUDENTS_PER_PAGE, numStudents); ++i) {
            cout << "\nStudent " << i + 1 << "\n"
                << "First Name: " << studentList[i].firstName << "\n"
                << "Last Name: " << studentList[i].lastName << "\n"
                << "Course: " << studentList[i].course << "\n"
                << "Year: " << studentList[i].year << "\n";
        }

        cout << "N - Next Page, P - Previous Page, E - Exit to Main Menu\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 'N':
            case 'n':
                if (currentPage < totalPages - 1) {
                    currentPage++;
                }
                break;
            case 'P':
            case 'p':
                if (currentPage > 0) {
                    currentPage--;
                }
                break;
        }
    } while (option != 'E' && option != 'e');
}
