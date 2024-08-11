#include<iostream>
#include<cstdint>
#include<cstring>
using namespace std;

#define N 100003
int64_t v[N],a[N];
int64_t sumV=0;
int n,d;

int64_t ans=INT64_MAX;
void dfs(int x,int64_t cst,int64_t dis){
    if(dis<0)return;
    if(x==n){
        ans=min(ans,cst);
        return;
    }
    for(int i=0;i<=(sumV+d)/d;i++){
        
        dfs(x+1,cst+i*a[x],dis+i*d-v[x]);
    }
}

// int64_t f[N][1000000];
// int64_t ans2=0;
// void dfsM(int x,int64_t cst,int64_t dis){
//     if(x==n){
//         f[n][dis]=cst;
//         return;
//     }
//     for(int i=0;i<=(sumV+d)/d;i++){
//         int64_t ndis=dis+i*d-v[x];
//         if(ndis<0)continue;
//         if(f[x+1][ndis]==0x3f3f3f3f3f3f3f3f){
//             dfsM(x+1,cst+i*a[x],ndis);
//         }
//         f[x][dis]=min(f[x][dis],f[x+1][ndis]);
//     }
// }

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        sumV+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    dfs(1,0,0);
    cout<<ans<<endl;

    // memset(f,0x3f,sizeof(f));
    // dfsM(1,0,0);


    return 0;
}