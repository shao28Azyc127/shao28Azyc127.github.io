#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //t1
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ll n,ans=0,d=0;
    ll n1;
    scanf("%lld",&n);
    n1=n;
    while(n1){
        ans++;
        if(n1==1){
            printf("%lld ",ans);
            break;
        }
        ll t=n1/3;
        if(n1%3!=0){
            t++;
        }
        n1-=t;
    }
    while(ans){
        d++;
        ll t=n/3;
        if(n%3!=0){
            t++;
        }
        if(n%3==1){
            printf("%lld",d);
            break;
        }
        n-=t;
        ans--;
    }
    return 0;
}
