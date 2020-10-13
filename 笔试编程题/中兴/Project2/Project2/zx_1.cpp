//某公司中有N名员工，给定所有员工工资的清单，财务人员要按照特定的顺序排列员工的工资。
//他按照工资的频次降序排列,即给定清单中所有频次较高的工资将在频次较低的工资之前出现。
//如果相同的数量的员工都有相同的工资，则将按照给定清单中该工资第一次出现的顺序排列。
//写一个算法来帮助财务人员排列员工工资的顺序。
//输入：
//该函数 / 方法的输入包括两个参数------
//num，一个整数，表示员工的人数
//salaries，一个正整数列表，表示N名员工的工资
//输出：
//返回一个正整数列表，该列表按照员工工资的频次排序。
//约束条件：
//1<num<100000
//1<salaries<1000000000
//0<i<num
//示例：
//输入：
//num = 19
//salaries = [10000, 20000, 40000, 30000, 30000, 30000, 40000, 20000, 50000,50000, 50000, 50000, 60000, 60000, 60000, 70000, 80000, 
//90000, 100000]
//输出：
//[50000, 50000, 50000, 50000, 30000, 30000, 30000, 60000, 60000,60000, 20000, 20000, 40000, 40000, 10000, 70000, 80000, 90000, 100000]
//分析：本题要求把根据数据出现的频数从高到低排序，所以基本的思路是算出每个数的频次，然后直接从高到低排序。
//可是这样会出现一个问题，频次相同的数据没法排序。比如 20 40 20 40 50 这组数据分别得到频次 2 2 2 2 1，本身就是一个降序排序，所以最后
//结果还是20 40 20 40 50 那怎么办呢？我们可以上面那种数据中间那个20为例，即20 40 20 40 50。首先我们来判断20的前半部分是否存在20，如果
//存在20的话则插入到该20的后面即可，即变为20 20 40 40 50。所有排序过程均使用插入排序。插入排序的详细原理读者可以自行百度，插入排序从
//后往前移动，移动过程中不会改变原有已经排列好的数字的顺序。
//思路：1.计算每个数的频数。
//2.根据频数的大小，对数据从高到低排序。排序的方法使用插入排序。
//3.对第2部排好序的结果再排序。这次从前向后遍历，判断该数的前半部分是否存在该数，存在的话就插入到最近和它相同数的后面。

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> salaryfrequeny(int num, int* salary)
{
	int i, j, k;
	int temp_frequency;
	int temp_salary;
	vector<int> result;
	//int frequency[num];
	int *frequency = new int[num]; // 频次
	for (i = 0; i < num; i++) // 给频次赋初值
	{
		frequency[i] = 0;
	}

	for (i = 0; i < num; i++) // 对已排序的数据统计频次
	{
		for (j = 0; j < num; j++)
		{
			if (salary[i] == salary[j])
			{
				frequency[i]++;
			}
		}
	}

	for (i = 1; i < num; i++) // 对频次进行插入排序，同时根据频数交换的顺序排列原数据
	{
		temp_frequency = frequency[i];
		temp_salary = salary[i];
		j = i - 1;
		while (j >= 0 && temp_frequency > frequency[j]) //频次递减排序
		{
			frequency[j + 1] = frequency[j];
			salary[j + 1] = salary[j]; // 变换原数据
			j--;
		}
		frequency[j + 1] = temp_frequency;
		salary[j + 1] = temp_salary;
	}

	for (i = 1; i < num; i++) // 再进行一次插入排序
	{
		temp_salary = salary[i];
		j = i - 1;
		k = i - 1;
		while (k >= 0)
		{
			if (temp_salary == salary[k]) // 判断前半部分子序列是否存在当前数据
			{
				while (j >= 0 && temp_salary != salary[j]) // 插入到相同的数的后面
				{
					salary[j + 1] = salary[j];
					j--;
				}
				salary[j + 1] = temp_salary;
				break; // 退出循环判断下个数
			}
			k--;
		}
	}

	for (i = 0; i < num; i++)
	{
		result.push_back(salary[i]);
	}
	return result;
}

int main()
{
	//int num = 19;
	//int slalay[19] = { 10000, 20000, 40000, 30000, 30000, 30000, 40000, 20000, 50000,
	//	50000, 50000, 50000, 60000, 60000, 60000, 70000, 80000, 90000, 100000 };// 测试数据
	int num = 6;
	int salary[6] = { 20, 40, 30, 40, 50, 20 };
	vector<int> salaryResult;
	salaryResult = salaryfrequeny(num, salary); // 保存结果
	int i;
	printf("输出结果为：");
	for (i = 0; i < num; i++)// 输出结果
	{
		printf("%d ", salaryResult[i]);
	}
	system("pause");
	return 0;
}