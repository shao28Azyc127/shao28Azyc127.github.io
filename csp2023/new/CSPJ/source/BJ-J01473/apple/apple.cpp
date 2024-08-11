#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n;
	cin >> n;
	int flag = n, flag1 = 0;
	int ans1 = 0, ans2 = 0;
	while(flag > 1)
	{
		ans1++;
		if(ans2 == 0)
			flag1++;
		if(flag % 3 == 1)
			ans2 = flag1;
		flag -= (flag + 2) / 3;
	}
	if(n != 0)
		ans1++, flag1++;
	if(ans2 == 0)
		ans2 = flag1;
	cout << ans1 << " " << ans2;
	return 0;
}