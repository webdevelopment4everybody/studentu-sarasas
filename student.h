#pragma once

//header

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
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
#endif

