#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person(){}
	Person(int age, char* name)
	{
		this->age = age;
		strcpy(this->name, name);
	}

	Person& operator=(const Person& another)
	{
		//防止自身赋值
		if (this == &another)
		{
			return *this;
		}

		//回收自身额外开销的空间
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
			this->age = 0;
		}

		//深拷贝
		int len = strlen(another.name);
		this->name = new char[len + 1];
		strcpy(this->name, another.name);
		this->age = another.age;

		//返回引用
		return *this;
	}
	~Person(){}

public:
	int age;
	char* name;
};

int main()
{
	char str1[] = "a";
	char str2[] = "b";
	Person p1(12, str1);
	Person p2(13, str2);
	cout << p1.age << " " << p1.name << endl;
	p1 = p2;
	cout << p1.age << " " << p1.name << endl;

	system("pause");
	return 0;
}