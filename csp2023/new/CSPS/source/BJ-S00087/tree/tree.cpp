#include<bits/stdc++.h>
using namespace std;
#define int long long
int q[100005][5];
int num[100005];
bool check[100005];
int ans=1e9;
int n;
int a[100005],b[100005],c[100005];
int grow(int i,int x){
    int ans=0,cnt=0;
    if(c[i]==0) return (a[i]+b[i]-1)/b[i]+x-1;
    if(c[i]<0&&-x*c[i]>b[i]) return a[i]+x-1;
    if(c[i]<0){
        int y=b[i]/abs(c[i]);
        if((y-x+1)*(2*b[i]+(y+x)*c[i])/2<a[i]) return a[i]-(y-x+1)*(2*b[i]+(y+x)*c[i])/2+y;
    }
    while(cnt<a[i]) cnt+=b[i]+(x+ans)*c[i],ans++;
    return x+ans-1;
}
void solve(){
    ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,grow(i,i));
}
void dfs(int i,int j,int k,int now,int t){
    if(now>=ans) return;
    if(t==n){
        ans=now;
        return;
    }
    if(j==0||(k!=0&&q[j][2]==0)){
        int tmp;
        tmp=j;
        j=k;
        k=tmp;
    }
    if(k==0){
        int x=q[j][1];
        if(b[x]==true) x=q[j][2];
        b[j]=true;
        dfs(j,x,k,max(now,grow(j,t+1)),t+1);
        b[j]=false;
        return;
    }
    if(q[k][2]==0){
        b[k]=true;
        dfs(k,j,0,max(now,grow(k,t+1)),t+1);
        b[k]=false;
    }
    else{
        int x=q[k][1];
        if(b[x]==true) x=q[k][2];
        b[k]=true;
        dfs(k,j,x,max(now,grow(k,t+1)),t+1);
        b[k]=false;
    }
    int x=q[j][1];
    if(b[x]==true) x=q[j][2];
    b[j]=true;
    dfs(j,x,k,max(now,grow(j,t+1)),t+1);
    b[j]=false;
    return;
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i],num[i]=0;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        num[u]++;
        num[v]++;
        q[u][num[u]]=v;
        q[v][num[v]]=u;
    }
    if(num[1]==1) solve();
    if(num[1]==2) dfs(1,q[1][1],q[1][2],grow(1,1),1);
    cout<<ans;
}
