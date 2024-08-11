#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5;
ll n,tmp[N],id[N],lt,i,p[N],lp;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        tmp[i]=i;
        id[i]=i;
    }
    lt=n;
    ll cnt=0,ans=0;
    while(lt){
        cnt++;
        lp=0;
        for(i=1;i<=lt;i++){
            if(i%3!=1){
                p[++lp]=i;
                id[lp]=id[i];
            }else if(id[i]==n){
                ans=cnt;
            }
        }
        lt=0;
        for(i=1;i<=lp;i++) tmp[++lt]=p[i];
    }
    printf("%lld %lld",cnt,ans);
    return 0;
}