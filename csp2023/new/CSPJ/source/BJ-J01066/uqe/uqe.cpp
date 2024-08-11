#include <iostream>
#include <cmath>
using namespace std;

// 辗转相除法求最大公约数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 判断是否为完全平方数
bool isPerfectSquare(int n) {
    int x = sqrt(n);
    return x * x == n;
}

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, M;
    cin >> T >> M;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        int delta = b * b - 4 * a * c;
        if (delta < 0) { // 无实数解
            cout << "NO\n";
        } else {
            int x1, x2; // 实数解
            // x1, x2 保证 x1 <= x2
            if (b >= 0) {
                x1 = (-b - sqrt(delta)) / (2 * a);
                x2 = (-b + sqrt(delta)) / (2 * a);
            } else {
                x1 = (-b + sqrt(delta)) / (2 * a);
                x2 = (-b - sqrt(delta)) / (2 * a);
            }
            if (delta == 0) { // 两个实数解相等
                cout << x1 << "\n";
            } else {
                int p = 0, q = 1; // 分数形式的解
                int r = delta;
                if (x1 % x2 == 0) { // 有理数解
                    p = x1 / x2;
                } else { // 无理数解
                    int a1 = x1, a2 = 1;
                    int b1 = x2, b2 = 1;
                    while (true) {
                        // 找到最小的正整数 k，使得 a1 + a2 * k > 0
                        int k = (-a1) / a2;
                        if (a1 + a2 * k <= 0) ++k;
                        // 找到最大的正整数 t，使得 r - (a1 + a2 * k)^2 是正整数且不是完全平方数
                        int t = 0;
                        while (isPerfectSquare(r - (a1 + a2 * k + b1 + b2 * t)*(a1 + a2 * k + b1 + b2 * t))) ++t;
                        // 检查下一个符合条件的组合
                        int a1_next = b1, a2_next = b2;
                        int b1_next = a1 + (2*k+1) * b1 + t * a2;
                        int b2_next = (2 * k + 1) * b2;
                        if (b2_next > M) break; // 超出 b 的上界，退出循环
                        // 更新当前分数形式的解
                        p = b1_next, q = b2_next;
                        // 更新下一步迭代的值
                        a1 = a1_next, a2 = a2_next, b1 = b1_next, b2 = b2_next;
                    }
                }
                if (p != 0) cout << p << "+"; // 输出有理数解的整数部分
                if (q == 1) { // 输出无理数解的形式
                    cout << "sqrt(" << r << ")\n";
                } else if (q > 1 && r != 1) {
                    int c = q / gcd(q, p*r);
                    cout << c * p << "*sqrt(" << r << ")/" << c * r / p << "\n";
                } else { // q == 1 && r != 1
                    cout << p << "*sqrt(" << r << ")\n";
                }
            }
        }
    }
    return 0;
}
