#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;
int dp1[100005],dp2[100005],dp3[100005],a[100005],v[100005];
int chu(int a1,int b)
{
    int i=0;
    i=a1/b;
    if(a1%b!=0)
    i++;
    return i;
}
int mini(int a1,int b)
{
    if(a1<b) return a1;
    return b;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,c=0,minn;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    cin>>v[i];
    for(int i=1;i<=n;i++)
    cin>>a[i];
    dp1[1]=chu(v[1],d);//you shu
    dp2[1]=dp1[1]*a[1];//qian shu
    dp3[1]=dp1[1]*d-v[1];//sheng de mi shu
    minn=a[1];
    for(int i=2;i<=n-1;i++)
    {
        minn=mini(a[i],minn);
        if(dp3[i-1]>=v[i])
        {
            dp2[i]=dp2[i-1];
            dp1[i]=0;
            dp3[i]=dp3[i-1]-v[i];
            continue;
        }
        dp1[i]=chu((v[i]-dp3[i-1]),d);
        dp2[i]=dp2[i-1]+dp1[i]*minn;
        dp3[i]=dp3[i-1]+dp1[i]*d-v[i];


    }
    cout<<dp2[n-1];

    return 0;
}
