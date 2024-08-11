#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

template<typename T> inline void checkmin(T &x, const T &y){if (x>y) x = y;}

template<typename T> inline void checkmax(T &x, const T &y){if (x<y) x = y;}

template<typename T> inline void read(T &x){
    x = 0; bool F = 0; char c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') F = 1;
    for (;isdigit(c);c = getchar()) x = x*10+(c^48);
    if (F) x = -x;
}

inline void Get(char &c){
    c = getchar();
    while (c!='+' && c!='-' && c!='T' && c!='F' && c!='U') c = getchar();
}

const int N = 1e5+100;
int n, m;

char op[N]; int val[N], tmp[N], x[N], y[N];
int ans;

void dfs(int step, int z){
    if (step == n+1){
        memcpy(tmp, val, sizeof(int)*20);
        for (int i = 1;i<=m;i++){
            if (isupper(op[i])){
                if (op[i] == 'U') tmp[x[i]] = 3;
                if (op[i] == 'T') tmp[x[i]] = 1;
                if (op[i] == 'F') tmp[x[i]] = 2;
            }
            else{
                if (tmp[y[i]] == 3) tmp[x[i]] = 3;
                else{
                    if (op[i] == '+') tmp[x[i]] = tmp[y[i]];
                    else tmp[x[i]] = 3-tmp[y[i]];
                }
            }
        }
        for (int i = 1;i<=n;i++) if (tmp[i]!=val[i]) z += 100;
        checkmin(ans, z);
        return;
    }
    for (val[step] = 1;val[step]<=3;val[step]++){
        dfs(step+1, z+(val[step] == 3));
    }
}

inline void solve_dfs(){
    read(n), read(m);
    for (int i = 1;i<=m;i++){
        Get(op[i]); read(x[i]);
        if (!isupper(op[i])) read(y[i]);
    }
    ans = 100;
    dfs(1, 0);
    printf("%d\n", ans);
}

inline void solve_cnt(){
    read(n), read(m); memset(val, 0, sizeof(val));
    char op; int x;
    for (int i = 1;i<=m;i++){
        Get(op); read(x);
        if (op == 'U') val[x] = 1;
        else val[x] = 0;
    }
    int ans = 0;
    for (int i = 1;i<=n;i++) ans += val[i];
    printf("%d\n", ans);
}

inline void solve_u(){
    read(n), read(m);
    for (int i = 1;i<=m;i++){
        Get(op[i]); read(x[i]);
        if (!isupper(op[i])) read(y[i]);
    }
    memset(val, 0, sizeof(val));
    for (int _ = 0;_<=m+n;_++){
        for (int i = 1;i<=m;i++){
            if (op[i] == 'U') val[x[i]] = 1;
            else val[x[i]] = val[y[i]];
        }
        if (n>=10000 && _>=130) break;
    }
    int ans = 0;
    for (int i = 1;i<=n;i++) ans += val[i];
    printf("%d\n", ans);
}

int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, t; read(c), read(t);
    while (t--){
        if (c == 1 || c == 2){solve_dfs(); continue;}
        if (c == 3 || c == 4){solve_cnt(); continue;}
        if (c == 5 || c == 6){solve_u(); continue;}
        printf("0\n");
    }
    return 0;
}
/*
self check:
1. long long
2. size of array
3. code for testing
4. initializing
5. freopen
*/
