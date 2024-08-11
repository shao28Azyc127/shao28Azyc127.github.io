#include <bits/stdc++.h>

using namespace std;

struct point{long long to,time;};
struct node{long long time,now;};

long long n,m,k;
long long u,v,a;

vector<point>mp[10005];
queue<node>que;

void BFS(){
    que.push({k,1});
    while(1){
        node tmp=que.front();
        //cout<<tmp.now<<" "<<tmp.time<<endl;
        que.pop();
        if(tmp.now==n&&tmp.time%k==0){cout<<tmp.time;return;}
        if(tmp.now==0&&tmp.time==0){return;}
        for(long long i=0;i<mp[tmp.now].size();i++){
            if(mp[tmp.now][i].time<=tmp.time){
                node tmp2;
                tmp2.now=mp[tmp.now][i].to;
                tmp2.time=tmp.time+1;
                que.push(tmp2);
            }
        }
    }
}

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        cin>>u>>v>>a;
        mp[u].push_back({v,a});
    }
    BFS();
    return 0;
}
