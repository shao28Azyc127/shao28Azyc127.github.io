//这破东西居然还要缩点！？？！？
#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<pair<int, int> > edge[1010];
queue<pair<int, int> > q;
int dis[1010];
void ans1(){
    q.push({1, 0});
    for(int i=2;i<=n;i++) dis[i]=1000000000;
    while(!q.empty()){
        pair<int, int> gg=q.front();
        dis[gg.first]=max(dis[gg.first], gg.second+1);
        for(int i=0;i<edge[gg.first].size();i++){
            if(dis[edge[gg.first][i].first]>=1000000000){
                q.push(edge[gg.first][i]);
                dis[edge[gg.first][i].first]=dis[gg.first]+1;
            }
        }
    }
}
int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin>>n>>m>>k;
    int op1=0, op2=0;
    for(int i=0;i<m;i++){
        int uu, vv, aa;
        cin>>uu>>vv>>aa;
        if(aa==0){
            op1++;
        }
        if(uu<vv){
            op2++;
        }
        edge[uu].push_back({vv, aa});
    }
    if(k==1){
        ans1();
        cout<<dis[n];
    }else{
        cout<<-1;
    }
    return 0;
}