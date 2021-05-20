#include <iostream>
using namespace std;
#define MAX 100
#pragma warning(disable : 4996)

int calc(int n, bool* symbols)
{
	bool* p = symbols;
	int res = 1;
	for (int i = 2; i <= n; i++)
	{
		if (*p == true)
		{
			res += i;
			p++;
		}
		else if (*p == false)
		{
			res -= i;
			p++;
		}
	}

	return res;
}

bool* generateSym(char* bin,int N)
{
	char* p = bin + strlen(bin) - 1;
	bool* res = new bool[MAX];
	bool* r = res + N - 2;
	int j = 1;
	for (int i = 1; i <= strlen(bin); i++)
	{
		*r = *p - '0';
		r--;
		p--;
		j++;
	}

	while (j < N)
	{
		*r = false;
		r--;
		j++;
	}

	return res;
}

int trySym(int N, int M)
{
	int res = 0;
	for (int i = 0; i <= pow(2, N-1) -1; i++)
	{

		char* symNum = new char[MAX];
		itoa(i, symNum, 2);
		if (calc(N, generateSym(symNum, N)) == M)
		{
			res++;
		}
	}
	return res;
}

int main()
{
	int N, M,temp;
	while (cin >> N >> M)
	{
		temp = trySym(N, M);
		if (temp == 0)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << temp << endl;
		}
	}
	
}

