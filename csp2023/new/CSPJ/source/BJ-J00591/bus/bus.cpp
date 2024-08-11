#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct Node{
    int x;
    int y;
};
int a[10010][10010];

long long n,m,s;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>s;
    memset(a,-1,sizeof(a));
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        a[u][v]=w;
    }
    int time=s;
    queue<int> q;
    q.push(1);
    bool flag=false;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        if(t==m&&time%s==0){
            cout<<time;
            return 0;
        }
        time++;
        for(int i=1;i<=n;i++){
            if(a[t][i]!=-1){
                if(a[t][i]<=time){
                    q.push(i);
                    flag=true;
                }
            }
        }
        if(!flag){
            time-=2;
        }

    }
    cout<<-1;
    return 0;

}
