#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

const int N=1e5+5;
int a[N],v[N];
long long s[N];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n;double d;
    cin>>n>>d;
    for(int i=1;i<n;i++)cin>>a[i],s[i+1]=s[i]+a[i];
    for(int i=1;i<=n;i++)cin>>v[i];
    long long ans=0;double rest=0;
    for(int i=1;i<n;i++)
    {
        //int p=lower_bound(v+i+1,v+1+n,v[i])-v;
        int p=n;
        for(int j=i+1;j<=n;j++)
            if(v[j]<v[i]){
                p=j;
                break;
            }
        //cout<<p<<endl;
        long long len=s[p]-s[i];
        double need=len*1.0/d;
        long long buy=ceil(need-rest);
        rest=buy+rest-need;
        ans+=buy*v[i];
        i=p-1;
    }
    cout<<ans;
    return 0;
}
