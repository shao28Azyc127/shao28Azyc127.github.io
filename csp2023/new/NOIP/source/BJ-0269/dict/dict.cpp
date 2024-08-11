#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n , m;
string w[3000];
int min0 = 1;
int main()
{
	freopen("dict.in" , "r" , stdin);
	freopen("dict.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> w[i];
		if(w[i] < w[min0])
		{
			min0 = i;
		}
	}
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	if(m == 1)
	{
		for(int i = 1 ; i <= n ; i ++)
		{
			if(i == min0)
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
		}
		return 0;
	}
	if(m == 2)
	{
		bool flag;
		for(int i = 1 ; i <= n ; i ++)
		{
			flag = 0;
			if(i == min0)
			{
				cout << 1;
				continue;
			}
			if(w[i] < w[min0])
			{
				cout << 1;
				continue;
			}
			for(int j = 1 ; j <= n ; j ++)
			{
				if(j == i) continue;
				if(w[i] > w[j])
				{
					swap(w[j][0] , w[j][1]);
					if(w[i] > w[j])
					{
						flag = 1;
						swap(w[j][0] , w[j][1]);
						break;
					}
					swap(w[j][0] , w[j][1]);
				}
			}
			if(!flag)
			{
				cout << 1;
				continue;
			}
			flag = 0;
			swap(w[i][0] , w[i][1]);
			if(w[i] < w[min0])
			{
				cout << 1;
				swap(w[i][0] , w[i][1]);
				continue;
			}
			for(int j = 1 ; j <= n ; j ++)
			{
				if(j == i) continue;
				if(w[i] > w[j])
				{
					swap(w[j][0] , w[j][1]);
					if(w[i] > w[j])
					{
						flag = 1;
						swap(w[j][0] , w[j][1]);
						break;
					}
					swap(w[j][0] , w[j][1]);
				}
			}
			swap(w[i][0] , w[i][1]);
			if(!flag)
			{
				cout << 1;
				continue;
			}
			cout << 0;
		}
		return 0;
	}
	return 0;
}