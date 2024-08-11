#include <bits/stdc++.h>
using namespace std;

int w[100005];
int a[100005];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin >> n >> d;
	long long ans = 0;
	for (int i = 1;i <= n - 1;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int c = 1;
	double box = 0;
	while (c < n)
	{
		bool flag = false;
		for (int i = c + 1;i < n;i++)
		{
			if (a[i] <= a[c])
			{
				flag = true;
				for (int j = c;j < i;j++)
				{
					double need = 1.0 * w[j] / d;
					if (box >= need)
					{
						box -= need;
					}
					else
					{
						int s = ceil(need - box);
						box = 0;
						ans += s * a[j];
					}
				}
			}
			c = i;

			break;
		}
		if (!flag)
		{
			for (int j = c;j < n;j++)
			{
				double need = 1.0 * w[j] / d;
				if (box >= need)
				{
					box -= need;
				}
				else
				{
					if(box > 0)
					{
						need -= box;
						int s = ceil(need);
						ans += s * a[j];	
					}
					else
					{
						need = ceil(need);
						ans += need * a[j];
					}
				}
			}
			c = n;
		}
	}
	cout << ans << endl;
	return 0;
}
