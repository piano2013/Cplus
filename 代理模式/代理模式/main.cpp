#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;


//提供一种代理来控制对其对象的访问

class AbstractCommonInterface {
public:
	virtual void run() = 0;
};
//已经写好的系统
class MySystem {
public:
	virtual void run() {
		cout << "Engine start!..." << endl;
	};
};
//必须要有权限验证(通过代理去访问对象)(提供用户名、密码)
class MySystemProxy :public AbstractCommonInterface {
public:
	MySystemProxy(string username, string password){
		this->mUsername = username;
		this->mPassword = password;
		pSystem = new MySystem;
	}

	bool checkUsernameAndPassword()
	{
		if (mUsername == "admin"&&mPassword == "admin")
		{
			return true;
		}
		return false;
	}

	virtual void run() {
		if (checkUsernameAndPassword())
		{
			cout << "用户名和密码正确，验证通过。。。" << endl;
			this->pSystem->run();
		}
		else
		{
			cout << "用户名或者密码错误，权限不足！" << endl;
		}
	}

	~MySystemProxy() {
		if (pSystem != NULL)
		{
			delete pSystem;
			pSystem = NULL;
		}
	}
public:
	MySystem* pSystem;
	string mUsername;
	string mPassword;
};

void test()
{
	MySystemProxy* system = new MySystemProxy("admin", "admin");
	system->run();
}

int main()
{
	test();

	system("pause");
	return 0;
}