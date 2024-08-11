#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
long long n,d,v[100005],a[100005],lu[100005],minn,mini,y,l,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        lu[i]=lu[i-1]+v[i];
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    minn=a[1];
    mini=1;
    for(int i=1;i<n;i++){
        if(a[i]<minn){
            minn=a[i];
            mini=i;
        }
        int t=ceil((lu[i]-l)*1.0/d);
        ans+=t*a[mini];
        l+=t*d;
    }
    cout<<ans;
    return 0;
}
