#include <bits/stdc++.h>
#define maxn 3005
using namespace std;

int m,n,f[maxn],cmp;
string s[maxn];
bool fi[maxn];

bool campa(int a,int b,int i)
{
	if(s[a][i] == s[b][i])
	{
		return campa(a,b,i+1);
	}
	if(s[a][i] < s[b][i])
	{
		return 1;
	}
	cmp = i;
	return 0;
}

bool dfs(int i)
{
	bool bo = 1;
	int fw = 0;
	for(int j = 1;j <= n;j++)
	{
		if(i == j)
		{
			continue;
		}
		if(!campa(i,j,0))
		{
			bo = 0;
			f[j] = 1;
			continue;
		}
		fi[j] = 0;
	}
	if(bo)
	{
		return 1;
	}
	else
	{
		for(int k = 1;k <= n;k++)
		{
			if(f[n] || k == i)
			{
				continue;
			}
			for(int j = 0;j < m;j++)
			{
				//cout << s[i][cmp] << " " << s[k][j] << endl;
				if(s[i][cmp]<s[k][j] && fw >= 1)
				{
					return 1;
				}
				else if(s[i][cmp]<s[k][j])
				{
					fw++;
				}
			}
		}
	}
	return 0;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> s[i];
		fi[i] = 1;
	}
	if(n == 1)
	{
		cout << "1";
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		cout << dfs(i);
	}
	return 0;
}
