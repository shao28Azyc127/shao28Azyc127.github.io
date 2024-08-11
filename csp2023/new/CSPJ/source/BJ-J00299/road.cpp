#include<bits/stdc++.h>
using namespace std;
long long n,d,v[100010],a[100010],ans;
long double t,t1,t2,t3;
long long harley(long long x,long long y)
{
    int sum=0;
    for(int i=x;i<y;i++)
    {
        sum+=v[i];
    }
    return sum;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(long long i=0;i<n-1;i++) cin>>v[i];
    for(long long i=0;i<n;i++) cin>>a[i];
    long long j=1;
    for(long long i=0;;)
    {
        if(a[j]<a[i])
        {
            t1=harley(i,j),t2=d,t3=a[i];
            long long linshi=ceil(t1/t2-t);
            t+=linshi;
            t-=t1/t2;
            ans+=linshi*a[i];
            i=j;
        }
        else if(a[j]>=a[i]&&j<n-1) j++;
        else if(j>=n-1)
        {
            t1=harley(i,n-1),t2=d,t3=a[i];
            long long linshi=ceil(t1/t2-t);
            t+=linshi;
            t-=t1/t2;
            ans+=linshi*a[i];
            i=n-1;
        }
        if(i==n-1) break;
    }
    cout<<ans;
    return 0;
}
