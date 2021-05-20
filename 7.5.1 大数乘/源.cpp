#include <iostream>
#include <stack>
#include <algorithm>
#define MAX 100
using namespace std;
#pragma warning(disable : 4996)

char*& addnum(char* a, char* b)
{
	char* res = new char[MAX];

	char* pa = a + strlen(a) - 1;
	char* pb = b + strlen(b) - 1;
	char* pr = res;
	bool up = false;

	while (pa != NULL || pb != NULL)
	{
		if (up == true)
		{
			*pr = '1' - '0';
			up = false;
		}
		else
		{
			*pr = '0' - '0';
		}

		if (pa != NULL && pb != NULL)
		{
			*pr += *pa + *pb - '0';
		}
		else if (pa != NULL && pb == NULL)
		{
			*pr += *pa;
		}
		else if (pb != NULL && pa == NULL)
		{
			*pr += *pb;
		}

		if (*pr > '9')
		{
			*pr -= 10;
			up = true;
		}

		if (pa == a || pa == NULL)
		{
			pa = NULL;
		}
		else
		{
			pa--;
		}

		if (pb == b || pb == NULL)
		{
			pb = NULL;
		}
		else
		{
			pb--;
		}

		pr++;

	}
	*pr = '\0';

	if (up == true)
	{
		strcat(res, "1");
		up = false;
	}
	res = strrev(res);

	return res;
}

char*& multiply(char* a, char* b)
{
	char *res = new char[MAX];
	strcpy(res, "0");

	char* addtemp = new char[MAX];
	char* at = addtemp;

	char* final = new char[MAX];
	char* r = res;

	int temp = 0, add = 0;//运算结果和进位记录
	int i = 0;//末尾应该补几个0

	if (strlen(a) > strlen(b))//如果a的长度比b长，那就把两个数对换
	{
		char* exchange;
		exchange = a;
		a = b;
		b = exchange;
	}
	char* pa = a + strlen(a) - 1;
	while (1)//a的每一位循环
	{
		char* pb = b + strlen(b) - 1;
		strcpy(addtemp, "0");
		at = addtemp;
		while (1)//b的每一位循环
		{
			temp = (*pa - '0') * (*pb - '0') + add;//本次结果加上上一位的进位
			add = 0;
			if (temp >= 10)
			{
				add = temp / 10;
				temp = temp % 10;
			}
			*at = temp + '0';
			at++;
			if (pb == b)
			{
				break;
			}
			pb--;
		}
		if (add != 0)
		{
			*at = add + '0';
			at++;
		}
		//补零
		*at = '\0';
		addtemp = strrev(addtemp);
		for (int j = 0; j < i; j++)
		{
			*at = '0';
			at++;
		}
		*at = '\0';

		res = addnum(res, addtemp);

		i++;

		if (pa == a)
		{
			break;
		}
		pa--;
	}
	
	return res;
	

}

int main()
{
	char* a = new char[MAX];
	char* b = new char[MAX];

	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
		{
			break;
		}
		cout << multiply(a, b) << endl;
	}
	
}