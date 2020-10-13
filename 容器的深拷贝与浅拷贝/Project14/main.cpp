#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//容器的深拷贝与浅拷贝

class Person
{
public:
	Person(char* name, int age)
	{
		this->pName = new char[strlen(name) + 1];
		strcpy(this->pName, name);
		this->mAge = age;
	}

	Person(const Person& p)
	{
		this->pName = new char[strlen(p.pName) + 1];
		strcpy(this->pName, p.pName);
		this->mAge = p.mAge;
	}

	Person& operator=(const Person& p)
	{
		if (this->pName != NULL)
		{
			delete[] this->pName;
		}

		this->pName = new char[strlen(p.pName) + 1];
		this->pName = p.pName;
		this->mAge = p.mAge;

		return *this;
	}

	~Person()
	{
		if (this->pName != NULL)
		{
			delete[] this->pName;
		}
	}
public:
	char* pName;//指针 （容易出现浅拷贝问题）
	int mAge;
};

void test01()
{
	Person p("aa", 30);
	vector<Person> vPerson;
	vPerson.push_back(p);
}

int main()
{
	test01();

	system("pause");
	return 0;
}