#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

template<typename T> inline void read(T &x){
    x = 0; bool F = 0; char c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') F = 1;
    for (;isdigit(c);c = getchar()) x = x*10+(c^48);
    if (F) x = -x;
}

template<typename T> inline void checkmax(T &x, const T &y){if (x<y) x = y;}

template<typename T> inline void checkmin(T &x, const T &y){if (x>y) x = y;}

const int N = 2e6+5, M = 22;
int f[N][M], val[N][M];
int Next[N], dp[N];
char c[N];
ll ans;
int n;

inline int g(int k){return 1<<(c[k]-'a');}

inline void cal(int k){
    // printf("cal: %d\n", k);
    int tmp = k, v = g(k); k++;
    for (int i = M-1;i>=0;i--){
        if (f[k][i]>n) continue;
        if (!(val[k][i]&v)) k = f[k][i];
    }
    k = Next[k]+1;
    Next[tmp] = min(k, n+1);
}

inline void init(){
    Next[n] = Next[n+1] = n+1;
    for (int i = 0;i<M;i++) f[n+1][i] = n+1;
    for (int i = 0;i<M;i++) f[n][i] = n+1;

    for (int i = n-1;i>=1;i--){
        if (c[i] == c[i+1]) Next[i] = i+1;
        else{
            /*
            int tmp = Next[i+1];
            Next[i] = n+1;
            while (tmp<n){
                if (c[tmp+1] == c[i]){Next[i] = tmp+1; break;}
                tmp = Next[tmp+1];
            } */
            cal(i);
        }
        // if (Next[i]<=i) printf("error\n");
        if (Next[i]>n){
            for (int j = 0;j<M;j++) f[i][j] = n+1;
            continue;
        }
        f[i][0] = Next[i]+1; if (Next[i]<n) val[i][0] = g(Next[i]+1);
        for (int j = 1;j<M;j++){
            f[i][j] = f[ f[i][j-1] ][j-1];
            val[i][j] = val[i][j-1] | val[ f[i][j-1] ][j-1];
        }
        dp[i] = dp[Next[i]+1]+1;
        ans += dp[i];
    }
    // for (int i = 1;i<=n;i++) printf("%d ", Next[i]);
    printf("%lld\n", ans);
}

int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%s", &n, c+1);
    init();
    return 0;
}
/*
self check:
1. freopen
2. long long
3. size of array
4. code for testing
5. initializing
*/
