#include <bits/stdc++.h>
using namespace std;

int n,cnt,flag[2000005];
char c[2000005];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> c[i];
	for (int len = 1;len <= n;len++)
	{
		for (int i = 1;i+len-1 <= n;i++)
		{
			string s;
			for (int k = i;k <= i+len-1;k++)
			{
				s += c[k];
			}
			//cout << s << endl;
			memset(flag,0,sizeof flag);
			int f = 1,m = s.size();
			if (m%2 == 1) continue;
			while (f == 1)
			{
				f = 0;
				int l = s.size();
				for (int k = 0;k < l-1;k++)
				{
					if (flag[k] == 1) continue;
					int j = k+1;
					while (j < l)
					{
						if (flag[j] == 0)
						{
							break;
						}
						j++;
					}
					if (s[k] == s[j])
					{
						flag[k] = flag[j] = 1;
						m -= 2;
						f = 1;
					}
				}
			}
			if (m == 0) 
			{
				//cout << s << endl;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	
	return 0;
}
