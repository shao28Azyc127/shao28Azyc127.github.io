#include <bits/extc++.h>

const int maxn = 1e1 + 7;
const int maxnum = 1e6 + 7;

std::ifstream fin("lock.in");
std::ofstream fout("lock.out");

int n;
std::array<std::string, maxn> a;
int ans = 0;

auto solve() -> void {
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                for (int o = 0; o <= 9; ++o) {
                    for (int l = 0; l <= 9; ++l) {
                        std::string number{i + '0', j + '0', k + '0', o + '0', l + '0'};
                        bool can = true;
                        for (int idx = 1; idx <= n; ++idx) {
                            int num1 = 0, fidx = -1, sidx = -1;
                            for (int idx2 = 0; idx2 < 5; ++idx2) {
                                if (number.at(idx2) != a.at(idx).at(idx2)) {
                                    ++num1;
                                    if (fidx == -1) {
                                        fidx = idx2;
                                    } else if (sidx == -1) {
                                        sidx = idx2;
                                    } else {
                                        break;
                                    }
                                }
                            }
                            if (num1 == 0) {
                                can = false;
                                break;
                            }
                            if (sidx == -1) {
                                continue;
                            }
                            if (num1 >= 3 || sidx - fidx != 1) {
                                can = false;
                                break;
                            }
                            if ((number.at(fidx) - a.at(idx).at(fidx) + 10) % 10 != (number.at(sidx) - a.at(idx).at(sidx) + 10) % 10) {
                                can = false;
                                break;
                            }
                        }
                        if (can) {

                           ++ans;
                        }
                    }
                }
            }
        }
    }
}

auto main() -> int {
    fin >> n;
    // fout << n << std::endl;
    for (int i = 1; i <= n; ++i) {
        int a1, b, c, d, e;
        fin >> a1 >> b >> c >> d >> e;
        a.at(i) = std::to_string(a1) + std::to_string(b) + std::to_string(c) + std::to_string(d) + std::to_string(e);
        // fout << a.at(i) << std::endl;
    }
    solve();
    fout << ans << std::endl;
    return 0;
}
