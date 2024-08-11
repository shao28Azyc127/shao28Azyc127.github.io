#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<list>
#include<queue>
#include<stack>>
#include<list>
#include<vector>
#include<map>
using namespace std;
const int N=1e4+10;
struct road{
    int to,ti;
};
struct node{
    int ma=0,h=0,w;
};
int n,m,k,mi=1e9;
vector<road> r[N];
void bfs(int x){
    queue<node> q;
    q.push({0,0,x});
    while(!q.empty()){
        node t=q.front();
        q.pop();
        for(auto i:r[t.w]){
            if(i.ti>t.h){
                t.ma=max(i.ti-t.h,t.ma);
            }
            if(i.to==n){
                if((t.h+1)%k==0){
                    int t1=t.h+1+ceil(t.ma*1.0/k)*k;
                    mi=min(mi,t1);
                }
                continue;
            }
            q.push({t.ma,t.h+1,i.to});
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,a;
        cin>>u>>v>>a;
        r[u].push_back({v,a});
    }
    bfs(1);
    cout<<mi;
    return 0;
}

