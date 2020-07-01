#include<iostream>
#include<string>
using namespace std;

/*
This is Factory Pattren  
in this pattran the objects are created by the class which use input
*/
class Person // this a an abstract class because it have a pure virtual function
{
protected:
	string name;
public:
	Person(string n)
	{
		name = n;
	}
	Person()
	{

	}
	virtual ~Person()
	{

	}
	virtual string getName()const = 0; // this is a pure virtual function
};

class Teacher : public Person // inherite class from person
{

public:
	Teacher(string n) :Person(n)
	{

	}
	~Teacher()
	{

	}
	string getName()const override
	{
		return "Teacher:" + name; // override method
	}
};
class Employee : public Person
{
public:
	Employee(string n) :Person(n)
	{

	}
	~Employee()
	{

	}
	string getName()const override
	{
		return "Employee:" + name;// override method
	}

};
class Student : public Person
{
public:
	Student(string n) :Person(n)
	{

	}
	~Student()
	{

	}
	string getName()const override
	{
		return "Student:" + name;// override method
	}
};

class PersonFactory // this is the factory class which will give us the object 
{
public:
	static Person * NewPerson(string n, string p) // we pass in a string to get  which type of person we need  (n = Name) (p = Person)
	{
		if (p == "Employee")
		{
			return new Employee(n);
		}
		if (p == "Student")
		{
			return new Student(n);
		}
		if (p == "Teacher")
		{
			return new Teacher(n);
		}

	}
};
int main()
{
	Person * p = PersonFactory::NewPerson("David", "Student"); // as we can see i have pass the student so the student object will be returne 
	cout << p->getName() << endl;
	delete p;
	p = PersonFactory::NewPerson("Near", "Employee"); //  same goes for this
	cout << p->getName() << endl;

	delete p;
	p = PersonFactory::NewPerson("Mello", "Teacher"); // same goes for this
	cout << p->getName() << endl;
	system("pause");
	return 0;
}