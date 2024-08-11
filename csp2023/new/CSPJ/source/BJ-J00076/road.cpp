#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d,minn=1e9+7,sum=0;
int a[100005],b[100005];
bool dfs(int step,double oil,int money,int went)
{
    if(money>minn)
        return 0;
    if(oil<0)
        return 0;
    if(step>n){
        bool ret=0;
        if(money<minn)
        {
            ret=1;
        }
        minn=min(minn,money);
        return ret;
    }
    for(int i = 0;i<=(sum-went)/d;i++)
    {
        bool boo=dfs(step+1,oil+i-(1.0*a[step]/d),money+(i*b[step]),went+a[step]);
        if(boo==1)
        {
            continue;
        }
    }
    return 0;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    bool flag=1;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>d;
    for(int i = 1;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(int i = 1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]<=b[1]&&i!=1)
        {
            flag=0;
        }
    }
    if(flag==1)
    {
        cout<<sum/d*b[1]<<endl;
        return 0;
    }
    dfs(1,0,0,0);
    cout<<minn<<endl;
    return 0;
}
