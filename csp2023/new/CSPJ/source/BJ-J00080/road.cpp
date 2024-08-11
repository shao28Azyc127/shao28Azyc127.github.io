#include<bits/stdc++.h>
using namespace std;
long long f[100001];
int a[100001],v[100001],minn=2000000000,b[100001],n,d;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        minn=min(minn,a[i]);
        if(v[i]%d==0)
        {
            f[i]=f[i-1]+(v[i])/d*minn;
            b[i+1]=b[i];
        }
        else if((v[i]-b[i])%d==0)
        {
            f[i]=f[i-1]+(v[i]-b[i])/d*minn;
            b[i+1]=0;
        }
        else
        {
            f[i]=f[i-1]+((v[i]-b[i])/d+1)*minn;
            b[i+1]=((v[i]-b[i])/d+1)*d-(v[i]-b[i]);
        }

    }
    cout<<f[n]<<endl;
    return 0;
}
