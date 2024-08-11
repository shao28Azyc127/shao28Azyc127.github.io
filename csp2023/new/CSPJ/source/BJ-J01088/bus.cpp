#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> v[10005],w[10005];
int last[10005];
int main(){
    ios::sync_with_stdio(0);
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)last[i]=-1;
    for(int i=1;i<=m;i++){

        int u,r,a;
        cin>>u>>r>>a;
        v[u].push_back(r);
        v[r].push_back(u);
        w[u].push_back(a);
        w[r].push_back(a);
    }
    queue<int> q;
    q.push(n);
    last[n]=0;
    while(!q.empty()){
        int nx=q.front();
        q.pop();
        int si=v[nx].size();
        for(int i=0;i<si;i++){
            int xx=v[nx][i];
            int va=w[nx][i];
            if(last[xx]==-1||last[xx]>max(va,last[nx]+k)){
                last[xx]=max(va,last[nx]+k);
                q.push(xx);
            }
        }
    }
    cout<<last[1];
    return 0;
}
