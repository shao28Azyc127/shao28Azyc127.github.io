#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, tmp = 1, ans = 0, a[200000+5], st[100005], fi[100005]; 
	char c[200000+5];
	scanf("%d", &n);
	cin >> c;
	for(int i = 0; i < n; i++)a[i] = c[i] - 'a' + 1;
	for(int i = 2; i <= n; i += 2)
	{
		for(int j = 0; j < n - 1; j++)
		{
			int k = j + i - 1, tmp = 0;
			for(int p = j; p <= k; p++)
			{
				tmp ^= j;
			}
			bool tt = 0;
			if(tmp != 0)continue;
			for(int p = j; p <= k; p++)
			{
				if(!(a[p] & a[k]) && !(a[p] & a[p+1])){tt = 1;break;}
				if((a[p] & a[k])) k--;
				if((a[p] & a[p+1]))p++;
			}
			if(tt == 0) ans++;
		}
	}
	cout << ans;
	return 0;
}
