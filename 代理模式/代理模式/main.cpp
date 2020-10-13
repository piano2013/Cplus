#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;


//�ṩһ�ִ��������ƶ������ķ���

class AbstractCommonInterface {
public:
	virtual void run() = 0;
};
//�Ѿ�д�õ�ϵͳ
class MySystem {
public:
	virtual void run() {
		cout << "Engine start!..." << endl;
	};
};
//����Ҫ��Ȩ����֤(ͨ������ȥ���ʶ���)(�ṩ�û���������)
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
			cout << "�û�����������ȷ����֤ͨ��������" << endl;
			this->pSystem->run();
		}
		else
		{
			cout << "�û��������������Ȩ�޲��㣡" << endl;
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