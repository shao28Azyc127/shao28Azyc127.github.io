#include <bits/stdc++.h>
using namespace std;

const int midn=1000405;

int n,cnt=0,ans=0;
int a[midn],b[midn],c[midn],head[100045],dis[10065][10065];
queue <int> q;

struct Edge{
    int next;
    int end;
}edge[100085];

void addedge(int start,int end){
    cnt++;
    edge[cnt].next=head[start];
    head[start]=cnt;
    edge[cnt].end=end;
}

void bfs(int start){
    dis[start][start]=0;
    int cur=q.front();
    for(int i=head[start];i<=edge[cur].end;i++){
            int x;
        if(dis[start][cur]==0x7f7f7f7f){
            dis[start][x]=dis[start][cur]+1;
            
        }
    }
    q.pop();
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];

    }
    for(int i=1;i<=n;i++){
        for(int i=1;i<=n;i++) dis[i][j]=0x7f7f7f7f;
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        addedge(x,y);
        addedge(y,x);
    }

    cout<<n+1;
    return 0;
}
