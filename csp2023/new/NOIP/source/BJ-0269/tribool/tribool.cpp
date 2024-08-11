#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int C , T;
int x[100005]; // value start at 3
int n , m;
int v1[100005];
int v2[100005];
void input()
{
	char op;
	int tmp1, tmp2;
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i ++)
	{
		cin >> op;
		cin >> tmp1;
		tmp1 += 2;
		if(op == '-')
		{
			cin >> tmp2;
			tmp2 += 2;
			tmp2 = -tmp2;
		}
		else if(op == 'T')
		{
			tmp2 = 2;
		}
		else if(op == 'F')
		{
			tmp2 = 0;
		}
		else if(op == 'U')
		{
			tmp2 = 1;
		}
		else
		{
			cin >> tmp2;
			tmp2 += 2;
		}
		v1[i] = tmp1;
		v2[i] = tmp2;
	}
}
vector<int> edge[500005];
int cnt = 0;
void dfs(int p)
{
	cnt ++;
	if(edge[p].size() == 0)
	{
		return;
	}
	for(int i = 0 ; i < edge[p].size() ; i ++)
	{
		dfs(edge[p][i]);
	}
}
void t1()
{
	while(T--)
	{
		cnt = 0;
		input();
		for(int i = 3 ; i <= n + 3 ; i ++)
		{
			x[i] = i;
		}
		for(int i = 1 ; i <= m ; i ++)
		{
			if(v2[i] < 0)
			{
				x[v1[i]] = -x[-v2[i]];
			}
			else
			{
				x[v1[i]] = x[v2[i]];
			}
		}
		for(int i = 3 ; i <= n + 2 ; i ++)
		{
			if(x[i] == i) continue;
			if(x[i] == -i) {edge[0].push_back(i);continue;}
			if(x[i] >= 0)
			{
				edge[x[i]].push_back(i);
			}
			else
			{
				edge[-x[i]].push_back(i);
			}
		}
		dfs(0);
		cout << cnt - 1 << endl;
		for(int i = 0 ; i <= n + 3 ; i ++)
		{
			vector<int> tmp0;
			edge[i].swap(tmp0);
		}
	}
}
int main()
{
	freopen("tribool.in" , "r" , stdin);
	freopen("tribool.out" , "w" , stdout);
	cin >> C >> T;
	x[0] = -1;
	x[1] = 0;
	x[2] = 1;
	t1();
	return 0;
}