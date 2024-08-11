#include<bits/stdc++.h>
using namespace std;
#define int long long
int h[10009];
struct st{
    int ne,v,w;
}sd[100009];
int n,m,k;
int f[10009][109];
bool zzz[10009];
queue<int> q;
void spfa(){

        //cout<<t<<endl;
        zzz[1]=1;
        q.push(1);
        while(q.size()){
                int t;
                t=q.front();
                zzz[t]=0;
                q.pop();
            for(int i=h[t];i;i=sd[i].ne){
            for(int j=0;j<k;j++){
                int sum;
                sum=f[t][j]+1;
                if(sum<sd[i].w){
                    sum+=(sd[i].w-sum)/k*k;
                    if(sum<sd[i].w){
                        sum+=k;
                    }
                }
                if(sum<f[sd[i].v][(j+1)%k]){
                    f[sd[i].v][(j+1)%k]=min(f[sd[i].v][(j+1)%k],sum);
                    if(zzz[sd[i].v]==0){
                        q.push(sd[i].v);
                        zzz[sd[i].v]=1;
                    }
                }

            }
        }
        }


}
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        sd[i].v=v;
        sd[i].w=w;
        sd[i].ne=h[u];
        h[u]=i;
    }
    memset(f,0x3f,sizeof(f));
    f[1][0]=0;
    spfa();
    if(f[n][0]>1e9){
        f[n][0]=-1;
    }
    cout<<f[n][0]<<endl;
    return 0;
}
