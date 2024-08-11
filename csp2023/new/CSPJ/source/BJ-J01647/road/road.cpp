#include <bits/stdc++.h>
using namespace std;
int v[100005],a[100005],minn[100005],mini[100005],tong[100005];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    v[0]=0;
    for(int i=2;i<=n;++i){
        cin>>v[i];
        v[i]+=v[i-1];
    }
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j)if(a[i]>a[j]){
            mini[i]=j;
            break;
        }
        if(mini[i]==0)mini[i]=i;
    }
    double you=0,price=0;
    if(mini[1]!=1)you+=ceil((v[mini[1]]-v[1])*1.0/d),price+=you*a[1];
    else{
        cout<<a[1]*ceil(v[n]/d);
        return 0;
    }
    cout<<you<<"\n";
    you-=(v[mini[1]]-v[1])*1.0/d;
    for(int i=mini[1];;){
        if(mini[i]==i){
            price+=max(a[i]*ceil(((v[n]-v[i])*1.0)/d-you),0.0);
            break;
        }
        int nowyou=you;
        you+=ceil(ceil((v[mini[i]]-v[i])*1.0/d)-you);
        price+=ceil((ceil((v[mini[i]]-v[i])*1.0/d)-nowyou)*a[i]);
        you-=(v[mini[i]]-v[i])*1.0/d;
        i=mini[i];
    }
    cout<<(int)price;
    return 0;
}
