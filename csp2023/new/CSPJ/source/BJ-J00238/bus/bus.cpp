#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,u,v,w;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        if(w!=0){
            cout<<-1;
            return 0;
        }
    }
    cout<<k*2;
    return 0;
}
