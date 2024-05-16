#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
const int MAX_STUDENTS = 5; 
const int MAX_SUBJECTS = 5;
const int num_students = 5;


struct SubjectScore {
	string subject;
	int score;
};

class Student {
public:
	
	int num_students;
	Student a[MAX_STUDENTS];
	string student_id;
	string name;
	SubjectScore marks[MAX_SUBJECTS]; 
	int num_subjects; 
	char grade;
	float math_grade = 0 , science_grade = 0 , physics_grade = 0, biology_grade = 0,
		chemistry_grade = 0;
	float total_grade;

	string password; 
	
	Student() : student_id(""), name(""), grade('F'), password(""), num_subjects(0)
	{}
	
	Student(const string& id, const string& student_name, const string& pwd)
		: student_id(id), name(student_name), grade('F'), password(pwd),
		num_subjects(0) {}
	void add_marks(const string& subject, int score) {
		if (num_subjects < MAX_SUBJECTS) {
			marks[num_subjects++] = { subject, score }; 
		}
	}
	void calculate_grade() {
		total_grade = math_grade + science_grade + physics_grade + biology_grade + chemistry_grade; 
	}
	bool verify_password(const string& pwd) const { // 'const' added here
		return password == pwd;
	}
	void display_grades() const {
		for (int i = 0; i < num_subjects; ++i) {
			cout << marks[i].subject << ": " << marks[i].score << endl;
		}
	}
};
// Class to manage the entire system
class StudentManagementSystem {
private:
	Student students[MAX_STUDENTS]; // Array of students
	int num_students; // Number of students added
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
			cin.ignore(); // Ignore the newline character left in the input stream
			cout << "Enter student name: ";
			getline(cin, name);
			cout << "Create a password for the student: ";
			getline(cin, pwd);
			if (!is_unique_password(pwd)) {
				cout << "This password is already taken. Please enter a unique password.\n";
				return;
			}
			Student new_student(id, name, pwd);
			string subjects[] = { "Math", "Science", "Physics", "Biology",
		   "Chemistry" };
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
			if (students[i].student_id == search_term || students[i].name ==
				search_term) {
				cout << "Enter password for " << students[i].name << ": ";
				getline(cin, pwd);
				if (students[i].verify_password(pwd)) {
					cout << "Student found: " << students[i].name << " with ID: " <<
						students[i].student_id << endl;
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
	void delete_student_record()
	{
		double* ptr;
		ptr = new double[10];

		delete[]ptr;
		cout << "The student record have been deleted succesfully ";
	}
};
class AddStudentRecord {
	struct Student {
		int math_grade;
		int science_grade;
		int biology_grade;
		int physics_grade;
		int chemistry_grade;
	};

	int students;
	vector<Student> studentRecords;

public:
	void addRecord() {
		cout << "Enter the number of students: ";
		cin >> students;

		for (int i = 0; i < students; i++) {
			Student record;

			cout << "Enter Math grade for student " << i + 1 << ": ";
			cin >> record.math_grade;

			cout << "Enter Science grade for student " << i + 1 << ": ";
			cin >> record.science_grade;

			cout << "Enter Biology grade for student " << i + 1 << ": ";
			cin >> record.biology_grade;

			cout << "Enter Physics grade for student " << i + 1 << ": ";
			cin >> record.physics_grade;

			cout << "Enter Chemistry grade for student " << i + 1 << ": ";
			cin >> record.chemistry_grade;

			studentRecords.push_back(record);
		}
	}
};


class modify_record : public Student {
public:

	void modify_student_record()
	{

		int n;
		float math_grade, science_grade, physics_grade, biology_grade,
			chemistry_grade;
		cout << "Enter the code of subject to be modified: \n "
			<< " 1 for Math : \n "
			<< " 2 for Science :  \n"
			<< " 3 for Physics :  \n "
			<< " 4 for Biology :  \n "
			<< " 5 for chemistry : \n ";
		cin >> n;
		if (n == 1)
		{
			cout << "Enter the new math grade: " << endl;
			cin >> math_grade;
		}
		else if (n == 2)
		{
			cout << "Enter the new Science grade: " << endl;
			cin >> science_grade;
			cout << "The new science grade has been modified " << endl;
		}
		else if (n == 3)
		{
			cout << "Enter the new physics grade: " << endl;
			cin >> physics_grade;
			cout << "The new Physics grade has been modified " << endl;
		}
		else if (n == 4)
		{
			cout << "Enter the new Biology grade: " << endl;
			cin >> biology_grade;
			cout << "The new Biology grade has been modified " << endl;
		}
		else if (n == 5)
		{
			cout << "Enter the new Chemistry grade: " << endl;
			cin >> chemistry_grade;
			cout << "The new Chemistry grade has been modified " << endl;
		}
		else
		{
			cout << "The code you entered is invalid : " << endl;
		}
	}

	};



class MarkSheet : public Student {
private:
	Student student;
	int total_marks;

public:
	void generate(int ID, string student_name, float math, float science, float physics, float chemistry, float biology)
	{
		
	}

	void display()
	{
		Student a[100]; 

		for (int i = 0; i < 100; i++)
		{
			cout << a[i].name << endl;
			cout << "-----------------" << endl;
			cout << a[i].student_id << endl;
			cout << "-----------------" << endl;
			cout << "The grade of physics is " << a[i].physics_grade << " / 100 " << endl;
			cout << "-----------------" << endl;
			cout << "The grade of chemistry is " << a[i].chemistry_grade << " / 100 " << endl;
			cout << "-----------------" << endl;
			cout << "The grade of biology is " << a[i].biology_grade << " / 100 " << endl;
			cout << "-----------------" << endl;
			cout << "The grade of math is " << a[i].math_grade << " / 100 " << endl;
			cout << "-----------------" << endl;
			cout << "The grade of science is " << a[i].science_grade << " / 100 " << endl;
			cout << "-------------------" << endl;
			cout << "-------------------" << endl;
			cout << "Total marks = " << a[i].total_grade << " / 100 " << endl; // To be declared new attribute total grade
		}
	}
};


class Admin
{
protected:
	string username;
	string password;
	bool is_logged_in;
	string user;
	string pass;
public:

	Admin(string& user, string& pass)
	{
		username = user;
		password = pass;
	}
	void login()
	{
		cout << "Enter username: " << endl;
		cin >> username;
		cout << "Enter password: " << endl;
		cin >> password;
		if (username == user && password == pass)
		{
			cout << "login succesful: " << endl;
		}
		else
		{
			cout << "Invalid username or password: " << endl;
		}
	}
	void logout()
	{
		if (is_logged_in = false)
		{
			cout << "Logout succesful " << endl;
		}
		else
		{
			cout << "You're not logged out " << endl;
		}
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


	vector<string> parseDataFromFile(const string& filename) {
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


// Main function
int main() {
	StudentManagementSystem system;
	MarkSheet generator;
	modify_record modifier;
	AddStudentRecord addStudent;
	FileHandler file;
	bool running = true;
	int choice;
	while (running) {
		cout << "Student Management System\n";
		cout << "1. Add Student Record\n";
		cout << "2. Search Student Record\n";
		cout << "3. Modify student Record\n";
		cout << "4. Generate mark sheet\n";
		cout << "5. Delete student record\n";
		cout << "6. Exit\n";
		cout << "7. Modify files\n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "How Many Student record you want to add" << endl;
			addStudent.addRecord();
			break;
		case 2:
			system.search_student_record();
			break;
		case 3:
			modifier.modify_student_record();
			break;
		case 4:
			generator.display();
			break;
		case 5:
			// Add code for deleting student record
			break;
		case 6:
			file.read_data();
			file.format_data();
			file.parseDataFromFile();
			file.write_data();


		case 7:
			running = false;
			break;
			// ... other cases
		}
	}


	return 0;
}