#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
ll a[10005][10005];
ll u[20005],v[20005],t[10005];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        a[i][i]=0;
        cin>>u[i]>>v[i]>>t[i];
        a[u[i]][v[i]]=1;
    }
    if(k==1){
        if(a[1][n]==1){
            cout<<1;
            return 0;
        }
        for(int i=1;i<=n;i++){
            if(a[i][n]==1&&a[1][i]==1){
                cout<<2;
                return 0;
            }
        }
        cout<<-1;
    }
    else{
        cout<<-1;
    }
    return 0;
}
