#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N=505;
vector<int> vec[N];
int a[N],b[N],c[N];
int n;
int ans;
bool hstr[N];
bool canvis[N];
int tree[N];
void dfs(int day,int u,bool fin){
hstr[u]=1;
    memset(canvis,0,sizeof(canvis));
    //cout<<day<<" "<<u<<endl;
    fin=true;
    if(day>=1e8)return;
    for(int i=1;i<=n;i++){
        for(auto v:vec[i]){
            if(!hstr[v]){
                canvis[v]=1;
            fin=false;}
        }
    }
    if(fin){
        while(1){
            day++;
            int flag=0;
            for(int i=1;i<=n;i++){
                if(tree[i]<=a[i]){
                    tree[i]+=max(b[i]+day*c[i],1ll);
                    flag=1;
                }
            }
            if(!flag)break;
        }
        ans=min(ans,day-1);

        return;
    }
    int flag=0;
    for(int i=1;i<=n;i++){
        if(hstr[i]&&tree[i]<=a[i]){
            flag=1;
            tree[i]+=max(b[i]+day*c[i],1ll);
        }
    }
    if(!flag&&fin){
        ans=min(ans,day);
        return;
    }

    for(int i=1;i<=n;i++){
        if(canvis[i]){
            dfs(day+1,i,fin);
        }
    }
    return;
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    ans=2e9;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=2;i<=n;i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1,1,0);
    cout<<ans;
    return 0;
}
