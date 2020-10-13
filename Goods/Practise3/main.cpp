#include<iostream>

using namespace std;

class Goods
{
public:
	Goods()
	{
		weight = 0;
		next = NULL;
		cout << "创建了一个重量为" << weight << "的货物" << endl;
	}

	Goods(int w)
	{
		weight = w;
		next = NULL;
		total_weight += w;
		cout << "创建了一个重量为" << weight << "的货物" << endl;
	}

	~Goods()
	{
		cout << "删除了一箱重量为" << weight << "的货物" << endl;
		total_weight -= weight;
	}

	static int get_total_weight()
	{
		return total_weight;
	}

	Goods* next;
private:
	int weight;//重量
	static int total_weight;//总重量
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
		cout << "仓库中已经没有货物了。。" << endl;
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

	Goods *head = NULL; //所有货物的表头

	do {
		cout << "1 进货" << endl;
		cout << "2 出货" << endl;
		cout << "0 退出" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			//进货
			cout << "请输入要创建的货物的重量" << endl;
			int w;
			cin >> w;
			buy(head, w);
			break;
		case 2:
			//出货
			sale(head);
			break;
		case 0:
			return 0;
			break;
		default:
			break;
		}

		cout << "此时仓库中有 " << Goods::get_total_weight() << "重量的货物" << endl;
	} while (1);
	system("pause");
	return 0;
}