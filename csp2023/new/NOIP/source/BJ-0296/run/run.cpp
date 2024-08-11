#include<bits/stdc++.h>
#define int long long 
using namespace std;
int ans,c,t,n,m,k,d,x[100005],y[100005],v[100005],sv[100005],bg[100005];
bool can[100005];
void slv2(){
    while(t--){
         cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            cin>>x[i]>>y[i]>>v[i];
            bg[i]=x[i]-y[i]+1;
            can[i]=(y[i]<=k);
        }
        ans=0;
        for(int i=1;i<=m;i++){
            if(can[i]&&v[i]-y[i]*d>=0)ans+=v[i]-y[i]*d;
        }
         cout<<ans<<endl;
    }return;
}
void dfs(int now,int lx,int as){
    if(now>=n){
        ans=max(as,ans);
        return;
    }
    if(lx>k)return;
    for(int i=1;i<=m;i++){
        if(x[i]==now&&lx>=y[i])as+=v[i];
    }
    dfs(now+1,lx+1,as-d);
    dfs(now+1,0,as);
    return ;
}
void slv1(){
    while(t--){
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            cin>>x[i]>>y[i]>>v[i];
        }
        ans=0;
        dfs(0,0,0);
        cout<<ans<<endl;
    }
    return;
}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    if(c<=2)slv1();
    else slv2();
    //cout<<clock()*1.0/CLOCKS_PER_SEC<<"s\n";
    return 0;
};