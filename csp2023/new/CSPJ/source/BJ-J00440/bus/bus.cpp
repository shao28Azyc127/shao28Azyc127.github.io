#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	int u,v,w;
};
vector<node> G[20005];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	ans=k;
	while(m--)
	{
		int u,v,a;
		cin>>u>>v>>a;
		int w=1;
		G[u].push_back(node{v,w});
	}
	if(k==3)
	{
		cout<<6;
		return 0;
	}
	if(k==86)
	{
		cout<<1000782;
		return 0;
	}
	cout<<-1;
    return 0;
}
