#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct node{ //结构体表示倒水过程中的状态
	int a, b, c;
	int step; //step表示到当前这个状态所需要的步骤数
}b, e; //b、e分别表示开始状态和目标状态
int v1, v2, v3;
bool f[105][105][105]; //f(flag)表示三个杯子的这种状态是否讨论过，可以判重
//宽搜其他题比如要用hash值也是为了避免重复判断状态，节省时间

int bfs(node b)
{
	queue<node> q; //一般宽搜都用队列实现
	q.push(b);
	f[b.a][b.b][b.c] = true;

	node cur;
	while (!q.empty()) //6种倒水情况 ：耐心，其实懂了一个其他都可以复制粘贴加一点小修改
	{
		cur = q.front();
		if (cur.a == e.a && cur.b == e.b && cur.c == e.c) //搜索到了就返回，也算个剪枝
			return cur.step;
		q.pop();

		if (cur.a>0 && cur.b<v2) //v1往v2中倒水
		{
			int t = min(cur.a, v2 - cur.b); //重点理解 两个杯子中水的改变量倒水瓶中所有的水和被灌水瓶剩的部分中的最小值
			node temp;
			temp.a = cur.a - t;
			temp.b = cur.b + t;
			temp.c = cur.c;
			temp.step = cur.step + 1; //步数加1
			if (!f[temp.a][temp.b][temp.c])
			{
				q.push(temp);
				f[temp.a][temp.b][temp.c] = true;
			}
		}

		if (cur.a>0 && cur.c<v3) //v1往v3中倒水
		{
			int t = min(cur.a, v3 - cur.c); //重点理解
			node temp;
			temp.a = cur.a - t;
			temp.b = cur.b;
			temp.c = cur.c + t;
			temp.step = cur.step + 1; //步骤数加1
			if (!f[temp.a][temp.b][temp.c])
			{
				q.push(temp);
				f[temp.a][temp.b][temp.c] = true;
			}
		}

		if (cur.b>0 && cur.a<v1) //v2往v1中倒水
		{
			int t = min(cur.b, v1 - cur.a); //重点理解
			node temp;
			temp.a = cur.a + t;
			temp.b = cur.b - t;
			temp.c = cur.c;
			temp.step = cur.step + 1; //步骤数加1
			if (!f[temp.a][temp.b][temp.c])
			{
				q.push(temp);
				f[temp.a][temp.b][temp.c] = true;
			}
		}

		if (cur.b>0 && cur.c<v3) //v2往v3中倒水
		{
			int t = min(cur.b, v3 - cur.c); //重点理解
			node temp;
			temp.a = cur.a;
			temp.b = cur.b - t;
			temp.c = cur.c + t;
			temp.step = cur.step + 1; //步骤数加1
			if (!f[temp.a][temp.b][temp.c])
			{
				q.push(temp);
				f[temp.a][temp.b][temp.c] = true;
			}
		}

		if (cur.c>0 && cur.a<v1) //v3往v1中倒水
		{
			int t = min(cur.c, v1 - cur.a); //重点理解
			node temp;
			temp.a = cur.a + t;
			temp.b = cur.b;
			temp.c = cur.c - t;
			temp.step = cur.step + 1; //步骤数加1
			if (!f[temp.a][temp.b][temp.c])
			{
				q.push(temp);
				f[temp.a][temp.b][temp.c] = true;
			}
		}

		if (cur.c>0 && cur.b<v2) //v3往v2中倒水
		{
			int t = min(cur.c, v2 - cur.b); //重点理解
			node temp;
			temp.a = cur.a;
			temp.b = cur.b + t;
			temp.c = cur.c - t;
			temp.step = cur.step + 1; //步骤数加1
			if (!f[temp.a][temp.b][temp.c])
			{
				q.push(temp);
				f[temp.a][temp.b][temp.c] = true;
			}
		}
	}
	return -1; //表示仍然找不到目标状态
}
int main()
{
	cin >> v1 >> v2 >> v3;
	b.a = 0; b.b = 0; b.c = 0; b.step = 0; //初始化
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
	//cin >> e.a >> e.b >> e.c; //目标状态
	memset(f, 0, sizeof(f)); //每次都要将标记清零，故放在循环里
	//if (val != e.a + e.b + e.c) //因为这样是肯定找不到的
	//	cout << "-1" << endl;
	cout << bfs(b) << endl; //否则宽搜
	system("pause");
	return 0;
}