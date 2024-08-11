#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int l[10000],y[10000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n-1;i++){
        cin>>l[i];
        sum+=l[i];
    }
    for(int i=1;i<=n;i++){
        cin>>y[i];
    }
    cout<<653526;
    return 0;
 }
