#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

bool f[8005][8005]={};

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    string a;
    cin >> n;
    cin >> a;
    a = ' ' + a;
    int l = a.size() - 1;
    for(int i = 1;i <= n;i++)
    {
    	if(a[i] == a[i+1])
    	{
    		f[2][i] = 1;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(f[2][i] != 0 && f[2][i+2] != 0)
		{
			f[4][i] = 1;
		}
	}
    for(int i = 4;i <= l;i += 2)
    {
    	for(int j = 1;j <= n;j++)
    	{
    		if(a[j] == a[j + i - 1] && f[i - 2][j + 1] != 0)
    		{
    			f[i][j] = 1;
			}
		}
		for(int j = 1;j <= n;j++)
		{
			for(int k = 2;k <= i;k++)
			{
				if(f[i][j] != 0 && f[k][i+j] != 0)
				{
					f[i+k][j] = 1;
				}
			}
		}
	}
	for(int i = 2;i <= l;i += 2)
    {
    	for(int j = 1;j <= n;j++)
    	{
    		if(a[j] == a[j + i - 1] && f[i - 2][j + 1] != 0)
    		{
    			f[i][j] = 1;
			}
		}
		for(int j = 1;j <= n;j++)
		{
			for(int k = 2;k <= l;k++)
			{
				if(f[i][j] != 0 && f[k][i+j] != 0)
				{
					f[i+k][j] = 1;
				}
			}
		}
	}
	long long ans = 0;
	for(int i = 2;i <= l;i+=2)
	{
		for(int j = 1;j <= n;j++)
		{
			ans+=f[i][j];
		}
	}
	cout << ans << endl;
    return 0;
}
