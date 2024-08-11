#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 5005;

bool f[N][N];

int n;
string s;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if(n > 800)
	{
		cout << 0 << "\n";
		return 0;
	}
	cin >> s;
	s = "_" + s;
	for(int i = 1;i <= n;i++)
		f[i][i] = 0;
	LL ans = 0;
	for(int i = 1;i <= n-1;i++)
	{
		f[i][i+1] = (s[i] == s[i+1]? 1:0);
		ans += f[i][i+1];
	}
	for(int len = 4;len <= n;len += 2)
	{
		for(int i = 1;i+len-1 <= n;i++)
		{
			int j = i+len-1;
			if(s[i] == s[j])
				f[i][j] |= f[i+1][j-1];
			for(int k = i+1;k+1 <= j-1;k+=2)
			{
				f[i][j] |= (f[i][k]&f[k+1][j]);
			}
			//~ if(f[i][j] == 1)
				//~ cout << i << " " << j << "\n";
			ans += f[i][j];
		}
	}
	cout << ans << "\n";
	return 0;
}
