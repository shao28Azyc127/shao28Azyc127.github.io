#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n , d , ans = -1;
int main()
{
	freopen("apple.in" , "r" , stdin);
	freopen("apple.out" , "w" , stdout);
	cin >> n;
	while (n)
	{
		d++;
		if (n % 3 == 1 && ans == -1)ans = d;
		n -= max(n - 1 , 1) / 3 + 1;
	}
	cout << d << " " << ans;
	return 0;
}
