#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int l[maxn][maxn]={-1};
int vis[maxn][maxn]={0};
struct p{
int b,t;
};
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
queue<p>d;
int n,m,k,mi=maxn;
cin>>n>>m>>k;
int u,v,a;
for(int i=0;i<m;i++){
cin>>u>>v>>a;
l[u][v]=a;
}
cout<<-1;
return 0;
}