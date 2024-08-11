#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
bool cmp(){
    return a>b;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,i,u[1000000010]={},v[1000000010]={},ans=0;
    for(i=1;i<n;i++){
        cin>>u[i];
    } 
    cin>>v[1];
    int q=0;
    for(i=2;i<=n;i++){
        sort(v+1,v+1+i,cmp);
        u[i]-=q;
        q=0;
        if(u[i]%d==0){
            ans+=v[i]*u[i]/d;
        }else{
            ans+=v[i]*(u[i]/d+1);
            q+=u[i]%d;
       }
       cin>>v[i];
   }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
