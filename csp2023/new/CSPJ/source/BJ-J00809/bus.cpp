#include<bits/stdc++.h>
using namespace std;
struct node{
    int to,val;
};
bool operator<(node n1,node n2){
    return n1.val>n2.val;
}
priority_queue<node> pq;
vector<node> v[10010];
int n,m,k,x,y,z,f[10010][101];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        v[x].push_back(node{y,z});
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            f[i][j]=1e9;
        }
    }
    f[1][0]=0;
    pq.push(node{1,0});
    while(!pq.empty()){
        node t=pq.top();
        pq.pop();
        int md=t.val%k,nx=0;
        if(md<k-1) nx=x+1;
        if(t.to==n && md==0){
            printf("%d",f[n][0]);
            return 0;
        }
        for(auto y:v[t.to]){
            f[y.to][nx]=max(min(f[y.to][nx],t.val+1),(y.val/k)*k+nx);
            pq.push(node{y.to,f[y.to][nx]});
        }
    }
    printf("-1");
    return 0;
}
