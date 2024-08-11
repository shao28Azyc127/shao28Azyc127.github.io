#include<iostream>
#include<cstdio>
using namespace std;
long long v[100001];
long long a[100001];
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++) {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    long long ans=0;
    long long minn=1000001;
    long long y=0;
    for(int i=1;i<n;i++) {
        minn=min(a[i],minn);
        v[i]=v[i]-y;
        long long temp=v[i]/d;
        long long temp2=d-v[i]%d;
        if(v[i]%d==0) temp2=0;
        if(temp2==0) ans+=temp*minn;
        else ans+=(temp+1)*minn;
        y=temp2;
    }
    cout<<ans;
    return 0;
}
