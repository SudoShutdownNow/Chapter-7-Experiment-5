#include <iostream>
using namespace std;

int module(unsigned a, unsigned p, int m)
{
	if (p == 0)
	{
		return 1;
	}
	if (p % 2)
	{
		return a * module(a, p - 1, m) % m;
	}
	a = module(a, p / 2, m);
	return a * a % m;
}

int main()
{
	for (unsigned a, p, m; cin >> a >> p >> m;)
	{
		cout << module(a % m, p, m) << endl;
	}
}