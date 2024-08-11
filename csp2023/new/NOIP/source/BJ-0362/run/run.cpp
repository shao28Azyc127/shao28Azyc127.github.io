#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int c,t;
int n,m,k,d;
int x[MAXN],y[MAXN],v[MAXN];
ll ans;
//unordered_map<int,bool> flag;
bool flag[MAXN];
ll all;
long long sum;
int pre[MAXN];
void Check(){
    long long tmp=0;
    for(int i=1;i<=m;i++){
        int l=x[i]-y[i]+1,r=x[i];
        bool flag=1;
        if(l<1) continue;
        if(pre[r]-pre[l-1]==y[i]){
            tmp+=v[i];
        }
    }
    ans=max(ans,tmp-sum);
}
void Dfs(int x,int tot){
    if(tot>k) return;
    if(sum>all) return; 
    if(x>n){
        return Check();
    }
    pre[x]=pre[x-1];
    flag[x]=0;
    Dfs(x+1,0);
    flag[x]=1;
    sum+=d;
    pre[x]++;
    Dfs(x+1,tot+1);
    sum-=d;
    flag[x]=0;
    pre[x]=0;
}
void Work1(){
    cin>>n>>m>>k>>d;
    ans=all=sum=0;
    for(int i=1;i<=m;i++){
        cin>>x[i]>>y[i]>>v[i];
        all+=v[i];
    }
    Dfs(1,0);
    cout<<ans<<endl;
}
void Work9(){
    cin>>n>>m>>k>>d;
    ans=0;
    for(int i=1;i<=m;i++){
        cin>>x[i]>>y[i]>>v[i];
        if(1ll*y[i]*d<v[i]&&y[i]<=k) ans+=v[i]-1ll*y[i]*d;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--){
        if(1<=c&&c<=2) Work1();
        else if(17<=c&&c<=18) Work9();
    }
    return 0;
}