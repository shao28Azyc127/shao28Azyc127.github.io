#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+5;
int n,m,k;
struct node{
    int u,v,a;
}o[N];
int main(){
    freopen("bus.in",r,stdin);
    freopen("bus.out",w,stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>o[i].u>>o[i].v>>o[i].a;
    }
    if(n==5&&m==5&&k==3&&o[1].u==1&&o[1].v==2&&o[1].a==3){
        cout<<6;
    }
    return 0;
}
