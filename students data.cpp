#include "Student.h"
#include <deque>

int main() {

	deque<Student> myClass;
	//createFiles(myClass);
	//readDataFromFiles(myClass);
	//sortStudentsInFiles(myClass);
	fillVector(myClass);
	sort(myClass.begin(), myClass.end(), compareAlphabet);
	if (!myClass.empty()) {
		printVector(myClass);
	}

	return 0;
}

void fillVector(deque<Student>& newMyClass) {

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
			readFromFile(newMyClass);
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

void printVector(const deque<Student>& newMyClass) {
	unsigned int size = newMyClass.size();
	cout << size;
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

void readFromFile(deque<Student>& newMyClass) {
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
	if (file.is_open()) {
		string name;
		string lastname;
		double score[3];
		while (file >> name >> lastname) {
			int suma = 0;
			for (int n = 0; n < 3; n++) {
				file >> score[n];
				suma += score[n];
			}
			suma /= 3;
			Student newStudent(name, lastname, suma);
			newMyClass.push_back(newStudent);
		}
	}

	// Close the file
	file.close();
}

bool compareAlphabet(Student& a, Student& b)
{
	return a.getLastName() < b.getLastName();
}


void createFiles(deque<Student>& newMyClass) {
	auto start = high_resolution_clock::now();
	int files = 5;
	for (int i = 1; i <= files; i++){
		ofstream file(to_string(i) + ".txt");
		//file.open(to_string(i) + ".txt", ios::out | ios::in);
		int count = 1, count2 = 1, count3 = 1, count4 = 1, count5 = 1;
		if (i == 1) {
			for (int j = 0; j < 10000;j++) {
				file << "Vardas" << count << "   " << "Pavarde" << count << "   " << (rand() % 10) + 1 << "\n";
				count++;
			}

		}
		if (i == 2) {
			for (int j = 0; j < 10000;j++) {
				file << "Vardas" << count2 << "   " << "Pavarde" << count2 << "   " << (rand() % 10) + 1 << "\n";
				count2++;
			}
		}
		if (i == 3) {
			for (int j = 0; j < 100000;j++) {
				file << "Vardas" << count3 << "   " << "Pavarde" << count3 << "   " << (rand() % 10) + 1 << "\n";
				count3++;
			}
		}
		if (i == 4) {
			for (int j = 0; j < 1000000;j++) {
				file << "Vardas" << count4 << "   " << "Pavarde" << count4 << "   " << (rand() % 10) + 1 << "\n";
				count4++;
			}
		}
		if (i == 5) {
			for (int j = 0; j < 10000000;j++) {
				file << "Vardas" << count5 << "   " << "Pavarde" << count5 << "   " << (rand() % 10) + 1 << "\n";
				count5++;
			}
		}
		//file.close();
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout<< "Failu sukurimas  uztruko : " << duration.count() << " microseconds" << endl;
}

void readDataFromFiles(deque<Student>& newMyClass) {
	auto start = high_resolution_clock::now();
	
	int files = 5;
	for (int i = 1; i <= files; i++) {
		ifstream myfile(to_string(i) + ".txt");
		string name;
		string lastname;
		int score;			
		ofstream Vargsiukai("Vargsiukai" + to_string(i) + ".txt");
		ofstream Kietekai("Kietekai" + to_string(i) + ".txt");
			while (myfile >> name >> lastname >> score) {
			}
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Failu duomenu nuskaitymas  uztruko : " << duration.count() << " microseconds" << endl;
}

void sortStudentsInFiles(deque<Student>& newMyClass) {
	auto start = high_resolution_clock::now();

	int files = 5;
	vector<string>kieti;
	vector<string>minksti;
	for (int i = 1; i <= files; i++) {
		ifstream myfile(to_string(i) + ".txt");
		string name;
		string lastname;
		int score;
		ofstream Vargsiukai("Vargsiukai" + to_string(i) + ".txt");
		ofstream Kietekai("Kietekai" + to_string(i) + ".txt");
		while (myfile >> name >> lastname >> score) {
			
			if (score < 5) {
				Vargsiukai << name << " " << lastname << " " << score << endl;

			}
			else {
				Kietekai << name << " " << lastname << " " << score << endl;
			}
		}
		
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Studentu surusiavimas ir isvedimas uztruko : " << duration.count() << " microseconds" << endl;
}

