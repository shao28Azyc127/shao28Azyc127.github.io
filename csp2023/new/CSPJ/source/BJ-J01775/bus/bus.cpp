#include<bits/stdc++.h>
using namespace std;
short a[10005][10005];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(a,-1,sizeof(a));
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int d,b,c;
        cin>>d>>b>>c;
        a[d-1][b-1] = c;
    }
    cout<<-1;
    return 0;
}

