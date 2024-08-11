#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N];
int b[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>a[i];
    }
    long long ans=0,t=0;
    bool f=0;
    int imin=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        t+=a[i-1];
        if(b[i]<imin){
            if(imin!=0x3f3f3f3f) f=1;
            imin=b[i];
            ans+=ceil(t*1.0/d*1.0)*imin;
            t=0;
        }
    }
    if(t>0){
        ans+=ceil(t*1.0/d*1.0)*imin;
    }
    if(f)
        cout<<ans;
    else {
        ans=ceil(t*1.0/d*1.0)*b[1];
        cout<<ans;
    }
    return 0;
}
