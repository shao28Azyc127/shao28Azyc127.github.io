#include<iostream>
#include<cstdio>
using namespace std;
long long n,d,v[100005],a[100005],minn[100005],ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    minn[1]=a[1];
    for(int i=2;i<n;i++){
        minn[i]=min(minn[i-1],a[i]);
    }
    long long g=0;
    for(int i=1;i<n;i++){
        v[i]-=g;
        ans+=(v[i]/d+(v[i]%d!=0))*minn[i];
        if(g=(v[i]/d+(v[i]%d!=0))*d==v[i])g=0;
        else g=(v[i]/d+(v[i]%d!=0))*d-v[i];
    }
    cout<<ans;
    return 0;
}