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

const int N = 3100;
int Max[N], Min[N];
char c[N];
int n, m; // n * m

int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1;i<=n;i++){
        scanf("%s", c+1); Min[i] = 1e4;
        for (int j = 1;j<=m;j++) checkmax(Max[i], (int)c[j]), checkmin(Min[i], (int)c[j]);
    }
    int f;
    for (int i = 1;i<=n;i++){
        f = 1;
        for (int j = 1;j<=n;j++){
            if (i!=j && Max[j]<=Min[i]){
                f = 0; break;
            }
        }
        printf("%d", f);
    }
    printf("\n");
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
