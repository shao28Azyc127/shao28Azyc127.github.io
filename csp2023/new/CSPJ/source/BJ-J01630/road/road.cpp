#include <bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005],cnt = 0,k = 0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> d;
	for(int i = 1;i < n;i++)
	{
		cin >> v[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int l = 1;
	while(1)
	{
		if(l == n)
		{
			break;
		}
		int p = l;
		int minn = a[l];
		for(int i = l+1;i <= n;i++)
		{
			if(minn > a[i])
			{
				p = i;
				minn = a[i - 1];
				break;
			}
		}
		if(p == l)
		{
			int t = 0;
			for(int i = l;i < n;i++)
			{
				t += v[i];
			}
			if((t - k) % d == 0)
			{
				cnt += (t - k) / d * a[l];
			}
			else
			{
				cnt += ((t - k) / d + 1) * a[l];
			}
			break;
		}
		else
		{
			int t = 0;
			for(int i = l;i < p;i++)
			{
				t += v[i];
			}
			if((t - k) % d == 0)
			{
				cnt += (t - k) / d * a[l];
			}
			else
			{
				cnt += ((t - k) / d + 1) * a[l];
			}
			k = k + ceil(1.0 * (t - k) / d) * d - t;
			l = p;
		}
	}
	cout << cnt;
	return 0;
}