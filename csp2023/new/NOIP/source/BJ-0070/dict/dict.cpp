#include <bits/stdc++.h>
const int MAXN = 3005;
std::map<std::string, int> S;
std::string s[MAXN], t[MAXN];
bool ans[MAXN];

bool check(const std::string &s) {
    for(int i = 0; i < s.size(); ++i)
        if(s[i] != s[0])
            return true;
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        std::cin >> s[i];
        t[i] = s[i];
        std::sort(t[i].begin(), t[i].end(), std::greater<char>());
        //std::cout << t[i] << '\n';
        ++S[t[i]];
    }
    for(int i = 1; i <= n; ++i) {
        auto it = S.find(t[i]);
        if(it->second > 1 && !check(t[i]))
            continue;
        S.erase(it);
        std::sort(s[i].begin(), s[i].end());
        //std::cout << s[i] << '\n';
        if(S.upper_bound(s[i]) == S.begin())
            ans[i] = 1;
        S[t[i]] = 1;
    }
    for(int i = 1; i <= n; ++i)
        std::cout << ans[i];
    putchar('\n');
    return 0;
}