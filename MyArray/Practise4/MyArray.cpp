#include "MyArray.h"

MyArray::MyArray()
{
	cout << "MyArray()..." << endl;
	this->len = 0;
	this->space = NULL;
}

MyArray::MyArray(int len)
{
	cout << "MyArray(int len)..." << endl;
	if (len <= 0)
	{
		this->len = 0;
		return;
	}
	else
	{
		this->len = len;
		this->space = new int[this->len];
	}
}

MyArray::MyArray(const MyArray &another)
{
	cout << "MyArray(const MyArray &another)..." << endl;
	if (another.len > 0)
	{
		this->len = another.len;

		//Éî¿½±´
		this->space = new int[this->len];
		for (int i = 0; i<this->len; i++)
		{
			this->space[i] = another.space[i];
		}
	}
	else
	{
		return;
	}
}
void MyArray::setData(int index, int data)
{
	if ((index > this->len) || (index < 0) || (this->space == NULL))
	{
		return;
	}
	else
	{
		this->space[index] = data;
	}
}
int MyArray::getData(int index)
{
	if ((index > this->len) || (index < 0) || (this->space == NULL))
	{
		return -1;
	}
	else
	{
		return this->space[index];
	}
}
int MyArray::getLen()
{
	if (this->space == NULL)
	{
		return -1;
	}
	else
	{
		return this->len;
	}
}

MyArray::~MyArray()
{
	cout << "~MyArray()..." << endl;
	if (this->space != NULL)
	{
		delete[] this->space;
		this->space = NULL;
		this->len = 0;
	}
}
