#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
bool vis[1000009];

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin >> n;
	int ans = 0;
	int cnt = 0;
	int ansn = 0;
	while (cnt < n)
	{
		ans++;
		int mod = 0;
		for (int i=1;i<=n;i++)
		{
			if (!vis[i])
			{
				if (mod%3 == 0)
				{
					vis[i] = true;
					cnt++;
					if (i == n) ansn = ans;
				}
				mod++;
			}
		}
	}
	cout << ans << " " << ansn;
	return 0;
}