#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
vector<int> e[N];
queue<int> q;
bool vis[N];
bool cmp(int x,int y){
    return x>y;
}
struct Node{
    int a,b,c;
};
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }/*
    q.push(1);
    vis[1]=true;
    int d=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        vis[x]=true;
        d++;
        for(int i=0;i<e[x].size();i++){
            int to=e[x][i];
            if(vis[to]) continue;
            q.push(to);
        }

    }*/
    sort(a+1,a+n+1,cmp);
    cout<<a[1]<<endl;
    return 0;
}
