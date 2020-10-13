#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Parent
{
public:
	Parent(int age) :age(age){}

	//�麯��->��д��������̬��
	virtual void print()
	{
		cout << this->age << endl;
	}

	/*��ͨ����->�ض��壨��������̬��
	void print()
	{
		cout << this->age << endl;
	}*/
public:
	int age;
};

class Child:public Parent
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

void Print(Parent& p)
{
	p.print();
}

int main()
{
	Parent p(40);
	Child c(12, 90);

	Print(p);
	Print((Parent&)c);

	system("pause");
	return 0;
}