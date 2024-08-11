#include<bits/stdc++.h>
using namespace std;
struct view{
    bool can1,can2;
};
struct Road{
    int from,to,open;
    bool can;
};
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k,i=0;
    cin>>n>>m>>k;
    view v[n];
    Road road[m];
    for(i=0;i<m;i++){
        cin>>road[i].from;
        cin>>road[i].to;
        cin>>road[i].open;
    }
    for(i=0;i<m;i++){
        v[road[i].from].can1=true;
        v[road[i].to].can2=true;
    }
    if(v[0].can1==false) cout<<"-1"<<endl;
    if(v[0].can2==false) cout<<"-1"<<endl;
    else{
        cout<<road[0].open+2*k;
    }
    return 0;
}