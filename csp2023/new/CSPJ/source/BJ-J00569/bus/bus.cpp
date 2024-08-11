//#define dbg
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=2e4+2;
vector<pair<int,int>> gr[N];
int ans=1e9+7;
queue<pair<int,pair<int,int>>> q;
void Bfs(int now,int max1,int len){
    q.push(make_pair(now,make_pair(max1,len)));
    while(!q.empty()){
        pair<int,pair<int,int>> tmp=q.front();
        now=tmp.first,max1=tmp.second.first,len=tmp.second.second;
        q.pop();
        #ifdef dbg
        cout<<"now:"<<now<<endl;
        #endif
        for(auto v: gr[now]){
            if(v.first==n){
                if((len+1)%k==0){
                    int op=max(v.second,max1);
                    if(op%k!=0){
                        op=op+(k-op%k);
                    }
                    ans=min(ans,len+1+op);
                }
            }
            else q.push(make_pair(v.first,make_pair(max(v.second,max1),len+1)));
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int u,v,a;
        cin>>u>>v>>a;
        gr[u].push_back(make_pair(v,a));
    }
    Bfs(1,0,0);
    cout<<ans<<endl;
    return 0;
}