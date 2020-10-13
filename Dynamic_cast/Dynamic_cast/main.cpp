#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Parent
{
public:
	Parent(int age) :age(age){}
	virtual void print()
	{
		cout << this->age << endl;
	}
public:
	int age;
};

class Child :public Parent
{
public:
	Child(int age, int score) :Parent(age), score(score){}
	void print()
	{
		cout << this->age << endl;
		cout << this->score << endl;
	}
public:
	int score;
};

int main()
{
	Parent p(40);
	Child c(12, 90);

	Parent* pp = dynamic_cast<Parent*> (&c);
	Child* cp = dynamic_cast<Child*> (&p);
	if (pp == NULL)
	{
		cout << "子转父失败！" << endl;
	}
	else
	{
		cout << "子类指针可以转父类指针！" << endl;
	}

	if (cp == NULL)
	{
		cout << "父转子失败！" << endl;
	}
	else
	{
		cout << "父类指针可以转子类指针！" << endl;
	}
	system("pause");
	return 0;
}