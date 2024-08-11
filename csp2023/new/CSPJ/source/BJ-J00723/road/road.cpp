#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,s,c,u,ans,p,v[100001],a[100001];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=1e9;
    for(int i=1;i<=n;i++){
        if(a[i]<a[s]){
            s=i;
        }
        u+=v[i];
        if(u>c){
            p=ceil(double(u-c*d)/d);
            ans+=p*a[s];
            c+=p;
        }
    }
    cout<<ans;
}
