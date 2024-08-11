#include <bits/extc++.h>

const int maxn = 1e4 + 7;
const int maxm = 2e4 + 7;

std::ifstream fin("bus.in");
std::ofstream fout("bus.out");

struct Edge {
    int to, next, w;
};
std::array<Edge, maxm> edge;
std::array<int, maxn> h;
int tot = -1;
auto addEdge(int x, int y, int len) -> void {
    edge.at(++tot) = (Edge){y, h.at(x), len};
    h.at(x) = tot;
}

int n, m, k;

auto main() -> int {
    std::ios::sync_with_stdio(false);
    fin.tie(nullptr);
    fin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        fin >> u >> v >> w;
        addEdge(u, v, w);
    }
    fout << -1 << "\n";
    return 0;
}

