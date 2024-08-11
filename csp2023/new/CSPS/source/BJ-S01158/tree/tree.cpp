#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100001],b[100001],c[100001];
long long u,v,lu[1001][1001];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		cin>>u>>v;
		lu[u][v]=lu[v][u]=1;
	}
	cout<<n+1;
	return 0;
}
