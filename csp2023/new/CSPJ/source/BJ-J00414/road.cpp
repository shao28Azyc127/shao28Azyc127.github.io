#include<bits/stdc++.h>
using namespace std;
int a[100005],v[100005],minn[100005]={(int)1e9},mini[100005],sum[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        sum[i]=sum[i-1]+v[i];
    }
    sum[n]=sum[n-1];
    for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]<minn[i-1]){
                minn[i]=a[i];
                mini[i]=i;
            }else{
                minn[i]=minn[i-1];
                mini[i]=mini[i-1];
            }
    }
    /*
    for(int i=1;i<=n;i++)
        cout<<minn[i]<<' ';
    cout<<'\n';
    for(int i=1;i<=n;i++)
        cout<<mini[i]<<' ';
    cout<<'\n';
    */
    long long ans=0;
    int targ=mini[n],last=n,lastful=0;
    while(last>1){
        ans+=1ll*a[targ]*(sum[last]-sum[targ])/d+lastful;
        lastful=(d-(sum[last]-sum[targ])%d)%d;
        last=targ;
        targ=mini[targ-1];
    }
    cout<<ans+a[1]*sum[last]/d;
    return 0;
}
