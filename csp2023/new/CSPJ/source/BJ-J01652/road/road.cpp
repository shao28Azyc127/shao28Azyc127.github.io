#include<bits/stdc++.h>
#define F
using namespace std;

const int MAXN=1e5+10;
int n,d,ans=INT_MAX;
int dis[MAXN],val[MAXN];

void DFS(int pos,int fuel,int v)
{
	if(pos==n)
	{
		ans=min(ans,v);
		return;
	}
	for(int i=(dis[pos]-fuel*d)/d+1;i<=n;i++)
		DFS(pos+1,fuel+i-(dis[pos]-fuel*d)/d+1,v+val[pos]*i);
	return;
}

int main()
{
	#ifdef F
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif
	cin>>n>>d;
	int tot=0;
	for(int i=1;i<=n-1;i++)
	{
		cin>>dis[i];
		tot+=dis[i];
	}
	int mn=INT_MAX;
	int mnp;
	for(int i=1;i<=n;i++)
	{
		cin>>val[i];
		if(val[i]<mn)
		{
			mn=val[i];
			mnp=i;
		}
	}
	if(mnp==1)//A
	{
		int L=tot/d;
		if(tot%d!=0)
			L++;
		cout<<L*val[1]<<endl;
		return 0;
	}
	DFS(1,0,0);
	cout<<ans<<endl;
	return 0;
}