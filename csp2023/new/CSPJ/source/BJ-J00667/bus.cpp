#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define mod 1000000007
using namespace std;
int n,m,k;
vector<pair<int,int> >v[100010];
bool dis[100010][110],f=0;
void bfs1(){
    queue<pair<int,int> >q;
    q.push(make_pair(1,0));
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        if(dis[x][y%k]==1)continue;
        dis[x][y%k]=1;
        if(x==n&&y%k==0){
            cout<<y;
            f=1;
            return;
        }
        for(int i=0;i<v[x].size();i++){
            int xx=v[x][i].first,yy=y+1;
            if(!dis[xx][yy%k])q.push(make_pair(xx,yy));
        }
    }
}
void bfs2(){
    queue<pair<int,int> >q;
    q.push(make_pair(1,0));
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        if(x==n&&y%k==0){
            cout<<y;
            f=1;
            return;
        }
        bool ff=0;
        for(int i=0;i<v[x].size();i++){
            int xx=v[x][i].first,yy=y+1;
            if(y>v[x][i].second){
                q.push(make_pair(xx,yy));
            }else ff=1;
        }
        if(ff)q.push(make_pair(x,y+k));
    }
}
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    bool flag=0;
    for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        if(w!=0)flag=1;
        v[x].push_back(make_pair(y,w));
    }
    if(!flag){
        bfs1();
        if(!f)cout<<-1;
    }else{
        bfs2();
        if(!f)cout<<-1;
    }
    return 0;
}
