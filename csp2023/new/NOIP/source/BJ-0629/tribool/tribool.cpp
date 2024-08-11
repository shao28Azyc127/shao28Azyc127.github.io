#include <bits/stdc++.h>
#define maxn 100005
#define maxm 100005
using namespace std;

int c,t,m,n;
char x[maxn] = {'0'},s[maxm];
int j[maxm],l[maxm];
int b[maxm];

int dfs(int i)
{
	for(int k = 1;k <= m;k++)
	{
		if((b[k] = 0 || b[k] == 1) && x[l[k]] == 'U' && j[k] == i)	return dfs(i+1)+1;
	}
	return min(dfs(i+1)+1,dfs(i+1));
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin >> c >> t;
	int cnt = 0;
	for(int k = 1;k <= t;k++)
	{
		cnt = 0;
		cin >> n >> m;
		for(int i = 1;i <= m;i++)
		{
			cin >> s[i];
			if((s[i] == 'T' || s[i] == 'U') || s[i] == 'F')
			{
				int gee;
				b[i] = 2;
				cin >> gee;
				x[gee] = s[i];
				if(c == 3 || c == 4)
				{
					cnt++;
				}
			}
			if(s[i] == '+')
			{
				b[i] = 1;
				cin >> j[i] >> l[i];
			}
			if(s[i] == '-')
			{
				b[i] = 0;
				cin >> j[i] >> l[i];
			}
			if(c == 3 || c == 4)
			{
				cout << cnt << endl;
				break;
			}
			
		}
		
	}
	return 0;
}
