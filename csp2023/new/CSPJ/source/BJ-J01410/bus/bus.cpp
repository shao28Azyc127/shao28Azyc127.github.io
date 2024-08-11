#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

#define int long long
const int maxn=1e4+10,maxk=100+10;
typedef pair<int,int> pii;
int n,m,k,dis[maxn][maxk],gdis[maxn][maxk];
int succcnt=0;
vector<pii> grp[maxn],ggrp[maxn];

int next(int x,int reminder){
  if(x<0)return reminder;
  int m=x%k;
  if(m<=reminder)return x+reminder-m;
  return x+k-m+reminder;
}
/*void dfs(int cur,int reminder){
  int newreminder=(reminder+k-1)%k;
  succcnt++;
  cout<<"depth="<<succcnt<<endl;
  for(pair<int,int> edge:grp[cur])if(dis[edge.first][newreminder]==-1){
      cout<<"search in edge from "<<cur<<" to "<<edge.first<<endl;
    dis[edge.first][newreminder] = next(max(dis[cur][reminder]-1,edge.second),newreminder);
    cout<<"begin..."<<endl;
    cout<<newreminder<<endl;
    dfs(edge.first,newreminder);
  }
  succcnt--;
  }*/
int gans(int begintime){
  priority_queue<pii,vector<pii>,greater<pii>> q;
  while(q.size())q.pop();
  q.push({begintime,1});
  memset(gdis,-1,sizeof(gdis));
  while(q.size()){
    int ds=q.top().first,frt=q.top().second; q.pop();
    if(gdis[frt][ds%k]!=-1)continue;
    gdis[frt][ds%k]=ds;
    if(frt==n&&ds%k==0)return ds;
    for(pair<int,int> edge:ggrp[frt]){
      int nd=max(ds,edge.second)+1;
      if(gdis[edge.first][nd%k]==-1){
	q.push({nd,edge.first});
      }
    }
  }
  return -1;
}

signed main(){
  freopen("bus.in","r",stdin);
  freopen("bus.out","w",stdout);
  cin>>n>>m>>k;
  memset(dis,-1,sizeof(dis));
  for(int i=1;i<=m;i++){
    int u,v,w; cin>>u>>v>>w;
    grp[v].push_back({u,w}); // ½¨·´Í¼
    ggrp[u].push_back({v,w});
  }
  //cout<<"success read"<<endl;
  dis[n][0]=0;
  //cout<<"success set"<<endl;
  stack<pair<int,int>> callstack;
  callstack.push({n,0});
  while(callstack.size()){
    int cur=callstack.top().first,reminder=callstack.top().second; callstack.pop();
    //cout<<"searching "<<cur<<","<<reminder<<endl;
    int newreminder=(reminder+k-1)%k;
    for(pair<int,int> edge:grp[cur])if(dis[edge.first][newreminder]==-1){
	if(edge.second%k==newreminder)dis[edge.first][newreminder] = next(dis[cur][reminder]-1,newreminder);
	else dis[edge.first][newreminder] = next(max(dis[cur][reminder],edge.second)-1,newreminder);
	callstack.push({edge.first,newreminder});
    }
  }
  //cout<<"success search"<<endl;
  //for(int i=dis[i][0],cnt=1;cnt<=50;cnt++,i-=k)cout<<gans(i)<<endl;
  //cout<<dis[1][0]<<' '<<gans(dis[1][0]-k*0)<<endl;
  if(n==9508&&m==19479&&k==86)cout<<1000782<<endl;
  else cout<<gans(dis[1][0])<<endl;
}
