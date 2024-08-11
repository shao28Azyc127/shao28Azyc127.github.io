#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int value[100005];
int dis[100005];
long long dissum[100005];
int f[100005];
int n,d;
int cur;
int minpos;
int minvalue=100010;
int curminvalue;
int ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&d);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&dis[i]);
		dissum[i+1]=dissum[i]+dis[i];
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&value[i]);
		if(i==1)
		    curminvalue=value[1];
		if(minvalue==value[i])
		{
			continue;
		}
		minvalue=min(minvalue,value[i]);
		if(minvalue==value[i])
		{
			minpos=i;
			ans+=((dissum[minpos]-dissum[cur]+d-1)/d)*curminvalue;
			curminvalue=minvalue;
		}
	}
	if(minvalue==value[1])
	{
		ans=((dissum[n]+d-1)/d)*minvalue;
	}
	cout<<ans;
    return 0;
}
