#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct node{ //�ṹ���ʾ��ˮ�����е�״̬
	int a, b, c;
	int step; //step��ʾ����ǰ���״̬����Ҫ�Ĳ�����
}b, e; //b��e�ֱ��ʾ��ʼ״̬��Ŀ��״̬
int v1, v2, v3;
bool f[105][105][105]; //f(flag)��ʾ�������ӵ�����״̬�Ƿ����۹�����������
//�������������Ҫ��hashֵҲ��Ϊ�˱����ظ��ж�״̬����ʡʱ��

int bfs(node b)
{
	queue<node> q; //һ����Ѷ��ö���ʵ��
	q.push(b);
	f[b.a][b.b][b.c] = true;

	node cur;
	while (!q.empty()) //6�ֵ�ˮ��� �����ģ���ʵ����һ�����������Ը���ճ����һ��С�޸�
	{
		cur = q.front();
		if (cur.a == e.a && cur.b == e.b && cur.c == e.c) //�������˾ͷ��أ�Ҳ�����֦
			return cur.step;
		q.pop();

		if (cur.a>0 && cur.b<v2) //v1��v2�е�ˮ
		{
			int t = min(cur.a, v2 - cur.b); //�ص���� ����������ˮ�ĸı�����ˮƿ�����е�ˮ�ͱ���ˮƿʣ�Ĳ����е���Сֵ
			node temp;
			temp.a = cur.a - t;
			temp.b = cur.b + t;
			temp.c = cur.c;
			temp.step = cur.step + 1; //������1
			if (!f[temp.a][temp.b][temp.c])
			{
				q.push(temp);
				f[temp.a][temp.b][temp.c] = true;
			}
		}

		if (cur.a>0 && cur.c<v3) //v1��v3�е�ˮ
		{
			int t = min(cur.a, v3 - cur.c); //�ص����
			node temp;
			temp.a = cur.a - t;
			temp.b = cur.b;
			temp.c = cur.c + t;
			temp.step = cur.step + 1; //��������1
			if (!f[temp.a][temp.b][temp.c])
			{
				q.push(temp);
				f[temp.a][temp.b][temp.c] = true;
			}
		}

		if (cur.b>0 && cur.a<v1) //v2��v1�е�ˮ
		{
			int t = min(cur.b, v1 - cur.a); //�ص����
			node temp;
			temp.a = cur.a + t;
			temp.b = cur.b - t;
			temp.c = cur.c;
			temp.step = cur.step + 1; //��������1
			if (!f[temp.a][temp.b][temp.c])
			{
				q.push(temp);
				f[temp.a][temp.b][temp.c] = true;
			}
		}

		if (cur.b>0 && cur.c<v3) //v2��v3�е�ˮ
		{
			int t = min(cur.b, v3 - cur.c); //�ص����
			node temp;
			temp.a = cur.a;
			temp.b = cur.b - t;
			temp.c = cur.c + t;
			temp.step = cur.step + 1; //��������1
			if (!f[temp.a][temp.b][temp.c])
			{
				q.push(temp);
				f[temp.a][temp.b][temp.c] = true;
			}
		}

		if (cur.c>0 && cur.a<v1) //v3��v1�е�ˮ
		{
			int t = min(cur.c, v1 - cur.a); //�ص����
			node temp;
			temp.a = cur.a + t;
			temp.b = cur.b;
			temp.c = cur.c - t;
			temp.step = cur.step + 1; //��������1
			if (!f[temp.a][temp.b][temp.c])
			{
				q.push(temp);
				f[temp.a][temp.b][temp.c] = true;
			}
		}

		if (cur.c>0 && cur.b<v2) //v3��v2�е�ˮ
		{
			int t = min(cur.c, v2 - cur.b); //�ص����
			node temp;
			temp.a = cur.a;
			temp.b = cur.b + t;
			temp.c = cur.c - t;
			temp.step = cur.step + 1; //��������1
			if (!f[temp.a][temp.b][temp.c])
			{
				q.push(temp);
				f[temp.a][temp.b][temp.c] = true;
			}
		}
	}
	return -1; //��ʾ��Ȼ�Ҳ���Ŀ��״̬
}
int main()
{
	cin >> v1 >> v2 >> v3;
	b.a = 0; b.b = 0; b.c = 0; b.step = 0; //��ʼ��
	int val;
	cin >> val;
	if (val <= v1)
	{
		e.a = val; e.b = 0; e.c = 0;
	}
	else if (val <= v2)
	{
		e.a = 0; e.b = val; e.c = 0;
	}
	else if (val <= v3)
	{
		e.a = 0; e.b = 0; e.c = val;
	}
	//cin >> e.a >> e.b >> e.c; //Ŀ��״̬
	memset(f, 0, sizeof(f)); //ÿ�ζ�Ҫ��������㣬�ʷ���ѭ����
	//if (val != e.a + e.b + e.c) //��Ϊ�����ǿ϶��Ҳ�����
	//	cout << "-1" << endl;
	cout << bfs(b) << endl; //�������
	system("pause");
	return 0;
}