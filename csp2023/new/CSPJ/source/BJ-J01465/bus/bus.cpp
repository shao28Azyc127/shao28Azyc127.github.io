#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=1000100;
struct node{
    long long  to,ti;
};
vector<node> v[10005];
bool book[10005];
void dfs(long long p,long long t,long long bs){
    if(t+(n-bs)>=ans)return;
    if(p==n){
        if(t%k==0){
            ans=min(ans,t);
        }
        return;
    }
    if(book[p])return;
    book[p]=1;
    for(long long i=0;i<v[p].size();i++){
        long long to=v[p][i].to,ti=v[p][i].ti;
        if(t>=ti)dfs(to,t+1,bs+1);
        else dfs(to,((ti-bs)/k+1)*k+bs+1,bs+1);
    }
    book[p]=0;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(node{b,c});
    }
    dfs(1,0,0);
    if(ans!=1000100)cout<<ans;
    else cout<<-1;
    return 0;
}
