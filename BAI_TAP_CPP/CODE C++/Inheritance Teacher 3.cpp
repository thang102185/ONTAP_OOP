#include <iostream>
#include <string>
using namespace std;
//--------------------------------------------------------------------//
class Teacher {
protected:
	string name;
	int age, numOfStudents;
public:
	void setName(const string & new_name) {
		name = new_name; age = 98; numOfStudents = 30;		
	}
	void print() const; // ham print cua lop Teacher
};
void Teacher :: print() const {
	cout << "Name: " << name << " Age: " << age << endl;
	cout << "Number of Students: " << numOfStudents << endl;
};
//--------------------------------------------------------------------//
class Principal : public Teacher {
	string school_name;
	int numOfTeachers;
public:
	void setSchool(const string & s_name) {
		school_name = s_name;
		numOfTeachers = 50;
	}
	void print() const; // ham print cua lop Principal
};
void Principal::print() const {
	Teacher::print();	
	cout << "Name of the school: " << school_name << endl;
	cout << "Num of Teachers: " << numOfTeachers << endl;
};
//--------------------------------------------------------------------//
int main () {
	Teacher t;
	t.setName("Michel Jackson");
	t.print();// print cua lop Teacher
	cout << "--------------------------" << endl;
	
	Principal p;	
	p.setSchool("Havard");
	p.setName("Bill Gates");
	p.print();// print cua lop Principal

		
	return 0;
}

