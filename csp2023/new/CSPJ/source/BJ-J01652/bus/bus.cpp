#include<bits/stdc++.h>
#define F
using namespace std;

const int MAXN=1e4+10;
int n,m,k,ans=INT_MAX;
struct Node
{
	int v,a;
};
vector<Node> e[MAXN];

void DFS(int cur,int tim)
{
	if(cur==n)
	{
		if(tim%k==0)
			ans=min(ans,tim);
		return;
	}
	for(Node x:e[cur])
	{
		int v=x.v;
		int a=x.a;
		if(tim>=a)
			DFS(v,tim+1);
	}
	return;
}

int main()
{
	#ifdef F
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	#endif
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int u,v,a;
		cin>>u>>v>>a;
		Node x;
		x.v=v;
		x.a=a;
		e[u].push_back(x);
	}
	DFS(1,k);
	if(ans==INT_MAX)
		cout<<"-1"<<endl;
	else
		cout<<ans<<endl;
	return 0;
}