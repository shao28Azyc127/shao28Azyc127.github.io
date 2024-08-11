#include<bits/stdc++.h>
using namespace std;
char a;
int t,tu[100005],w,c,n,m,ans,p;
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c==3||c==4){
    for(int j=1;j<=t;j++){
       cin>>n>>m;
       ans=0;
       memset(tu,0,sizeof(tu));
       for(int i=1;i<=m;i++){
           cin>>a>>w;
           if(a=='U'){
              tu[w]=1;
           }
           if(a=='T'||a=='F'){
              tu[w]=0;
           }
       }
       for(int i=1;i<=n;i++){
           if(tu[i]==1){
              ans++;
           }
       }
       cout<<ans<<endl;
    }
    }
    if(c==5||c==6){
    for(int j=1;j<=t;j++){
        cin>>n>>m;
        ans=0;
        memset(tu,0,sizeof(tu));
        for(int i=1;i<=m;i++){
           cin>>a;
           if(a=='U'){
              cin>>w;
              tu[w]=1;
           }
           if(a=='+'){
              cin>>p>>w;
              tu[p]=tu[w];
           }
       }
       for(int i=1;i<=n;i++){
           if(tu[i]==1){
              ans++;
           }
       }
       cout<<ans<<endl;
    }
    }
    return 0;
}