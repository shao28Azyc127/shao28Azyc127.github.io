#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

struct aa
{
	int nn[5];
	bool ach;
} finals[9];

queue<aa> alla;

int chas(int a, int b)
{
	if(b >= a)
	{
		return b-a;
	}
	else
	{
		return 10+b - a;
	}
}

bool ablee(aa a1 ,aa b1)
{
	int butong, butonga, butongb;
	butong = 0;
	butonga = -1;
	butongb = -1;
	for(int i = 0 ; i < 5 ; i++)
	{
		if(a1.nn[i] != b1.nn[i])
		{
			butong++;
			if(butong > 2)
			{
				return false;
			}
			if(butonga == -1)
			{
				butonga = i;
				continue;
			}
			if(butongb == -1)
			{
				butongb = i;
				continue;
			}
		}
	}
	if(butong == 0)
	{
		return false;
	}
	if(butong == 1)
	{
		return true;
	}
	else
	{
		if(butongb - butonga != 1)
		{
			return false;
		}
		else
		{
			if(chas(a1.nn[butonga], a1.nn[butongb]) == chas(b1.nn[butonga], b1.nn[butongb]))
			{
				return true;
			}
		}
	}
	return false;
}

int n, ans;
// struct probs
// {
// 	int nn;

// }

int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	ans = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < 5 ; j++)
		{
			int tmp;
			cin >> tmp;
			finals[i].nn[j] = tmp;
		}
		finals[i].ach = false;

	}
	if(n == 1)
	{
		cout << 81 << endl;
		return 0;
	}
	for(int i = 0 ; i <= 9 ; i++)
	{
		for(int j = 0 ; j <= 9 ; j++)
		{
			for(int k = 0 ; k <= 9 ; k++)
			{
				for(int l = 0 ; l <= 9 ; l++)
				{
					for(int m = 0 ; m <= 9 ; m++)
					{
						aa tmp;
						tmp.nn[0] = i;
						tmp.nn[1] = j;
						tmp.nn[2] = k;
						tmp.nn[3] = l;
						tmp.nn[4] = m;
						alla.push(tmp);
					}
				}
			}
		}
	}
	// cout << alla.size() << endl;
	for(int i = 0 ; i < 100000 ; i++)
	{
		aa tmps = alla.front();
		// cout << alla.front().nn[4];
		alla.pop();
		bool flag = true;
		for(int j = 0 ; j < n ; j++)
		{
			if(!ablee(tmps, finals[j]))
			{
				flag = false;
			}
		}
		if(flag)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}