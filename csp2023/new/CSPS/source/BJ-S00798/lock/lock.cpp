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

const int M = 1e5, N = 5, K = 10;
int cnt[M+50];
int v[N+50];
int a[N+50];
int n, ans;

inline int cal(){
    int ans = 0;
    for (int i = 1;i<=N;i++){
        ans = ans*10+v[i];
    }
    return ans;
}

int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    read(n);
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=N;j++){
            read(a[j]), v[j] = a[j];
        }
        cnt[cal()] -= 100;

        // one
        for (int j = 1;j<=N;j++){
            for (int k = 1;k<K;k++){
                v[j] = (a[j]+k)%K;
                cnt[cal()]++;
                // printf("%d\n", cal());
            }
            v[j] = a[j];
        }
        // two
        for (int j = 1;j<N;j++){
            for (int k = 1;k<K;k++){
                v[j] = (a[j]+k)%K;
                v[j+1] = (a[j+1]+k)%K;
                cnt[cal()]++;
            }
            v[j] = a[j];
            v[j+1] = a[j+1];
        }
    }
    for (int i = 0;i<M;i++){
        if (cnt[i] == n) ans++;
    }
    printf("%d\n", ans);
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
