#include <bits/stdc++.h>
using namespace std;
long long n,d;
long long v[100005];
long long a[100005];
long long qz[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++)
    {
        scanf("%lld",&v[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qz[0]=0;
    qz[1]=0;
    for(int i=2;i<=n;i++)
    {
        qz[i]=qz[i-1]+v[i];
    }
    int j;
    long long ans=0;
    long long mylast=a[1];
    long long oildis=0;
    long long mydis;
    long long oilsum;
    for(int i=1;i<=n;i++)
    {
        j=i+1;
        mylast=a[i];
        while((j<n)&&(mylast<=a[j]))
        {
            //mylast=a[j];
            j++;
        }
        mydis=qz[j]-qz[i];

        oilsum=(mydis-oildis)/d;
        if(oilsum*d+oildis<mydis) oilsum++;
        ans+=(oilsum)*a[i];//(mydis-oildis)/d+1 youshu
        oildis=((oilsum)*d+oildis-mydis);

        i=j-1;
        if(j>=n) break;
    }
    cout<<ans;
    return 0;
}
