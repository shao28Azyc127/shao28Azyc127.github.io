// uqe.cpp  X δ��ɣ�����

#include <iostream>
#include <math.h>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

void compute(int a, int b, int c) {
    int n = b * b - 4 * a * c;
    if (n < 0) {
        cout << "NO";
        return;
    }

    int sqrtn = sqrt(n);
    if (sqrtn * sqrtn == n) {
        int p = -b + sqrtn; int q = 2 * a;
        if (q < 0) { p *= -1; q *= -1; }  // ? ��ȷ��
        int gcdn = gcd(p, q); p /= gcdn; q /= gcdn;

        cout << p;
        if (q != 1) {
            cout << "/" << q;
        }
    } else {
        // TODO: r Ϊ�������� r > 1,�Ҳ����������� d > 1 ʹ r �� d^2 �ı�
        // ��)
        int r = n;
        double q2 = 0.5*a;  // ������
        double q1 = -b*q2;  // ������
//        for (int d = 2; d <= sqrt(r); d++) {
//            if (r % d * d == 0) {
//                r /= d * d;
//
//            }
//        }

        if (q1 != 0) {
            int p = q1 * 2; int q = 2;
            if (q < 0) { p *= -1; q *= -1; }  // ? ��ȷ��
            int gcdn = gcd(p, q); p /= gcdn; q /= gcdn;
            cout << p;
            if (q != 1) {
                cout << "/" << q;
            }
            cout << "+";
        }
        if (q2 == 1) cout << "sqrt(" << r << ")";
        // 1 ? q2 = 2 ? a
        else if (a == 1 || a == 2) cout << "sqrt(" << r << ")/" << 2 / a;
        else {
            int p = q2*2; int q = 2;
            if (q < 0) { p *= -1; q *= -1; }  // ? ��ȷ��
            int gcdn = gcd(p, q); p /= gcdn; q /= gcdn;
            cout << p << "*sqrt(" << r << ")/" << q;
        }
    }
}

int main() {freopen("uqe2.in","r",stdin);freopen("uqe.out","w",stdout);
    int t, m; cin >> t >> m;
    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        compute(a, b, c);
        cout << endl;
    }
    return 0;
}
