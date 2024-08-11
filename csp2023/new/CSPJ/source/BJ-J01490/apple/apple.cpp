#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n, day = 0, pos = 0;
	cin >> n;
	while (n)
	{
		int now = ceil(1.0 * n / 3);
		day++;
		if (n % 3 == 1 && pos == 0) pos = day;
		n -= now;
	}
	cout << day << " " << pos << endl;
	return 0;
}