#include<iostream>

using namespace std;

class Goods
{
public:
	Goods()
	{
		weight = 0;
		next = NULL;
		cout << "������һ������Ϊ" << weight << "�Ļ���" << endl;
	}

	Goods(int w)
	{
		weight = w;
		next = NULL;
		total_weight += w;
		cout << "������һ������Ϊ" << weight << "�Ļ���" << endl;
	}

	~Goods()
	{
		cout << "ɾ����һ������Ϊ" << weight << "�Ļ���" << endl;
		total_weight -= weight;
	}

	static int get_total_weight()
	{
		return total_weight;
	}

	Goods* next;
private:
	int weight;//����
	static int total_weight;//������
};

int Goods::total_weight = 0;

void buy(Goods* &head, int w)
{
	Goods* new_goods = new Goods(w);
	if (head == NULL)
	{
		head = new_goods;
	}
	else
	{
		new_goods->next = head;
		head = new_goods;
	}
}

void sale(Goods* &head)
{
	if (head == NULL)
	{
		cout << "�ֿ����Ѿ�û�л����ˡ���" << endl;
		return;
	}
	Goods* temp;
	temp = head;
	head = head->next;
	delete temp;
	cout << "saled." << endl;
}

int main()
{
	int choice = 0;

	Goods *head = NULL; //���л���ı�ͷ

	do {
		cout << "1 ����" << endl;
		cout << "2 ����" << endl;
		cout << "0 �˳�" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			//����
			cout << "������Ҫ�����Ļ��������" << endl;
			int w;
			cin >> w;
			buy(head, w);
			break;
		case 2:
			//����
			sale(head);
			break;
		case 0:
			return 0;
			break;
		default:
			break;
		}

		cout << "��ʱ�ֿ����� " << Goods::get_total_weight() << "�����Ļ���" << endl;
	} while (1);
	system("pause");
	return 0;
}