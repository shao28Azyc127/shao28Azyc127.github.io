#include <bits/stdc++.h>

std::ifstream fin("apple.in");
std::ofstream fout("apple.out");

int n;

auto solve1(int x) -> int {
    if (x <= 3) {
        return x;
    }
    return solve1(x - std::ceil(x / 3.0)) + 1;
}

auto solve2(int x) -> int {
    if (x % 3 == 1) {
        return 1;
    }
    return solve2(x - std::ceil(x / 3.0)) + 1;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    fin.tie(nullptr);
    fin >> n;
    fout << solve1(n) << " " << solve2(n) << "\n";
    return 0;
}
