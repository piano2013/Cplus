#include<iostream>

using namespace std;
//抽象层----------------
//定义拆开锦囊方法的类型
typedef void(TIPS)(void);

//定义锦囊
struct tip
{
	char from[64];//谁写的
	char to[64];//给谁的
	//锦囊的内容
	TIPS *tp;//相当于抽象类的纯虚函数
};

//需要一个打开锦囊的架构函数
void open_tips(struct tip *tip_p)
{
	cout << "打开了锦囊" << endl;
	cout << "此锦囊是由" << tip_p->from << "写给" << tip_p->to << "的" << endl;
	cout << "内容是：" << endl;
	tip_p->tp();//此时发生多态
}

//提供一个创建锦囊的方法
struct tip* creat_tip(char *from, char *to, TIPS *tp)
{
	struct tip *temp = (struct tip*)malloc(sizeof(struct tip));
	if (temp == NULL)
	{
		return NULL;
	}
	strcpy_s(temp->from, from);
	strcpy_s(temp->to, to);
	temp->tp = tp;

	return temp;
}

//提供一个销毁锦囊的方法
void destory_tip(struct tip *tp)
{
	if (tp != NULL)
	{
		free(tp);
		tp = NULL;
	}
}

//实现层----------------
//三个锦囊
void tip1_func(void)
{
	cout << "一到东吴就拜见乔国老！" << endl;
}

void tip2_func(void)
{
	cout << "如果被留，就谎称曹军来袭！" << endl;
}

void tip3_func(void)
{
	cout << "如果被孙权追杀，就向孙尚香求救！" << endl;
}

//业务层----------------
int main()
{
	struct tip *tip1 = creat_tip("孔明", "赵云", tip1_func);
	struct tip *tip2 = creat_tip("孔明", "赵云", tip2_func);
	struct tip *tip3 = creat_tip("孔明", "赵云", tip3_func);

	//由赵云进行拆锦囊
	cout << "刚刚来到东吴，赵云打开第一个锦囊"<< endl;
	open_tips(tip1);
	cout << "----------" << endl;
	cout << "刘备被困，赵云打开第二个锦囊" << endl;
	open_tips(tip2);
	cout << "----------" << endl;
	cout << "被吴军追杀，赵云打开第三个锦囊" << endl;
	open_tips(tip3);
	cout << "----------" << endl;

	destory_tip(tip1);
	destory_tip(tip2);
	destory_tip(tip3);
	
	system("pause");
	return 0;
}