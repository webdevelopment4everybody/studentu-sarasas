#include <vector>
#include <vector>
#include <numeric>
#include "Student.h"


void fillVector(vector<Student>&);

void printVector(const vector<Student>&);
//print vector - prints the if of all students
//@param const vector<Student>& - students in class

double average(double);


int main() {

	vector<Student> myClass;

	fillVector(myClass);
	printVector(myClass);

	return 0;
}

void fillVector(vector<Student>& newMyClass) {

	string name;
	string lastname;
	double grade=0;

	cout << "How many students you want to create ?";
	int classSize;
	cin >> classSize;

	for (int i = 0; i < classSize; i++) {
		cout << "Enter Student name: ";
		cin >> name;
		cout << "Enter Student lastname: ";
		cin >> lastname;
		//average( grade);
		//cout << "enter grade: ";
		//cin >> grade;
		Student newStudent(name,lastname, average(grade));
		newMyClass.push_back(newStudent);
		cout << endl;
	}
	cout << endl;
}
void printVector(const vector<Student>& newMyClass) {

	unsigned int size = newMyClass.size();
	cout << "Firstname " << "Last name " << "Grade " << endl;
	cout << "------------------------------------------" << endl;
	for (unsigned int i = 0; i < size; i++) {
		cout << newMyClass[i].getName()<< "      " << newMyClass[i].getLastName() << "      " << newMyClass[i].getGrade() << endl;
	}

}
double average(double grade) {
	int marks_quantity =0;
	double marks = 0;
	double test = 0;

	cout << "Enter grades(if you want to break write -1): "<<endl;
	while (cin >> marks) {
		if (marks == -1) {
			break;
		}
		++marks_quantity;
		grade += marks;
	}
	grade /= marks_quantity;
	cout << "Enter test result: " << endl;
	cin >> test;

	grade = (0.4 * grade) + (0.6 * test);
	
	return grade;
}
