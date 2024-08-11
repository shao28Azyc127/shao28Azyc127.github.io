#include <iostream>
#include <cstdio>
#include <vector>
#define N 100000
using namespace std;

vector<int> e[N];


struct tree{
    int a,b,c;
}tree[N];


int day[N],index[N],deep[N];
bool vis[N];


int dfs1(int now,int n){
    day[now] = tree[now].a;
    index[now] = now;
    for(auto i:e[now]){
        if(vis[i])
            continue;
        vis[i] = true;
        dfs1(i,n);
        day[i] -= tree[index[i]].b;
        if(day[now] < day[i]){
            day[now] = day[i];
            index[now] = index[i];
            deep[now] = deep[i]+1;
        }
    }
    return index[now];
}



int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;

    bool flag1=true;
    for(int i=0;i<n;i++){
        cin>>tree[i].a>>tree[i].b>>tree[i].c;
        if(tree[i].c != 0)
            flag1 = false;
    }

    if(flag1){
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            e[u].push_back(v);
            e[v].push_back(u);
        }

        int ind=dfs1(0,n);
        int ans=tree[ind].a/tree[ind].b;
        if(double(ans)*tree[ind].b < tree[ind].a){
            ans++;
        }
        ans += deep[0];
        cout<<ans<<endl;
    }
    return 0;
}
