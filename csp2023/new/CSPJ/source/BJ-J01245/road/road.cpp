#include<bits/stdc++.h>
using namespace std;
int len[100005];
int cost[100005];
int fm[100005];
int c[100005];
int l[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,t;
	cin>>n>>t;
	int lentotal=0;
	for(int i=1;i<n;i++)
	{
		cin>>len[i];
		lentotal+=len[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>cost[i];
	}
	if(lentotal%t==0)
	{
		cout<<lentotal/t*cost[1];
	}
	else
	{
		cout<<(lentotal/t+1)*cost[1];
	}		
	return 0;
}
