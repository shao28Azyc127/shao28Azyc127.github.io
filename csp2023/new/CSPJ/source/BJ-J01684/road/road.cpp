#include<bits/stdc++.h>
using namespace std;
#define int long long
int st[100005][22],nxt[100005],n,d,v[100005],a[100005],dis[100005],ans,oil;
int query(int l,int r){
    int loglen=log2(r-l+1);
    return min(st[l][loglen],st[r-(1<<loglen)+1][loglen]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i],st[i][0]=a[i];
    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j<=n;j++)
            if(j+(1<<i)-1<=n) st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
    //cout<<1<<endl;
    for(int i=1;i<=n;i++){
        int l=i+1,r=n;
       // cout<<i<<endl;
        //if(i==15) cout<<a[i]<<endl;
        while(r-l>5){
            int mid=(l+r)>>1;
            //if(i==1) cout<<l<<" "<<r<<" "<<mid<<" "<<query(i+1,mid)<<endl;
            if(query(i+1,mid)>=a[i]) l=mid;
            else r=mid;
        }
        for(int j=l;j<=r;j++)
            if(query(i+1,j)<a[i]){
                nxt[i]=j;
                break;
            }
        //cout<<nxt[i]<<endl;
        if(!nxt[i]) nxt[i]=n;
       //cout<<nxt[i]<<" ";
    }
    for(int i=2;i<=n;i++) dis[i]=dis[i-1]+v[i-1];
    int i=1;
    while(i<n){
        ans+=ceil((dis[nxt[i]]-dis[i]-oil)/(d*1.0))*a[i];
        oil+=ceil((dis[nxt[i]]-dis[i]-oil)/(d*1.0))*d-dis[nxt[i]]+dis[i];
        i=nxt[i];
        //cout<<i<<" "<<ans<<endl;
    }
    cout<<ans;
    return 0;
}