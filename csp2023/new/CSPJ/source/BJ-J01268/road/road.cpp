#include<iostream>
#include<cstdio>
using namespace std;
struct go{
    long long road,money;
    long long sum;
};
bool cmp(go x,go y){
    return x.sum<y.sum;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,v=0,ans=0;
    cin>>n>>m;
    go a[n];
    for(long long i=0;i<n;i++){
        cin>>a[i].money;
        a[i].sum=a[i].money/m;
    }
    for(long long i=0;i<n-1;i++)
        cin>>a[i].road;
    for(long long i=0;i<n;i+=0)
    {
        v+=m;
        ans+=a[i].money;
        if(v>a[i].road)
            i++;
    }
    cout<<ans;
    return 0;
}
