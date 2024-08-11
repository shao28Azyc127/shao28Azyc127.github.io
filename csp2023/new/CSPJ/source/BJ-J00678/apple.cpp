#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n, t, ans1 = 0, ans2 = 1;
	scanf("%d", &t);
	n = t;
	while(n > 3)
	{
		n = n - n / 3;
		if(n % 3 != 0)n--;
		ans1++;
	}
	ans1+=n;
	n = t;
	while(n % 3 != 1)
	{
		if(n == 3)n = n - 1;
		else n = n - n / 3 - 1;
		ans2++;
	}
	cout << ans1 << " " << ans2;
	return 0;
}
