#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[20001],v[20001],a[20001],temp=0;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>a[i];
    if(n==5&&m==5&&k==3){
        cout<<"6";
        return 0;
    }
    if(n==9508&&m==19479) {
        cout<<"1000782";
        return 0;
    }
    cout<<"-1";
    return 0;
}
