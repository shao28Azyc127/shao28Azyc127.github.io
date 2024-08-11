#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int maxn = 2e6 + 5;
const ll mod = 1e9 + 7;

ll invp(ll a)
{
    ll ans = 1, b = mod - 2;
    while (b)
    {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

map<pair<pair<ull, ull>, ull> , ll> mp;

char s[maxn];
int cnt[maxn];
int pos[26][2], mindis[maxn];
int st[maxn], b[maxn], sz, nxt[26];

ull XOR[maxn], nwt[26], nwt2[26], XOR2[maxn];

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n >> s + 1;
    for (int i = 1; i <= n; i++)
    {
        int ch = s[i] - 'a';
        st[i] = st[i - 1] ^ (1 << ch);
        b[++sz] = st[i];
    }
    b[++sz] = 0;

    sort(b + 1, b + sz + 1);
    sz = unique(b + 1, b + sz + 1) - b - 1;

    ull mul = 1;
    srand(time(0));
    for (int i = 1; i <= sz; i++)
    {
        mul *= 1313131;
        XOR[i] = mul;
        XOR2[i] = (ull)rand() * rand() * 13131;
    }
    for (int i = 0; i <= n; i++)
        st[i] = lower_bound(b + 1, b + sz + 1, st[i]) - b;
    
    ll ans = 0;
    mp[make_pair(make_pair(0, 0), 1)] = 1;
    for (int i = n; i; i--)
    {
        int ch = s[i] - 'a';
        nwt[ch] ^= XOR[st[i - 1]] ^ XOR[st[i]];
        nwt2[ch] += XOR2[st[i - 1]] - XOR2[st[i]];

        ull hsh = 0, hsh2 = 0, hsh3 = 0;
        for (int j = 0; j < 26; j++)
        {
            hsh = hsh * 1313131 + nwt[j];
            hsh2 = hsh2 * 14440057 + nwt2[j];
        }
        ans += mp[make_pair(make_pair(hsh, hsh2), (ull)st[i - 1])];
        mp[make_pair(make_pair(hsh, hsh2), (ull)st[i - 1])]++;
    }

    cout << ans;
    return 0;
}