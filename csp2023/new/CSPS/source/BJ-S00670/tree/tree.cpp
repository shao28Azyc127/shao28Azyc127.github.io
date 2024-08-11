#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n;
struct tree{
    ll a,b,c;
}m[100001];
vector<int> v[100001];
int fMax[100001];
void dfs(int x,int f,int num){
    fMax[x]=num;
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==f) continue;
        dfs(v[x][i],x,num+1);
    }
    return;
}
ll ans=1e9+7;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i].a>>m[i].b>>m[i].c;
    }
    for(int i=1;i<n;i++){
        int t1,t2;
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    dfs(1,0,0);
    int t=0;
    for(int i=1;i<=n;i++){
        if(m[i].a/m[i].b>t){
            t=m[i].a/m[i].b;
            ans=fMax[i]+m[i].a/m[i].b;
        }
    }
    cout<<ans<<endl;
    return 0;
}
