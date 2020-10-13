#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Singleton_lazy
{
private:
	Singleton_lazy(){}
	static Singleton_lazy* getInstance()
	{
		if (pSingleton == NULL)
		{
			pSingleton = new Singleton_lazy;
		}
		return pSingleton;
	}
private:
	static Singleton_lazy* pSingleton;
};

//类外初始化
Singleton_lazy* Singleton_lazy::pSingleton = NULL;

int main()
{


	system("pause");
	return 0;
}