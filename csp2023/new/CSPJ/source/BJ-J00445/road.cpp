#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

int n,d;
ll v[100005],a[100005];
ll sum;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)cin>>v[i],v[i]+=v[i-1];
    for(int i=1;i<=n;i++)cin>>a[i];
    sum=(v[1]+d-1)/d*a[1];
    int nw=1,y=(v[1]+d-1)/d*d-v[1];
    for(int i=2;i<n;i++){
        if(a[i]<a[nw])nw=i;
        if(y>=v[i]-v[i-1]){y-=v[i]-v[i-1];continue;}
        sum+=0>(v[i]-v[i-1]-y+d-1)/d*a[nw]?0:(v[i]-v[i-1]-y+d-1)/d*a[nw];
        y+=(v[i]-v[i-1]-y+d-1)/d*d-v[i]+v[i-1];
        //cout<<nw<<' '<<sum<<'\n';
    }
    cout<<sum;
    return 0;
}
