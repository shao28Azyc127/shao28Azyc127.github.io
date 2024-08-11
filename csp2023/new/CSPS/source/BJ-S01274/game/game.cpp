#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
char s[N];
int n,tt;char stk[N];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",s+1);
    ll ans=0;
    for(int l=1;l<=n;l++){
        tt=0;stk[++tt]=s[l];
        for(int r=l+1;r<=n;r++){
            if(s[r]==stk[tt]) tt--;
            else stk[++tt]=s[r];
            ans+=(tt==0);
        }
    }
    printf("%lld",ans);
    return 0;
}
/*
12
accaabccbaaa

*/
