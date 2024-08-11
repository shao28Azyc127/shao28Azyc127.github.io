#include<bits/stdc++.h>
using namespace std;
const int N=1E5+1;
int v[N];
int a[N];
int Up(int n,int d)
{
	if(n%d!=0)
		return n/d+1;
	else
		return n/d;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,now=1,k=0;
	long long ans=0;
    cin>>n>>d;
    for(int i=2;i<=n;i++)
    {
        cin>>v[i];
        v[i]+=v[i-1];
    }
    for(int i=1;i<n;i++)
		cin>>a[i];
	while(now<n)
	{
		int next=-1;
		for(int i=now+1;i<n;i++)
		{
			if(a[i]<a[now])
			{
				next=i;
				break;
			}
		}
		if(next==-1)
		{
			ans+=Up(v[n]-v[now]-k,d)*a[now];
			k=Up(v[n]-v[now]-k,d)*d-(v[n]-v[now]-k);
			now=n;
		}
		else
		{
			ans+=Up(v[next]-v[now]-k,d)*a[now];
			k=Up(v[next]-v[now]-k,d)*d-(v[next]-v[now]-k);
			now=next;
		}
	}
	cout<<ans;
    return 0;
}