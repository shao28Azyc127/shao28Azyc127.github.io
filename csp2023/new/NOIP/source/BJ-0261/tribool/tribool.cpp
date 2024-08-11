#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
vector<int> G[100010];
int in[100010];
int tp()
{
	int cnt=0;
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			q.push(i);
			cnt++;
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:G[u])
		{
			in[v]--;
			if(in[v]==0)
			{
				q.push(v);
				cnt++;
			}
		}
	}
	return n-cnt;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	cin>>c>>t;
	char v;
	while(t--)
	{
		if(c==3||c==4)
		{
			int ans=0;
			cin>>n>>m;
			for(int i=1;i<=m;i++)
			{
				cin>>v>>x;
				if(v=='U')
				{
					ans++;
				}
			}
			cout<<ans<<endl;
		}
		if(c==7||c==8)
		{
			memset(in,0,sizeof(in));
			cin>>n>>m;
			for(int i=1;i<=n;i++) G[i].clear();
			for(int i=1;i<=m;i++)
			{
				cin>>v>>x>>y;
				if(v=='+')
				{
					G[x].push_back(y);
					in[y]++;
				}
				else
				{
				    //cout<<x<<endl;
					G[y].push_back(x);
					in[x]++;
				}
			}
			cout<<tp()<<endl;
		}
	}
    return 0;
}
