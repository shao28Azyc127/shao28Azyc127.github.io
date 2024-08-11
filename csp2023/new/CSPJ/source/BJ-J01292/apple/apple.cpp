#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

int n;

int calc(int x)
{
	if(x % 3 == 0) return 1;
	int res = 0;
	while(true)
	{
		res++;
		int t = x - (x + 2) / 3;
		if(x == t) return res;
		else x = t;
	}
}

signed main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	cin >> n;
	int maxp;
	for(maxp = 1; maxp <= n; maxp *= 2);
	maxp /= 2;
	cout << calc(maxp - 1) << ' ';
	cout << calc(n - 1) << endl;
	
	return 0;
}