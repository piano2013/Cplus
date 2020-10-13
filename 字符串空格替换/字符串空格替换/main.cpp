#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(char c)
{
	cout << c;
}

//Ìæ»»¿Õ¸ñ
void transform(char* str,vector<char>& arr)
{
	if (str == NULL)
	{
		return;
	}
	char p[] = { '%', '2', '0' };
	while (*str != '\0')
	{	
		if (*str == ' ')
		{		
			for (int i = 0; i < 3; i++)
			{
				arr.push_back(p[i]);
			}
		}
		else
		{
			arr.push_back(*str);
		}		
		str++;
	}
}


int main()
{
	char arr[] = "We are happy";
	vector<char> arr2;
	transform(arr,arr2);
	for_each(arr2.begin(), arr2.end(), print);

	cout << endl;
	system("pause");
	return 0;
}