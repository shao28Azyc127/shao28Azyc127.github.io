#include <iostream>
#include <cstdio>

using namespace std;

long long int n;

int main ()
{
	freopen ("apple.in", "r", stdin);
	freopen ("apple.out", "w", stdout);
	long long int i;
	cin >> n;
	if (n <= 5)
	{
		if (n == 1)
		{
			cout << 1 << " " << 1 << endl;
			return 0;
		}
		else
		{
			cout << n - 1 << " ";
		}
	}
	else
	{
		cout << 5 << " ";
	}
	if (n % 3 == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	if (n % 9 == 6 || n % 9 == 2)
	{
		cout << 2 << endl;
		return 0;
	}
	if (n % 9 == 3 || n % 9 == 0)
	{
		cout << 3 << endl;
		return 0;
	}
	if (n % 9 == 5)
	{
		cout << 4 << endl;
	}
	else
	{
		cout << 5 << endl;
	}
	return 0;
}
