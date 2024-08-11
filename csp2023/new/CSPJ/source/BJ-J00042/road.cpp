#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,v[100005],a[100005],vv[100005],you=0,qian=0;
    vv=v;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        sort(v,v+n);
        if(vv[i]==v[i]){
            you+=4*a[i];qian+=d*n*a[i];
        }

    }
    return 0;
}