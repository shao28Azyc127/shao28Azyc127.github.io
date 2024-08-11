#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("busin","r",stdin);
    freopen("busout","w",stdout);
    int n,m,k,a[10010],b[10010],c[10010],p=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>c[i];
        if(c[i]!=0) p++;
    }
    if(p==0) cout<<k*2;
    return 0;
}
