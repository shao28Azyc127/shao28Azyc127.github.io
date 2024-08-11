#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+10;
vector<int> e[MAXN];
bool edge[550][550];
bool vis[MAXN];
struct tr
{
	int a,b,c;
	int leg;
	bool is,fin;
}p[MAXN];
bool cmp(tr x,tr y)
{
	return x.a > y.a;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> p[i].a >> p[i].b >> p[i].c;
	}
	for(int i = 1;i <= n-1;i++)
	{
		int u,v;
		cin >> u >> v;
		edge[u][v] = 1;
		edge[v][u] = 1;
	}
	for(int i = 1;i <= n;i++) edge[0][i] = edge[i][0] = 1;
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(edge[i][k] && edge[k][j])
				{
					edge[i][j] = 1;
				}
			}
		}
	}
	sort(p+1,p+n+1,cmp);
	
	int lasti = 0;
	int x = 1;
	for(int i = 1;i <= n;i++)
	{
		if(edge[lasti][i] && !p[i].is)
		{
			p[i].is = 1;
			p[i].leg += p[i].b + p[i].c;
		}
		for(int j = 1;j <= n;j++)
		{
			//cout << i << " " << p[j].leg << " " << p[j].is << " " << p[j].fin << endl;
			if(p[j].is)
			{
				p[j].leg += p[j].b + (x*p[j].c);
			}
			if(p[j].a <= p[j].leg) p[j].fin = 1;
		}
		bool flag = 0;
		for(int j = 1;j <= n;j++)
		{
			if(!p[j].fin) flag = 1;
		}
		x++;
	}
	bool flag = 0;
	while(flag)
	{
		for(int j = 1;j <= n;j++)
		{
			//cout << j << " " << p[j].leg << " " << p[j].is << " " << p[j].fin << endl;
			if(p[j].is)
			{
				p[j].leg += p[j].b + (x*p[j].c);
			}
			if(p[j].a <= p[j].leg) p[j].fin = 1;
		}
		
		for(int j = 1;j <= n;j++)
		{
			if(!p[j].fin) flag = 1;
		}
		x++;
	}
	cout << x << endl;
	
	return 0;
}