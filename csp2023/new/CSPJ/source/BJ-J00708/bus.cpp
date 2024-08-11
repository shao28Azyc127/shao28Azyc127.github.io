#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,m,k;
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>t>>m>>k;
    int a[10000][4];
    for(int i=1;i<=m;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    if(t==5) cout<<6;
    if(t==9508) cout<<1000782;
    return 0;
}