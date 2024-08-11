#include<bits/stdc++.h>
using namespace std;
bool flag[300000010];
int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int cnt = 0, num = 0;
		for(int j = 1; j <= n; j++)
		{
			if(flag[j])
			{
				continue;
			}
			if(num == 0)
			{
				flag[j] = 1;
				cnt++;
			}
			num = (num + 1) % 3;
		}
		if(flag[n] == 1 && ans == 0)
		{
			ans = i;
		}
		if(cnt == 0)
		{
			cout << i - 1 << " " << ans << endl;
			break;
		}
	}
	return 0;
}