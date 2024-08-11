#include <stdio.h>
#include <bitset>
using namespace std;
const int MAXN = 8005;
int n;
char str[MAXN];
bool ok[MAXN][MAXN];

inline bool &OK(int i,int j){
    return ok[i][j];
}

bool check(int l,int r){
    if (str[l] == str[r] && OK(l + 1,r - 1))
        return OK(l,r) = true;
    for (int i = l + 1;i + 2 <= r;i ++){
        if (OK(l,i) && OK(i + 1,r))
            return OK(l,r) = true;
    }
    return OK(l,r) = false;
}

int main(){
    #ifndef kevin
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    #endif
    scanf("%d%s",&n,str + 1);
    if (n > 800){
        long long ans = 0;
        for (int i = 2;i <= n;i += 2)
            ans += n - i + 1;
        printf("%lld",ans);
        return 0;
    }
    str[0] = '(';
    str[n + 1] = ')';
    long long ans = 0;
    for (int i = 1;i < n;i ++)
        if (str[i] == str[i + 1]){
            OK(i,i + 1) = true;
            ans ++;
        }
    for (int len = 4;len <= n;len += 2){
        for (int l = 1;l + len - 1 <= n;l ++){
            int r = l + len - 1;
            if (check(l,r)){
                ans ++;
                // printf("OK %d %d\n",l,r);
            }
        }
    }
    printf("%lld",ans);
    return 0;
}