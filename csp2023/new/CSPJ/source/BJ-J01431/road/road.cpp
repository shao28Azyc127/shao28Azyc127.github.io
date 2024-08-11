#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n,d;
int v[100009];
int a[100009];
long long MAX = -1;
long long answ = 1e9;

void dfs(int step,int c,int l)
{
	if (answ!=1e9&&c>answ) return;
	if (step == n)
	{
		if (answ > c) answ = c;
		MAX = answ;
		return;
	}
	for (int i=0;i<=MAX;i++)
	{
		if (c+a[i]*i > MAX) break;
		if (l+i*d < v[i]) continue;
		else
		{
			dfs(step+1,c+a[i]*i,l+i*d-v[i]);
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> d;
	int s = 0;
	for (int i=1;i<n;i++) 
	{
		cin >> v[i];
		s += v[i];
	}
	for (int i=1;i<=n;i++) 
	{
		cin >> a[i];
	}
	MAX = int(ceil(s*1.0*a[1]/d));
	if (n<=8)
	{
		dfs(1,0,0);
		cout << answ << endl;
	}
	else cout << int(s*a[1]/d);
	return 0;
}