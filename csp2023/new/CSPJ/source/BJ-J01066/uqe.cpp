#include <iostream>
#include <cmath>
using namespace std;

// շת����������Լ��
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// �ж��Ƿ�Ϊ��ȫƽ����
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
        if (delta < 0) { // ��ʵ����
            cout << "NO\n";
        } else {
            int x1, x2; // ʵ����
            // x1, x2 ��֤ x1 <= x2
            if (b >= 0) {
                x1 = (-b - sqrt(delta)) / (2 * a);
                x2 = (-b + sqrt(delta)) / (2 * a);
            } else {
                x1 = (-b + sqrt(delta)) / (2 * a);
                x2 = (-b - sqrt(delta)) / (2 * a);
            }
            if (delta == 0) { // ����ʵ�������
                cout << x1 << "\n";
            } else {
                int p = 0, q = 1; // ������ʽ�Ľ�
                int r = delta;
                if (x1 % x2 == 0) { // ��������
                    p = x1 / x2;
                } else { // ��������
                    int a1 = x1, a2 = 1;
                    int b1 = x2, b2 = 1;
                    while (true) {
                        // �ҵ���С�������� k��ʹ�� a1 + a2 * k > 0
                        int k = (-a1) / a2;
                        if (a1 + a2 * k <= 0) ++k;
                        // �ҵ����������� t��ʹ�� r - (a1 + a2 * k)^2 ���������Ҳ�����ȫƽ����
                        int t = 0;
                        while (isPerfectSquare(r - (a1 + a2 * k + b1 + b2 * t)*(a1 + a2 * k + b1 + b2 * t))) ++t;
                        // �����һ���������������
                        int a1_next = b1, a2_next = b2;
                        int b1_next = a1 + (2*k+1) * b1 + t * a2;
                        int b2_next = (2 * k + 1) * b2;
                        if (b2_next > M) break; // ���� b ���Ͻ磬�˳�ѭ��
                        // ���µ�ǰ������ʽ�Ľ�
                        p = b1_next, q = b2_next;
                        // ������һ��������ֵ
                        a1 = a1_next, a2 = a2_next, b1 = b1_next, b2 = b2_next;
                    }
                }
                if (p != 0) cout << p << "+"; // ��������������������
                if (q == 1) { // ��������������ʽ
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
