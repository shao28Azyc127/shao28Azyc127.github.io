#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<functional>
#include<limits>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
long long n,d;
long long a[100001],ans,v[100001],vv[100001],f[100001];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        vv[i]=vv[i-1]+v[i];
    }

    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
    }
    f[0]=0;
    f[1]=0;
    f[2]=(v[1]+d-1)/d*a[1];
    //cout<<f[2]<<'\n';
    for(int i=3;i<=n;i++)
    {
        f[i]=1000000000000001;
        for(int j=1;j<i;j++)
        {
            //cout<<i<<' '<<j<<' '<<vv[j]-vv[j-(i-j)]<<'\n';
            //cout<<i<<' '<<j<<' '<<f[j]+((vv[i-1]-vv[j-1]+d-1)/d)*a[j]<<' '<<vv[i-1]-vv[j-1]<<'\n';
            f[i]=min(f[i],f[j]+((vv[i-1]-vv[j-1]+d-1)/d)*a[j]);

        }
        //cout<<f[i]<<' ';
    }
    cout<<f[n];
    return 0;
}
