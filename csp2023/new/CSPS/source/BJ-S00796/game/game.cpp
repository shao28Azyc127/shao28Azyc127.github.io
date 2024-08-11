#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#define maxn 3000005
#define mod 998244353
#define ll unsigned long long
#define eps 1e-7
using namespace std;
int n;
char s[maxn];
ll P1 = 23333ull, Pd1[maxn];
ll P2 = 37777ull, Pd2[maxn];
ll ans = 0;
struct node {
    ll s1, s2;
    bool operator < (const node &p) const {
        return (s1 == p.s1) ? (s2 < p.s2) : (s1 < p.s1);
    }
    bool operator != (const node &p) const {
        return (s1 != p.s1) || (s2 != p.s2);
    }
} sta[maxn];
char st[maxn];
int top = 0;
ll C (int x) {
    return 1ull * x * (x-1ull) / 2ull;
}
int main () {
    freopen ("game.in", "r", stdin);
    freopen ("game.out", "w", stdout);
    cin >> n >> (s+1);
    Pd1[0] = Pd2[0] = 1ull;
    for (int i = 1; i <= n; i++)
        Pd1[i] = Pd1[i-1] * P1, Pd2[i] = Pd2[i-1] * P2;
    st[0] = '$';
    for (int i = 1; i <= n; i++) {
        if (s[i] == st[top]) {
            top--;
            sta[i].s1 = sta[i-1].s1 - s[i] * Pd1[top];
            sta[i].s2 = sta[i-1].s2 - s[i] * Pd2[top];
        } else {
            sta[i].s1 = sta[i-1].s1 + s[i] * Pd1[top];
            sta[i].s2 = sta[i-1].s2 + s[i] * Pd2[top];
            st[++top] = s[i];
        }
    }
    sort (sta+1, sta+n+1);
    sta[n+1].s2 = sta[n].s2-1;
    int lst = 0;
    for (int i = 1; i <= n+1; i++) {
        if (sta[i] != sta[i-1]) {
            ans += C (i - lst);
            lst = i;
        }
    }
    printf ("%llu\n", ans);
    return 0;
}