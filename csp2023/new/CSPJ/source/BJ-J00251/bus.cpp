#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long>PLL;
long long n,m,k;
vector<PLL>a[200001];
bool mark[200001];
long long ans=LLONG_MAX;
long long up(long long c){
    if(c%k==0)return c;
    return (c/k+1)*k;
}
void dfs(int pos,long long step,long long t){
    if(pos==n){
        if(step%k==0){
            ans=min(step+t,ans);
        }
        return;
    }
    if(step>m)return;
    for(int i=0;i<a[pos].size();i++){
        if(mark[a[pos][i].first])continue;
        mark[a[pos][i].first]=1;
        dfs(a[pos][i].first,step+1,max(t,step<=a[pos][i].second?up(a[pos][i].second-step):0));
        mark[a[pos][i].first]=0;
    }
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        a[t1].push_back(PLL(t2,t3));
    }
    dfs(1,0,0);
    if(ans==LLONG_MAX)ans=-1;
    cout<<ans<<endl;
    return 0;
}
