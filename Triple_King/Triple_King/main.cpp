#include<iostream>

using namespace std;
//�����----------------
//����𿪽��ҷ���������
typedef void(TIPS)(void);

//�������
struct tip
{
	char from[64];//˭д��
	char to[64];//��˭��
	//���ҵ�����
	TIPS *tp;//�൱�ڳ�����Ĵ��麯��
};

//��Ҫһ���򿪽��ҵļܹ�����
void open_tips(struct tip *tip_p)
{
	cout << "���˽���" << endl;
	cout << "�˽�������" << tip_p->from << "д��" << tip_p->to << "��" << endl;
	cout << "�����ǣ�" << endl;
	tip_p->tp();//��ʱ������̬
}

//�ṩһ���������ҵķ���
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

//�ṩһ�����ٽ��ҵķ���
void destory_tip(struct tip *tp)
{
	if (tp != NULL)
	{
		free(tp);
		tp = NULL;
	}
}

//ʵ�ֲ�----------------
//��������
void tip1_func(void)
{
	cout << "һ������Ͱݼ��ǹ��ϣ�" << endl;
}

void tip2_func(void)
{
	cout << "����������ͻѳƲܾ���Ϯ��" << endl;
}

void tip3_func(void)
{
	cout << "�������Ȩ׷ɱ��������������ȣ�" << endl;
}

//ҵ���----------------
int main()
{
	struct tip *tip1 = creat_tip("����", "����", tip1_func);
	struct tip *tip2 = creat_tip("����", "����", tip2_func);
	struct tip *tip3 = creat_tip("����", "����", tip3_func);

	//�����ƽ��в����
	cout << "�ո��������⣬���ƴ򿪵�һ������"<< endl;
	open_tips(tip1);
	cout << "----------" << endl;
	cout << "�������������ƴ򿪵ڶ�������" << endl;
	open_tips(tip2);
	cout << "----------" << endl;
	cout << "�����׷ɱ�����ƴ򿪵���������" << endl;
	open_tips(tip3);
	cout << "----------" << endl;

	destory_tip(tip1);
	destory_tip(tip2);
	destory_tip(tip3);
	
	system("pause");
	return 0;
}