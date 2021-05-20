#include <iostream>
using namespace std;
#pragma warning (disable : 4996)

int calcFact(int n)
{
	int res = 1;
	for (int i = n; i > 0; i--)
	{
		res *= i;
	}
	return res;
}

int countZero(int n)
{
	char* num = new char[1000];
	sprintf(num, "%d", n);
	
	int res = 0;
	for (char* p = num; *p != '\0'; p++)
	{
		if (*p == 0 + '0')
		{
			res++;
		}
	}
	return res;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << countZero(calcFact(n)) << endl;
	}
}