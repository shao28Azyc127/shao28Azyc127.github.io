#include <bits/stdc++.h>
using namespace std;

struct code
{
	int a[6];
	int& operator[](int x)
	{
		return a[x];
	}
	void read()
	{
		scanf("%d %d %d %d %d", &a[1], &a[2], &a[3], &a[4], &a[5]);
	}
};

code a[9];

bool chk(code s, code e)
{
	for(int i = 1;i <= 5;i++)
	{
		s[i] = (s[i] - e[i] + 10) % 10;
	}
	int cur = 0, cnt = 2;
	for(int i = 1;i <= 5;i++)
	{
		if(s[i] == 0)
		{
			if(cnt != 2)
			{
				cnt = 0;
			}
		}
		else if(s[i] == cur || cur == 0)
		{
			cur = s[i];
			if(cnt == 0)
			{
				return false;
			}
			cnt--;
		}
		else
		{
			return false;
		}
	}
	if(cur == 0)
	{
		return false;
	}
	return true;
}

int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		a[i].read();
	}
	code i;
	int cnt = 0;
	for(i[1] = 0;i[1] <= 9;i[1]++)
	{
		for(i[2] = 0;i[2] <= 9;i[2]++)
		{
			for(i[3] = 0;i[3] <= 9;i[3]++)
			{
				for(i[4] = 0;i[4] <= 9;i[4]++)
				{
					for(i[5] = 0;i[5] <= 9;i[5]++)
					{
						for(int j = 1;j <= n;j++)
						{
							if(!chk(i, a[j]))
							{
								break;
							}
							if(j == n)
							{
								cnt++;
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
