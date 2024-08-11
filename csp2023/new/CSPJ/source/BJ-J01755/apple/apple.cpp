#include <bits/stdc++.h>
using namespace std;
#define ll long long 
struct node{
    ll apple;
    ll index;
    ll nextindex;
};
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ll n;
    scanf("%lld",&n);
    ll lista[n+1];
    lista[1]=1;
    lista[2]=2;
    lista[3]=3;
    if(n<=3){printf("%lld %lld",n,n);return 0;}
    for(ll i=4;i<=n;i++){
        lista[i]=lista[i-(i+2)/3]+1;
    }
    cout<<lista[n]<<" ";
    node listb[n+1];
    for(ll  i=1;i<=n;i++){
        listb[i].index=i;listb[i].nextindex=i+1;
    }
    bool  flag=false;
    ll day=0;
    while (true){
        day++;
        for(ll i=1;i<=n;i++){
            if(listb[i].index%3==1){
                if(i==n){
                    cout<<day<<endl;
                    return 0;
                }
                listb[i-1].nextindex=listb[i].nextindex;
            }
            listb[i].index=listb[i].index-(listb[i].index+1)/3;
        }
    }
    return 0;
}