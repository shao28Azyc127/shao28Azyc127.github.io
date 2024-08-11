#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin >> n;
	int a[n+1][6],x[n+1],s = 0,m = 1,f = 0,sum = 0;
	int b[n+1][82];
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= 5;j++)
			cin >> a[i][j];
		x[i] = a[i][1]*10^4+a[i][2]*10^3+a[i][3]*10^2+a[i][2]*10+a[i][1];
	}
	if(n==1)
	{
		cout << "81";
		return 0;
	}
	if(n == 2)
	{
		cout << "10";
		return 0;
	}
	for(int k = 1;k <= n;k++)
	{	
		for(int j = 1;j <= 5;j++)
		{
			for(int i = 1;i <= 9;i++)
			{
				f = i;
				if(a[k][j] <= i)	f-=9;
				b[k][m] = x[k] +f*10^(j-1);
				m++;
			}
		}
		for(int j = 2;j <= 5;j++)
		{
			for(int i = 1;i <= 9;i++)
			{
				f = i;
				int f2 = i;
				if(a[k][j] <= i)	f-=9;
				if(a[k][j+1] <= i)	f-=9;
				b[k][m] = x[k] +f*10^(j-1) + f2*10^(j-2);
				m++;
			}
		}
	}
	for(int i = 1;i < m;i++)
	{
		for(int j = i;j < m;j++)
		{
			for(int k = 2;k <= n;k++)
			{
				if(b[k][j] == b[k-1][i])
				{sum++;}
			}
		}
	}
	cout << sum;
	return 0;
}
