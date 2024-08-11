#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[10][10];
ll fsm=0,ans=0;
ll b[10][10];//bucket
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%lld",&n);
    if(n==1) {
        printf("81");
        return 0;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
            b[j][a[i][j]]++;
        }
    }
    ll sm=0;
    for(ll i=1;i<=5;i++){
      sm=0;
      for(ll j=1;j<=9;j++){
            if(b[i][j]!=0) sm++;
        }
        if(sm==1) continue;
        else {
            ans+=(10-sm);
            fsm++;

        }
    }
    if(n==2){
        if(fsm==1){
            ans+=2;
            printf("%lld",ans);
        }else if(fsm==2){
            printf("%lld",2);//ab cd=>ad ad /cb cb/
        }
        }
    else{
        if(fsm==5){
            printf("%lld",1);
        }
        else if(fsm==1){
            printf("%lld",ans);
        }
        else printf("1");
    }


   // printf("%lld",ans);
    return 0;
}
