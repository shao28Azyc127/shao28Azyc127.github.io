#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n, u, v;
long long ans;
bool flag, vis[100005];
vector<int> g[100005];

struct node
{
	int x;
	long long a, b, c;
	
}d[100005];

bool operator< ( node d1, node d2 )
{
	return (long long)ceil((double)d1.a/max(d1.b,1ll))<(long long)ceil((double)d2.a/max(d2.b,1ll));
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	
	scanf("%d", &n);
	
	for ( int i=1; i<=n; i++ )
	{
		scanf("%lld%lld%lld", &d[i].a, &d[i].b, &d[i].c);
		d[i].x = i;
		
		if ( d[i].c ) flag = true;
	}
	
	for ( int i=1; i<n; i++ )
	{
		scanf("%d%d", &u, &v);
		
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	//printf("%ld\n", g[1].size());
	
	if ( !flag )
	{
		priority_queue<node> q;
		
		ans = (long long)ceil((double)d[1].a/max(d[1].b,1ll));
		vis[1] = true;
		
		for ( int i=0; i<(int)g[1].size(); i++ )
		{
			q.push(d[g[1][i]]);
			vis[g[1][i]] = true;
		}
		
		while ( !q.empty() )
		{
			u = q.top().x;
			q.pop();
			
			ans = max(ans, (long long)ceil((double)d[u].a/max(d[u].b,1ll)));
			
			for ( int i=0; i<(int)g[u].size(); i++ )
			{
				v = g[u][i];
				
				if ( !vis[v] )
				{
					vis[v] = true;
					q.push(d[v]);
				}
			}
		}
		
		printf("%lld\n", ans);
		
		return 0;
	}
	
	
}
