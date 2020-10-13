#include <iostream>
#include <string>
#include <list>

using namespace std;

bool isChar(char i)
{
	return i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z';
}

bool isNum(char i)
{
	return i >= '0' && i <= '9';
}

bool isSpe(char i)
{
	return i >= '!' && i <= '*' || i == '^';
}

void parse_str(char* str)
{
	int length = strlen(str);
	// statement 0: begin; 1: number; 2: string begin; 3: input "; 4: string; 5: error
	int state = 0;
	int str_count = 0;
	list<string> strlist;
	string cache;
	for (int i = 0; i < length; ++i)
	{
		switch (state)
		{
		case 0:
			if (str[i] == ',')
			{
				state = 0;
				strlist.push_back(string("--"));
				cache = string();
			}
			else if (isNum(str[i]))
			{
				state = 1;
				cache.push_back(str[i]);
			}
			else if (isChar(str[i]))
			{ 
				state = 4;
				cache.push_back(str[i]);
			}
			else if (str[i] == '\"')
			{
				state = 2;
			}
			else
			{
				printf("ERROR\n");
				return;
			}
			break;
		case 1:
			if (isNum(str[i]))
			{
				state = 1;
				cache.push_back(str[i]);
			}
			else if (str[i] == ',')
			{
				state = 0;
				strlist.push_back(cache);
				cache = string();
			}
			else
			{
				printf("ERROR\n");
				return;
			}
			break;
		case 2:
			if (str[i] == '"')
			{
				state = 3;
			}
			else if (isNum(str[i]) || isChar(str[i]) || str[i] == ',' || str[i] == '^')
			{
				state = 2;
				cache.push_back(str[i]);
			}
			else
			{
				printf("ERROR\n");
				return;
			}
			break;
		case 3:
			if (str[i] == '"')
			{
				state = 2;
				cache.push_back('\"');
			}
			else if (str[i] == ',')
			{
				state = 0;
				strlist.push_back(cache);
				cache = string();
			}
			else
			{
				printf("ERROR\n");
				return;
			}
			break;
		case 4:
			if (str[i] == ',')
			{
				state = 0;
				strlist.push_back(cache);
				cache = string();
			}
			else if (isChar(str[i]))
			{
				cache.push_back(str[i]);
			}
			else
			{
				printf("ERROR\n");
				return;

			}
			break;
		default:
			printf("ERROR\n");
			return;
		}
	}
	strlist.push_back(cache);
	printf("%d\n", strlist.size());
	for (auto s = strlist.begin(); s != strlist.end(); ++s)
	{
		printf("%s\n", (*s).c_str());
	}
	return;
}

int main(int argc, char* argv)
{
	parse_str("a,,1,\"b,\"\"\"");
	getchar();
}