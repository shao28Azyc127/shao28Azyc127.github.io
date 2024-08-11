#include<bits/stdc++.h>
using namespace std;
int N,M,K;
const int NMAX=1e4+7;
int A[NMAX][NMAX];
bool B[NMAX];
int o=2147483640;
void DFS(int x,int T,int stT){
    if(x==N){
//        printf("%d %d %d\n",x,T,stT);
        if(T%K==0){
            o=min(o,((stT/K)+bool(stT%K))*3+T);
        }
        return;
    }
    B[x]=1;
    for(int i=1;i<=N;i++){
        if(A[x][i]!=-1&&B[i]==0){
            stT=max(stT,T-A[x][i]);
            DFS(i,T+1,stT);
        }
    }
    B[x]==0;
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>N>>M>>K;
    for(int i=0;i<=N;i++)for(int j=0;j<=N;j++) A[i][j]=-1;
    while(M--){
        int a,b;
        cin>>a>>b;
        cin>>A[a][b];
    }
    DFS(1,0,-1);
    if(o>=2147483640) cout<<"-1";
    else cout<<o;
    return 0;
}
