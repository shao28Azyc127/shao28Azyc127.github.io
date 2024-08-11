#include <bits/stdc++.h>

const int maxn = 1e5 + 7;

std::ifstream fin("road.in");
std::ofstream fout("road.out");

using pii = std::pair<long long int, long long int>;

long long int n, d;
long long int sum = 0, nowi = 1, nowd = 0;
long long int ans = 0;
std::array<int, maxn> a, v;
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> que;

auto main() -> int {
    std::ios::sync_with_stdio(false);
    fin.tie(nullptr);
    fin >> n >> d;
    for (int i = 1; i < n; ++i) {
        fin >> a.at(i);
        sum += a.at(i);
    }
    for (int i = 1; i <= n; ++i) {
        fin >> v.at(i);
    }
    while (nowi < n) {
        que.emplace(v.at(nowi), nowi);
        long long int cheapest, id;
        std::tie(cheapest, id) = que.top();
        while (nowd < a.at(nowi)) {
            ans += v.at(id);
            nowd += d;
        }
        nowd -= a.at(nowi);
        ++nowi;
    }
    fout << ans << std::endl;
    return 0;
}
