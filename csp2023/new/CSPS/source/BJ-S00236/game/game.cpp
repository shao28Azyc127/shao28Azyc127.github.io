#include<cstdio>
#include<cstring>
#include<iostream>
#include<bitset>
using namespace std;
typedef long long ll;
const ll N=2e5+10,M=8e3+10;
char s[N];
ll a[N];
bool dp[M/2][M],dp2[11][N];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ll n,ans=0;
    scanf("%lld%s",&n,&s);
    for(ll i=1;i<=n;i++){
        a[i]=s[i-1]-'a'+1;
    }
    if(n>=M){
        for(ll i=1;i<n;i++){
            if(a[i]==a[i+1]){
                dp2[1][i]=1;
                ans++;
            }
        }
        for(ll l=4;l<=20;l+=2){
            for(ll i=1;i<=n-l+1;i++){
                ll j=i+l-1,tp=l>>1;
                if(dp2[tp-1][i+1]&&a[i]==a[j]){
                    dp2[tp][i]=1,ans++;
                    continue;
                }
                for(ll k=i+1;k<j;k+=2){
                    dp2[tp][i]|=dp2[(k-i+1)>>1][i]&&dp2[(j-k)>>1][k+1];
                }
                if(dp[tp][i]){
                    ans++;
                }
            }
        }
        printf("%lld",ans);
        return 0;
    }
    for(ll i=1;i<n;i++){
        if(a[i]==a[i+1]){
            dp[1][i]=1;
            ans++;
        }
    }
    for(ll l=4;l<=n;l+=2){
        for(ll i=1;i<=n-l+1;i++){
            ll j=i+l-1,tp=l>>1;
            if(dp[tp-1][i+1]&&a[i]==a[j]){
                dp[tp][i]=1,ans++;
                continue;
            }
            for(ll k=i+1;k<j;k+=2){
                dp[tp][i]|=dp[(k-i+1)>>1][i]&&dp[(j-k)>>1][k+1];
            }
            if(dp[tp][i]){
                ans++;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
