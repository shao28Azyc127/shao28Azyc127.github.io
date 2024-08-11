#include<iostream>
#include<fstream>
#include<cstdio>
#include<queue>
using namespace std;
int n,m,k;
int dat[20001][20001];
int u,v,w;
int fest[20001];
const int inf=1145141919;
queue<int> qe;
int main () {
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i!=j) {
                dat[i][j]=inf;
            }
        }
    }
    for(int i=0;i<m;i++) {
        cin>>u>>v>>w;
        dat[u][v]=w;
    }
    qe.push(1);
    while(!qe.empty()) {
            for(int i=1;i<=n;i++) {
                if(dat[qe.front()][i]<inf) {
                    if(fest[qe.front()]+1<dat[qe.front()][i]) {
                        continue;
                    }
                    fest[i]=min(fest[i],fest[qe.front()]+1);
                    qe.push(i);
                }
            }
            qe.pop();
    }
    while(fest[n]%k!=0) {
        fest[n]++;
    }
    cout<<fest[n]<<endl;
    return 0;
}
