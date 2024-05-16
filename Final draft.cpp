 #include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

const int MAX_STUDENTS = 100; 
const int MAX_SUBJECTS = 5; 

 
struct SubjectScore {
    string subject;
    int score;
};

class Student {
public:
    string student_id;
    string name;
    SubjectScore marks[MAX_SUBJECTS];
    int num_subjects;
    char grade;
    string password;
    int num_students;
    

    // Default constructor
    Student() : student_id(""), name(""), grade('F'), password(""), num_subjects(0) {}

    // Parameterized constructor
    Student(const string& id, const string& student_name, const string& pwd)
        : student_id(id), name(student_name), grade('F'), password(pwd), num_subjects(0) {}

    void add_marks(const string& subject, int score) {
        if (num_subjects < MAX_SUBJECTS) {
            marks[num_subjects++] = { subject, score };
        }
    }

    void display_grades() const {
        for (int i = 0; i < num_subjects; ++i) {
            cout << marks[i].subject << ": " << marks[i].score << endl;
        }
    }

    void generate_mark_sheet() const {
        cout << "Mark Sheet for Student " << name << " (ID: " << student_id << "):\n";
        cout << "---------------------------------------------\n";
        cout << "Subject\t\tScore\n";
        cout << "---------------------------------------------\n";
        for (int i = 0; i < num_subjects; ++i) {
            cout << setw(10) << left << marks[i].subject << "\t" << marks[i].score << endl;
        }
        cout << "---------------------------------------------\n";
    }

    bool verify_password(const string& pwd) const {
        return password == pwd;
    }
};

class StudentManagementSystem {
private:
    Student students[MAX_STUDENTS];
    int num_students;

public:
    StudentManagementSystem() : num_students(0) {}

    bool is_unique_id(const string& id) {
        for (int i = 0; i < num_students; ++i) {
            if (students[i].student_id == id) {
                return false;
            }
        }
        return true;
    }

    bool is_unique_password(const string& pwd) {
        for (int i = 0; i < num_students; ++i) {
            if (students[i].password == pwd) {
                return false;
            }
        }
        return true;
    }

    void add_student_record() {
        if (num_students < MAX_STUDENTS) {
            string id, name, pwd;
            cout << "Enter student ID: ";
            cin >> id;
            if (!is_unique_id(id)) {
                cout << "This ID is already taken. Please enter a unique ID.\n";
                return;
            }
            cin.ignore();
            cout << "Enter student name: ";
            getline(cin, name);
            cout << "Create a password for the student: ";
            getline(cin, pwd);
            if (!is_unique_password(pwd)) {
                cout << "This password is already taken. Please enter a unique password.\n";
                return;
            }
            Student new_student(id, name, pwd);
            string subjects[] = { "Math", "Science", "Physics", "Biology", "Chemistry" };
            int score;
            for (const string& subject : subjects) {
                do {
                    cout << "Enter grade for " << subject << " (0-100): ";
                    cin >> score;
                    if (score < 0 || score > 100) {
                        cout << "Invalid grade. Please enter a value between 0 and 100.\n";
                    }
                } while (score < 0 || score > 100);
                new_student.add_marks(subject, score);
            }
            students[num_students++] = new_student;
            cout << "Student record added with grades.\n";
        }
        else {
            cout << "Maximum number of students reached.\n";
        }
    }

