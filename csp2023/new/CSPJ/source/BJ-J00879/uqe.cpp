#include <bits/extc++.h>

std::ifstream fin("uqe.in");
std::ofstream fout("uqe.out");

int T, M;
int a, b, c;

auto gcd(int x, int y) -> int {
    if (y == 0) {
        return x;
    }
    if (x - y < 0) {
        x ^= y ^= x ^= y;
    }
    if ((x & 1) && (y & 1)) {
        return gcd(y, x - y);
    }
    if (x & 1) {
        return gcd(x, y >> 1);
    }
    if (y & 1) {
        return gcd(x >> 1, y);
    }
    return gcd(x >> 1, y >> 1) << 1;
}

auto mostMin(int &x, int &y) -> void {
    bool flag = false;
    if (x * y < 0) {
        flag = true;
    }
    x = std::abs(x), y = std::abs(y);
    int g = gcd(x, y);
    x /= g;
    y /= g;
    if (flag) {
        x = -x;
    }
}

auto isSquare(int x) -> bool {
    int s = static_cast<int>(std::sqrt(x));
    return s * s == x;
}

auto getSqrtNum(int x) -> int {
    for (int i = x; i >= 2; --i) {
        if (x % i == 0 && isSquare(i)) {
            return sqrt(i);
        }
    }
    return 1;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    fin.tie(nullptr);
    fin >> T >> M;
    while (T--) {
        fin >> a >> b >> c;
//        fout << a << " " << b << " " << c << "\n";
        if (b * b < 4 * a * c) {
            fout << "NO\n";
            continue;
        }
        if (b * b == 4 * a * c) {
            int x = -b;
            int y = 2 * a;
            mostMin(x, y);
            if (y == 1) {
                fout << x << "\n";
                continue;
            }
            fout << x << "/" << y << "\n";
            continue;
        }
        int derta = b * b - 4 * a * c;
        if (isSquare(derta)) {
            if (a < 0) {
                derta = static_cast<int>(std::sqrt(derta));
                int x = -b - derta;
                int y = 2 * a;
                mostMin(x, y);
                if (y == 1) {
                    fout << x << "\n";
                    continue;
                }
                fout << x << "/" << y << "\n";
                continue;
            }
            derta = static_cast<int>(std::sqrt(derta));
            int x = -b + derta;
            int y = 2 * a;
            mostMin(x, y);
            if (y == 1) {
                fout << x << "\n";
                continue;
            }
            fout << x << "/" << y << "\n";
            continue;
        }
        int x = -b;
        int y = 2 * a;
        if (x != 0) {
            mostMin(x, y);
            if (y == 1) {
                fout << x;
            } else {
                fout << x << "/" << y;
            }
            fout << "+";
        }
        int s = getSqrtNum(derta);
        x = s;
        y = 2 * a;
        mostMin(x, y);
        if (x != 1 && x != -1) {
            fout << std::abs(x) << "*";
        }
        fout << "sqrt(" << derta / s / s << ")";
        if (y != 1) {
            fout << "/" << y;
        }
        fout << "\n";
    }
    fout << std::flush;
}
