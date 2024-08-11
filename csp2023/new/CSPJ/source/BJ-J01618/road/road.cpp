#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int sum[100020],v[100020],mn[100020],p[100020];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	scanf("%d%d",&n,&d);
	for (int i = 1;i < n;i++)
	{
		scanf("%d",v + i);
		sum[i] = sum[i-1] + v[i];
	}
	sum[n] = sum[n-1] + v[n-1];
	int minn = 1e9,mnid = 0;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",p + i);
		if (p[i] < minn) 
		{
			mnid = i;
			minn = p[i];
		}
	}
	if (mnid == 1)
	{
		printf("%d\n",int(ceil(1.0 * sum[n-1] / d) * p[1]));
		return 0;
	}
	for (int i = 1;i <= mnid;i++)
	{
		for (int j = i + 1;j <= mnid;j++)
		{
			if (p[j] < p[i]) 
			{
				mn[i] = j;
				break;
			}
		}
	}
	int ans = 0,last = 1;
	for (int i = 1;i < mnid;i++)
	{
		if (i == last) 
		{
			ans += p[i] * ceil(1.0 * (sum[mn[i]] - sum[i]) / d);
			last = mn[i];
		}
	}
	if (mnid == n) printf("%d\n",ans);
	else printf("%d\n",int(ans + minn * ceil(1.0 * (sum[n] - sum[mnid]) / d)));
	return 0;
}
