#include<bits/stdc++.h>
using namespace std;
int ans[20005],inq[20005];
vector<pair<int,int>> V[20005];
long long n,m,k,alls=0;
struct node{
    long long ntm,x;
}cur,tmp;
queue<node> Q;
long long spfa(int S){
    cur.x=S;
    cur.ntm=0;
    Q.push(cur);
    inq[S]=1;
    while(!Q.empty()){
        cur=Q.front();
        Q.pop();
        inq[cur.x]=0;
        //cout<<cur.x<<endl;
        if(cur.x==n&&cur.ntm%k==0){
            return cur.ntm;
        }
        for(int i=0;i<V[cur.x].size();i++){
            int nx=V[cur.x][i].first,w=V[cur.x][i].second;
           // if(cur.ntm)
            if(!inq[nx]&&cur.ntm+alls>=w){
                inq[nx]=1;
                tmp.x=nx;
                tmp.ntm=cur.ntm+1;
                Q.push(tmp);
            }
        }
    }
    return -1;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        long long u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        if(u==v) continue;
        V[u].push_back(make_pair(v,w));
    }
    long long fans=1e17,c=1;
    for(alls=0;alls<=1000000+k;alls+=k){
        for(int i=1;i<=n;i++){
            inq[i]=0;
        }
        while(!Q.empty()){
            Q.pop();
        }
        fans=spfa(1)+alls;
        if(fans!=alls-1){
            c=0;
            break;
        }
    }
    if(c){
        fans=-1;
    }
    printf("%lld",fans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
