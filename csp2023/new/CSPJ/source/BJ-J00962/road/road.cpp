#include<bits/stdc++.h>
using namespace std;
struct st{
    int v,tmp;
}b[100005];
int a[100005];
int n,d;
long long dp[100005],s[100005],c[100005];
bool cmp(st a,st b){
    if(a.v!=b.v)return a.v<b.v;
    return a.tmp<b.tmp;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i].v;b[i].tmp=i;c[i]=b[i].v;
    }
    for(int i=2;i<=n;i++)s[i]=s[i-1]+a[i-1];
    sort(b+1,b+n+1,cmp);
    int left=n;
    int cnt=0,vis[100005];
    vis[++cnt]=n;
    for(int i=1;i<=n;i++){
        if(b[i].tmp>left)continue;
        left=b[i].tmp;
        vis[++cnt]=left;
        if(left==1)break;
    }
    int sum=0;
    long double nowd=0.0,need;
    for(int i=cnt;i>1;i--){
        long double vvis=nowd;
        need=((long double)s[vis[i-1]]-s[vis[i]])/d-nowd;
        nowd=ceil(need);
        sum+=ceil(need)*c[vis[i]];
        nowd-=need;
    }
    cout<<sum<<endl;
}
