#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
const int N = 2e6 + 10;
inline int read ()
{
    int x = 0, f = 1;
    char c = getchar ();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar (); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar (); }
    return x * f;
}
int n;
long long ans;
char s[N];
int root, p;
struct Trie {
    int node;
    struct node {
        int ch[26];
        int val, fa;
        #define ch(x, y) tree[x].ch[y]
        #define val(x) tree[x].val
        #define fa(x) tree[x].fa
    } tree[N];
    void clear (int rt)
    {
        for (int i = 0; i < 26; i++)
        {
            if (ch(rt, i)) clear (ch(rt, i));
            ch(rt, i) = 0;
        }
        val(rt) = 0; fa(rt) = 0;
    }
    void insert (int x, int s)
    {
        if (!ch(x, s))
        {
            ch(x, s) = ++node;
            fa(ch(x, s)) = x;
        }
        p = ch(x, s);
    }
} T;
void divide (int l, int r)
{
    if (l == r) return ;
    if (l + 1 == r)
    {
        if (s[l] == s[r]) ans++;
        return ;
    }
    int mid = (l + r) >> 1;
    divide (l, mid);
    divide (mid + 1, r);
    T.clear (root); root = p = 1; T.node = 1;
    stack <int> st;
    for (int i = mid; i >= l; i--)
    {
        if (st.empty ())
        {
            st.push (s[i] - 'a');
            T.insert (p, s[i] - 'a');
            T.tree[p].val++;
        }
        else
        {
            if (st.top() == s[i] - 'a') p = T.tree[p].fa, st.pop();
            else T.insert (p, s[i] - 'a'), st.push (s[i] - 'a');
            T.tree[p].val++;
        }
    }
    while (!st.empty()) st.pop();
    p = 1;
    for (int i = mid + 1; i <= r; i++)
    {
        if (st.empty ())
        {
            st.push (s[i] - 'a');
            T.insert (p, s[i] - 'a');
            ans += T.tree[p].val;
        }
        else
        {
            if (st.top() == s[i] - 'a') p = T.tree[p].fa, st.pop();
            else T.insert (p, s[i] - 'a'), st.push (s[i] - 'a');
            ans += T.tree[p].val;
        }
    }
    return ;
}
signed main ()
{
    freopen ("game.in", "r", stdin);
    freopen ("game.out", "w", stdout);
    n = read ();
    for (int i = 1; i <= n; i++) s[i] = getchar ();
    divide(1, n);
    printf ("%lld\n", ans);
    return 0;
}