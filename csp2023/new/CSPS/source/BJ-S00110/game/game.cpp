#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string ch;
long long ans = 0;
char zhan[2000005];
int now = 0;
signed main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld",&n);
    cin >> ch;
    for(int i = 0; i < n; i++){
        now = 0;
        for(int j = i; j < n; j++){
            if(now == 0){
                zhan[now] = ch[j],now++;
                continue;
            }
            if(zhan[now-1] == ch[j]) now--;
            else zhan[now] = ch[j],now++;
            if(!now) ans++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
