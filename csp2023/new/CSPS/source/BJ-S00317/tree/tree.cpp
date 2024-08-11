#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
int n;
int mx;
int mxpos;
int a[100005],b[100005],c[100005],u[100005],v[100005];
int ans;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		if(mx==a[i])continue;
		mx=max(mx,a[i]);
		if(mx==a[i])mxpos=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>u[i]>>v[i];
	}
	cout<<n+mx/b[mxpos]<<endl;
    return 0;
}