    void search_student_record() {
        string search_term, pwd;
        cout << "Enter student ID or full name to search: ";
        cin.ignore();
        getline(cin, search_term);
        for (int i = 0; i < num_students; ++i) {
            if (students[i].student_id == search_term || students[i].name == search_term) {
                cout << "Enter password for " << students[i].name << ": ";
                getline(cin, pwd);
                if (students[i].verify_password(pwd)) {
                    cout << "Student found: " << students[i].name << " with ID: " << students[i].student_id << endl;
                    students[i].display_grades();
                }
                else {
                    cout << "Invalid password.\n";
                }
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void delete_student_record() {
        string id_to_delete;
        cout << "Enter student ID to delete: ";
        cin >> id_to_delete;
        for (int i = 0; i < num_students; ++i) {
            if (students[i].student_id == id_to_delete) {
                // Shift elements to fill the gap
                for (int j = i; j < num_students - 1; ++j) {
                    students[j] = students[j + 1];
                }
                num_students--;
                cout << "Student record deleted successfully.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void modify_student_record() {
        string id_to_modify;
        cout << "Enter student ID to modify: ";
        cin >> id_to_modify;
        for (int i = 0; i < num_students; ++i) {
            if (students[i].student_id == id_to_modify) {
                int choice;
                cout << "Select what you want to modify:\n";
                cout << "1. Name\n";
                cout << "2. Password\n";
                cout << "3. Grades\n";
                cout << "Enter your choice: ";
                cin >> choice;
                switch (choice) {
                case 1:
                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, students[i].name);
                    break;
                case 2:
                    cout << "Enter new password: ";
                    cin.ignore();
                    getline(cin, students[i].password);
                    break;
                case 3:
                    int score;
                    for (int j = 0; j < students[i].num_subjects; ++j) {
                        cout << "Enter new grade for " << students[i].marks[j].subject << " (0-100): ";
                        cin >> score;
                        if (score < 0 || score > 100) {
                            cout << "Invalid grade. Please enter a value between 0 and 100.\n";
                            --j; 
                            continue;
                        }
                        students[i].marks[j].score = score;
                    }
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
                }
                cout << "Student record modified successfully.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void generate_mark_sheet() {
        string id_to_generate;
        cout << "Enter student ID to generate mark sheet: ";
        cin >> id_to_generate;
        for (int i = 0; i < num_students; ++i) {
            if (students[i].student_id == id_to_generate) {
                students[i].generate_mark_sheet();
                return;
            }
        }
        cout << "Student not found.\n";
    }
};

class FileHandler {
private:
    string file_path;
    string a;

public:
    void read_data() {
        ifstream file("C:\\");

        if (file.is_open()) {
            string a;
            while (getline(file, a)) {


            }
            file.close();

        }
        else {
            cout << "Failed to open file: " << endl;
        }
    }
    void write_data() {
        ofstream file("C:// ");

        if (file.is_open()) {
            for (int i = 0; ; i++) {
                file << a << endl;
            }
            file.close();
            cout << "Data entered succesfully: " << endl;
        }
        else {
            cout << "Failed to open file: " << endl;
        }
    }


    vector<string> parse_data(const string& filename) {
        vector<string> data;
        ifstream file(filename);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                data.push_back(line);
            }
            file.close();
        }
        else {
            cout << "Failed to open file: " << filename << endl;
        }

        return data;
    }

    void format_data(const vector<int>& data, const string& filename) {
        ofstream file(filename);

        if (file.is_open()) {
            for (const int& item : data) {
                file << item << "\n";
            }

            file.close();
            cout << "Data formatted and written to file: " << filename << endl;
        }
        else {
            cout << "Unable to open file: " << filename << endl;
        }
    }

};



int main() {
    StudentManagementSystem system;
    bool running = true;
    int choice;
    while (running) {
        cout << "Student Management System\n";
        cout << "1. Add Student Record\n";
        cout << "2. Search Student Record\n";
        cout << "3. Delete Student Record\n";
        cout << "4. Modify Student Record\n";
        cout << "5. Generate Mark Sheet\n";
        cout << "6. Exit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            system.add_student_record();
            break;
        case 2:
            system.search_student_record();
            break;
        case 3:
            system.delete_student_record();
            break;
        case 4:
            system.modify_student_record();
            break;
        case 5:
            system.generate_mark_sheet();
            break;
        case 6:
            running = false;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6.\n";
            break;
        }
    }
    return 0;
}

