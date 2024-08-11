#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n, ans;
	cin >> n;
	bool a[1000010];
	for(int i = 1; i <= n; i++) a[i] = true;
	int cnt = 0, day = 0;
	while(cnt < n)
	{
		day++;
		int pos = 1;
		for(int i = 1; i <= n; i++)
			if(a[i]) 
			{
				pos = i;
				break;
			}
		int x = 2;
		for(int i = pos; i <= n; i++)
		{
			if(!a[i])
				continue;
			if(x < 2)
			{
				x++;
				continue;
			}
			cnt++;
			if(i == n)
			{
				a[i] = false;
				ans = day;
				break;
			}
			a[i] = false;
			x = 0;
		}
	}
	cout << day << " " << ans << endl;
	return 0;
}