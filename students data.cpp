#include <vector>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Student.h"
#include<iostream>
#include <stdexcept>
using namespace std;


void fillVector(vector<Student>&);

void printVector(const vector<Student>&);
//print vector - prints the if of all students
//@param const vector<Student>& - students in class

double average(double);

double median(double);

void readFromFile();

bool compareAlphabet(Student& a, Student& b);




int main() {

	vector<Student> myClass;

	fillVector(myClass);
	sort(myClass.begin(), myClass.end(), compareAlphabet);
	if (!myClass.empty()) {
		printVector(myClass);
	}

	return 0;
}



void fillVector(vector<Student>& newMyClass) {

	string name;
	string lastname;
	double grade=0;
	int choose=1;
	int choice = 0;
	
	cout << "*******************************\n";
	cout << " 1 - Read from a file.\n";
	cout << " 2 - Read not from a file.\n";
	cout << " Enter your choice and press return: ";
	cin >> choice;
	try {
		if (choice >= 3 || choice <= 0) {
			throw invalid_argument("Input can only be 1 or 2");
		}
		else if (choice == 1) {
			readFromFile();
		}
		else {
			cout << "How many students you want to create ?";
			int classSize;
			cin >> classSize;

			for (int i = 0; i < classSize; i++) {

				cout << "Enter Student name: ";
				cin >> name;
				cout << "Enter Student lastname: ";
				cin >> lastname;

				cout << "1-Calculate with average" << endl;
				cout << "2-Calculate with median" << endl;
				cin >> choose;

				if (choose == 1) {
					Student newStudent(name, lastname, average(grade));
					newMyClass.push_back(newStudent);

				}
				else {
					Student newStudent(name, lastname, median(grade));
					newMyClass.push_back(newStudent);
				}
				cout << endl;
			}
		}
	}
	catch (const invalid_argument& e) {
		cout << e.what() << endl;
	}
	
	cout << endl;
}

void printVector(const vector<Student>& newMyClass) {
	unsigned int size = newMyClass.size();
	cout << "Firstname " << "Last name " << "Final grade(avg)/Final grade(median) " << endl;
	cout << "------------------------------------------" << endl;
	for (unsigned int i = 0; i < size; i++) {
		cout << newMyClass[i].getName()<< "      " << newMyClass[i].getLastName() << "      " << newMyClass[i].getGrade() << endl;
	}
}

double average(double grade) {
	int marks_quantity =0;
	double marks = 0;
	double test = 0;
	int random = 0;

	cout << "1-Generate homework grades and test grades random." << endl;
	cout << "2-Enter grades by yourself." << endl;
	cin >> random;
	if (random == 1) {
		cout << "How many grades?" << endl;
		cin >> marks_quantity;
		srand(time(0));
		for (int i = 0; i < marks_quantity; i++) {
			int randomNumber = (rand() % 10) + 1;
			cout << randomNumber << endl;
			grade += randomNumber;
		}
			grade /= marks_quantity;
		test = (rand() % 10);
		cout << test << endl;
		grade = (0.4 * grade) + (0.6 * test);
	}else {
		cout << "Enter grades(if you want to break write -1): " << endl;
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
		while (test > 10 || test < 0) {
			cout << "Enter valid test result(1-10)" << endl;
			cin >> test;
		}
		cout << grade;

		grade = (0.4 * grade) + (0.6 * test);
	}
	
	return grade;
}

double median(double grade) {
	int marks_quantity = 0;
	double marks = 0;
	double test = 0;
	vector<double> arr;
	int random = 0;

	cout << "1-Generate homework grades and test grades random." << endl;
	cout << "2-Enter grades by yourself." << endl;
	cin >> random;
	
	
	
	if (random == 1) {
		cout << "How many grades?" << endl;
		cin >> marks_quantity;
		srand(time(0));
		for (int i = 0; i < marks_quantity; i++) {
			int randomNumber = (rand() % 10) + 1;
			cout << randomNumber << endl;
			arr.push_back(marks);
		}
		test = (rand() % 10);
		cout << test << endl;
		int n;
		n = marks_quantity;
		//array size odd
		if (n % 2 == 1) {
			nth_element(arr.begin(), arr.begin() + n / 2, arr.end());
			grade = (arr[n / 2] * 0.4) + (test * 0.6);
		}
		else { //array size even
			double tmedian = (arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) / 2;
				grade = ((tmedian * 0.4) + (test * 0.6));
		}
	}
	else {
		cout << "Enter grades(if you want to break write -1): " << endl;
		while (cin >> marks) {
			if (marks == -1) {
				break;
			}
			++marks_quantity;
			arr.push_back(marks);
		}
		cout << "Enter test result: " << endl;
		cin >> test;
		while (test > 10 || test < 0) {
			cout << "Enter valid test result(1-10)" << endl;
			cin >> test;
		}

		int n;
		n = marks_quantity;
		//array size odd
		if (n % 2 == 1) {
			nth_element(arr.begin(), arr.begin() + n / 2, arr.end());
			grade = (arr[n / 2] * 0.4) + (test * 0.6);
		}
		else { //array size even
			double tmedian = (arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) / 2;
				grade = ((tmedian * 0.4) + (test * 0.6));
		}
	}
	return grade;
}

void readFromFile() {
	// Create a text string, which is used to output the text file
	string myText;
	string name;

	// Read from the text file
	ifstream file("Studentai.txt");

	// Use a while loop together with the getline() function to read the file line by line
	try {
		if (!file) {
			throw invalid_argument("File does not exist.");
		}
	}
	catch (const invalid_argument& e) {
		cout << e.what() << endl;
	}
	if (file.is_open())
	{
		vector<string> myArray;
		string line;

		//push every line of txt
		while (getline(file, line))
		{
			myArray.push_back(line);
		}
		string word;
		string studentName;
		stringstream ss;
		cout << "Firstname " << "Last name " << "Final grade(avg)/Final grade(median) " << endl;
		cout << "------------------------------------------" << endl;
		for (const string& line_of_file : myArray) {

			float num = 0;
			int totalMarks = 0;

			for (size_t i = 0; i < line_of_file.length(); i++)
			{
				if (line_of_file[i] != ' ') {
					word += line_of_file[i];
				}

				if (line_of_file[i] == ' ') {
					if (word.length() <= 3) {
						num++;

						stringstream s(word);
						int mark = 0;
						s >> mark;

						totalMarks += mark;

						word = " ";
					}

					if (word.length() > 3) {
						studentName += word;
						
						cout << studentName;

						word = " ";
						studentName = " ";
					}

				}

			}
			float ats = totalMarks / num;
		cout <<"         "<< ats << endl;
		}
		
	}

	// Close the file
	file.close();
}


bool compareAlphabet(Student& a, Student& b)
{
	return a.getLastName() < b.getLastName();
}
