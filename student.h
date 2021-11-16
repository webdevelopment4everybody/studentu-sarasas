#pragma once

//header

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <chrono>
#include <thread>
using namespace std::chrono;
using namespace std;


class Student {
public:
	//default constructor
	Student();

	//overload constructor
	Student(string, string,double);

	//destructor
	~Student();

	//accessor functions
	string getName() const;
	//getName
	//@return string- name of student
	string getLastName() const;

	double getGrade() const;
	//getGrade
	//@return int - grade student

	//Mutator function
	void setName(string);
	//setName
	//@param string - name of student
	void setLastName(string);
	void setGrade(double);
	//setGrade
	//@param char - grade of students

private:
	string newName;
	string newLastName;
	double newGrade;

};
void fillVector(vector<Student>&);

void printVector(const vector<Student>&);
//print vector - prints the if of all students
//@param const vector<Student>& - students in class

double average(double);

double median(double);

void readFromFile(vector<Student>&);

bool compareAlphabet(Student& a, Student& b);

void createFiles(vector<Student>&);

void readDataFromFiles(vector<Student>&);

void sortStudentsInFiles(vector<Student>&);

#endif

