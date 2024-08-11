#include<bits/stdc++.h>
using namespace std;
int a[1000], b[6], mod = 13;
int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	int t, tmp = 1;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
	{
		for(int j = 1; j <= 5; j++)scanf("%d", &b[j]);
		for(int j = 1; j <= 5; j++)
		{
			for(int k = 0; k <= 9; k++)
			{
				if(k == b[j])continue;
				for(int p = 1; p <= 5; p++)
				{
					if(p == j)
					{
						a[tmp] += k;
						a[tmp] *= mod;
					}
					else 
					{
						a[tmp] += b[p];
						a[tmp] *= mod;
					}
				}
				tmp++;
			}
		}
		for(int j = 1; j <= 4; j++)
		{
			for(int k = 0; k <= 9; k++)
			{
				if(k == b[j])continue;
				for(int p = 1; p <= 5; p++)
				{
					if(p == j)
					{
						a[tmp] += k;
						a[tmp] *= mod;
					}
					if(p == j + 1)
					{
						a[tmp] = a[tmp] + (b[p] + k) % 10;
						a[tmp] *= mod;
					}
					else
					{
						a[tmp] += b[p];
						a[tmp] *= mod;
					}
				}
				tmp++;
			}
		}
	}
	for(int i = 1; i < tmp; i++)for(int j = i+1; j < tmp; j++)if(a[i] > a[j])swap(a[i], a[j]);
	int cun = 1, ans = 0;
	for(int l = 1; l < tmp; l++)
	{
		if(a[l] != a[l+1])
		{
;			if(cun == t)ans++;
			cun = 1;
		}
		else cun++;
	}
	printf("%d\n", ans);
	return 0;
}
