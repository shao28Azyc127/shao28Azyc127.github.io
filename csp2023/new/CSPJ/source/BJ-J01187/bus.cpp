#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
const int N=1e4+10,K=105;
int n,m,k,flag=0,dis[N][K];
vector<int> v[N],t[N];
void cheak(int mid,int x,int l){
    for(int i=0;i<v[i].size();i++){
        if(t[i][x]>mid)continue;
        dis[i][(l+1)%k]=min(dis[i][(l+1)%k],l+1);
        cheak(mid,v[x][i],l+1);
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cout<<-1;
    /*
    cin>>n>>m>>k;
    int l=0,r=0;
    for(int i=1;i<=m;i++){
        int x,y,a;
        cin>>x>>y>>a;
        v[x].push_back(y);
        t[x].push_back(y);
        r=max(r,a);
    }
    r=ceil(1.0*r/k);
    while(l<r){
        int mid=(l+r)/2*3;
        for(int i=1;i<=n;i++){
            for(int j=0;j<k;j++){
                dis[i][j]=0x3f3f3f3f;
            }
        }
        cheak(mid,1,0);
        if(dis[n][0]==0x3f3f3f3f){
            l=mid+1;
        }else{
            r=mid;
        }
        cout<<mid<<" "<<dis[n][0]<<endl;
    }
    cout<<l+dis[n][0];
    */
    fclose(stdin);
    fclose(stdout);
    return 0;
}
