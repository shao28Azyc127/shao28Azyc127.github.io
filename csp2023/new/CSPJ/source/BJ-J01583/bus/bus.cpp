#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i <= n;i++){
        int u[i];
        cin>>u[i];
    }
    for(int i = 1;i <= m;i++){
        int U[i];
        cin>>U[i];
    }
    for(int i = 1;i <= k;i++){
        int a[i];
        cin>>a[i];
        if(k%i == 0)
            cout<<k;
        else
            cout<<'-1';
    }
    return 0;
}
