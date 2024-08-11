
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=5002;

ll n;
char ch[maxn];

bool f[maxn][maxn];
ll ans=0;

int main() {

    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    scanf("%lld", &n);
    scanf("%s", ch+1);

    for(ll i=1; i<n; i++) {
        if(ch[i]==ch[i+1]) {
            f[i][i+1]=1;
            ans++;
        }
    }

    for(ll l=4; l<=n; l+=2) {
        for(ll i=1; i+l-1<=n; i++) {
            ll j=i+l-1;
         //   cout<<i<<" "<<j<<endl;
            if(ch[i]==ch[j] && f[i+1][j-1]) f[i][j]=1;
            else for(ll k=i+1; k<j; k++) {
                if(f[i][k] && f[k+1][j]) {
                    f[i][j]=1;
                    break;
                }
            }
            if(f[i][j]==1) ans++;
        }
    }

    printf("%lld", ans);

    return 0;
}
