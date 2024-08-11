#include<bits/stdc++.h>
using namespace std;

//#define LOCAL

#define MAXN 2000005

int n;
char s[MAXN];

int f[MAXN],fcnt[MAXN];
long long ans=0;

int main(){
    #ifndef LOCAL
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    #endif

    ios::sync_with_stdio(false);

    cin>>n;
    cin>>s+1;

    s[n+1]='_';
    f[n+1]=n+1;

    for(int i=n;i>=1;i--){
        int now=i+1;
        while(now<=n){
            if(s[now]==s[i]){
                now++;
                f[i]=now;
                fcnt[i]=fcnt[now]+1;
                break;
            }
            now=f[now];
        }
        if(!f[i]){
            f[i]=n+1;
        }
        ans+=(long long)fcnt[i];
    }
    cout<<ans<<endl;

    return 0;
}
