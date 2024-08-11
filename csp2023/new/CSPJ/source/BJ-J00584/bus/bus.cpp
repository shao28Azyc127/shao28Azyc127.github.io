#include <iostream>
using namespace std;
int main(){
    int x,m,n,k,u[10005],v[10005],a[10005];
    freopen("bus.in","r",stdin);
    freopen("bus.ans","w",stdout);
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>a[i];
    }
    int ans;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(u[i]>u[i+1]){
                x=u[i];
                u[i]=u[i+1];
                u[i+1]=x;
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans+=1;
        if(u[i]==u[i+1]){
            ans-=1;
        }
    }
    if(ans%3==0){
        cout<<ans;
    }
    else if(ans%3==2){
        ans+=1;
        cout<<ans;
    }
    else{
        ans+=2;
        cout<<ans;
    }
    return 0;
}
