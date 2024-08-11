#include<bits/stdc++.h>
using namespace std;
int n,m,k;const int N=10000;
int stupid[N][N];int r[N][N];
int s=100000000;
void bus(int now,int time){
    if(now==n&&time%k!=0){
        return;
    }
    if(now==n&&time%k==0){
        if(time<=s){
            s=time;
        }
        return;
    }else{
        for(int i=1;i<=n;i++){
            if(r[now][i]==1&&time>=stupid[now][i]){
                r[now][i]=0;
                bus(i,time+1);
                r[now][i]=1;
            }
        }
    }
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;int a,b,c,maxc;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;maxc=max(maxc,c);
        r[a][b]=1;stupid[a][b]=c;
    }
    int mins=10000000;
    for(int i=0;i<=maxc;i=i+k){
        bus(1,i);
        if(s<mins){
            mins=s;
        }
        s=100000000;
    }
    cout<<mins;
    return 0;
}
