#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
ll n,m,i,j,k,ans,d;
ll a[100009],v[100009];
ll qzh[100009];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    int now=1;
    for(i=2;i<=n;i++) cin>>a[i],qzh[i]=qzh[i-1]+a[i];
    for(i=1;i<=n;i++) cin>>v[i];
    ll nowpos=1,restfuel=0;
    for(i=1;i<=n;i++)
    {
        ll money=v[i];
        if(i==n) break;
        while(v[i]>=v[nowpos]&&i<n) i++;
        //i=minimum gas
     //   cout<<i<<" "<<nowpos<<endl;
        if(restfuel>qzh[i]-qzh[nowpos-1])
        {
            restfuel-=qzh[i]-qzh[nowpos-1];
            continue;
        }
        ll dist=qzh[i]-qzh[nowpos-1]-restfuel;
        restfuel=0;
        ll fuel=ceil(dist*1.0/d)*money;
        ans+=fuel;
        restfuel+=fuel/money*d-dist;
      //  cout<<dist<<" "<<restfuel<<" "<<i<<endl;
        nowpos=i;
    }
    cout<<ans;
    return 0;
}
