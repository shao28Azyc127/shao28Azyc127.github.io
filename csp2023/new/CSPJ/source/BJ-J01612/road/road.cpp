#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int maxi=1;
int n,d,v[10001],ans=0;
struct s{
	int a,v1;
	bool raoddown=false;
};
s s1[5001];
int continuebuy(int i1)
{
    int payv,w=s1[i1].v1%d;
    if(w!=0)
    {
        payv=s1[i1].v1/d+1;
        for(int j=i1+1;j<=n-1;j++)
        {
            int w1=w;
            if(w<=s1[j].v1)
            {
                s1[j].v1-=w;
                break;
            }
            else
            {
                w-=s1[j].v1;
                s1[j].v1=0;
            }
        }
    }
    else
        payv=s1[i1].v1/d;
    return payv*s1[maxi].a;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n-1;i++)
	{
		cin>>s1[i].v1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i].a;
	}
    for(int i=1;i<=n-1;i++)
    {
        if(s1[i].a<s1[maxi].a)
            maxi=i;
        if(s1[i].raoddown)
            continue;
        ans+=continuebuy(i);
    }
    cout<<ans;
	return 0;
}