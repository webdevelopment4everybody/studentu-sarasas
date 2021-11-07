#include "Student.h"

Student::Student() {
	newGrade = 0;

}
Student::Student(string name,string lastname, double grade) {
	newName = name;
	newLastName = lastname;
	newGrade = grade;
	
}
Student::~Student() {

}
string Student::getName() const{
	return newName;
}
string Student::getLastName() const {
	return newLastName;
}
double Student::getGrade() const {
	return newGrade;
}
void Student::setName(string name) {
	newName = name;
}
void Student::setLastName(string lastname) {
	newLastName = lastname;
}
void Student::setGrade(double grade) {
	newGrade = grade;
}
