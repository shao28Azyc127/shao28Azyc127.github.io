#include <iostream>
using namespace std;
int n, cnt;
bool wcnmd1[100005], wcnmd2[100005], wcnmd3[100005], wcnmd4[100005], wcnmd5[100005], wcnmd6[100005], wcnmd7[100005], wcnmd8[100005];

int a, b, c, d, e;
int a1, b1, c1, d1, e1;
int a2, b2, c2, d2, e2;
int a3, b3, c3, d3, e3;
int a4, b4, c4, d4, e4;
int a5, b5, c5, d5, e5;
int a6, b6, c6, d6, e6;
int a7, b7, c7, d7, e7;
int a8, b8, c8, d8, e8;
int a9, b9, c9, d9, e9;

int ab1, bc1, cd1, de1;
int ab2, bc2, cd2, de2;
int ab3, bc3, cd3, de3;
int ab4, bc4, cd4, de4;
int ab5, bc5, cd5, de5;
int ab6, bc6, cd6, de6;
int ab7, bc7, cd7, de7;
int ab8, bc8, cd8, de8;
int ab9, bc9, cd9, de9;

int aa0;
int aa1, bb1, cc1, dd1, ee1;
int aa2, bb2, cc2, dd2, ee2;
int aa3, bb3, cc3, dd3, ee3;
int aa4, bb4, cc4, dd4, ee4;
int aa5, bb5, cc5, dd5, ee5;
int aa6, bb6, cc6, dd6, ee6;
int aa7, bb7, cc7, dd7, ee7;
int aa8, bb8, cc8, dd8, ee8;
int aa9, bb9, cc9, dd9, ee9;

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a >> b >> c >> d >> e;
        a1 = (a + 1) % 10, b1 = (b + 1) % 10, c1 = (c + 1) % 10, d1 = (d + 1) % 10, e1 = (e + 1) % 10;
        a2 = (a + 2) % 10, b2 = (b + 2) % 10, c2 = (c + 2) % 10, d2 = (d + 2) % 10, e2 = (e + 2) % 10;
        a3 = (a + 3) % 10, b3 = (b + 3) % 10, c3 = (c + 3) % 10, d3 = (d + 3) % 10, e3 = (e + 3) % 10;
        a4 = (a + 4) % 10, b4 = (b + 4) % 10, c4 = (c + 4) % 10, d4 = (d + 4) % 10, e4 = (e + 4) % 10;
        a5 = (a + 5) % 10, b5 = (b + 5) % 10, c5 = (c + 5) % 10, d5 = (d + 5) % 10, e5 = (e + 5) % 10;
        a6 = (a + 6) % 10, b6 = (b + 6) % 10, c6 = (c + 6) % 10, d6 = (d + 6) % 10, e6 = (e + 6) % 10;
        a7 = (a + 7) % 10, b7 = (b + 7) % 10, c7 = (c + 7) % 10, d7 = (d + 7) % 10, e7 = (e + 7) % 10;
        a8 = (a + 8) % 10, b8 = (b + 8) % 10, c8 = (c + 8) % 10, d8 = (d + 8) % 10, e8 = (e + 8) % 10;
        a9 = (a + 9) % 10, b9 = (b + 9) % 10, c9 = (c + 9) % 10, d9 = (d + 9) % 10, e9 = (e + 9) % 10;

        aa1 = a1 * 10000 + b * 1000 + c * 100 + d * 10 + e;
        aa2 = a2 * 10000 + b * 1000 + c * 100 + d * 10 + e;
        aa3 = a3 * 10000 + b * 1000 + c * 100 + d * 10 + e;
        aa4 = a4 * 10000 + b * 1000 + c * 100 + d * 10 + e;
        aa5 = a5 * 10000 + b * 1000 + c * 100 + d * 10 + e;
        aa6 = a6 * 10000 + b * 1000 + c * 100 + d * 10 + e;
        aa7 = a7 * 10000 + b * 1000 + c * 100 + d * 10 + e;
        aa8 = a8 * 10000 + b * 1000 + c * 100 + d * 10 + e;
        aa9 = a9 * 10000 + b * 1000 + c * 100 + d * 10 + e;

        bb1 = a * 10000 + b1 * 1000 + c * 100 + d * 10 + e;
        bb2 = a * 10000 + b2 * 1000 + c * 100 + d * 10 + e;
        bb3 = a * 10000 + b3 * 1000 + c * 100 + d * 10 + e;
        bb4 = a * 10000 + b4 * 1000 + c * 100 + d * 10 + e;
        bb5 = a * 10000 + b5 * 1000 + c * 100 + d * 10 + e;
        bb6 = a * 10000 + b6 * 1000 + c * 100 + d * 10 + e;
        bb7 = a * 10000 + b7 * 1000 + c * 100 + d * 10 + e;
        bb8 = a * 10000 + b8 * 1000 + c * 100 + d * 10 + e;
        bb9 = a * 10000 + b9 * 1000 + c * 100 + d * 10 + e;

        cc1 = a * 10000 + b * 1000 + c1 * 100 + d * 10 + e;
        cc2 = a * 10000 + b * 1000 + c2 * 100 + d * 10 + e;
        cc3 = a * 10000 + b * 1000 + c3 * 100 + d * 10 + e;
        cc4 = a * 10000 + b * 1000 + c4 * 100 + d * 10 + e;
        cc5 = a * 10000 + b * 1000 + c5 * 100 + d * 10 + e;
        cc6 = a * 10000 + b * 1000 + c6 * 100 + d * 10 + e;
        cc7 = a * 10000 + b * 1000 + c7 * 100 + d * 10 + e;
        cc8 = a * 10000 + b * 1000 + c8 * 100 + d * 10 + e;
        cc9 = a * 10000 + b * 1000 + c9 * 100 + d * 10 + e;

        dd1 = a * 10000 + b * 1000 + c * 100 + d1 * 10 + e;
        dd2 = a * 10000 + b * 1000 + c * 100 + d2 * 10 + e;
        dd3 = a * 10000 + b * 1000 + c * 100 + d3 * 10 + e;
        dd4 = a * 10000 + b * 1000 + c * 100 + d4 * 10 + e;
        dd5 = a * 10000 + b * 1000 + c * 100 + d5 * 10 + e;
        dd6 = a * 10000 + b * 1000 + c * 100 + d6 * 10 + e;
        dd7 = a * 10000 + b * 1000 + c * 100 + d7 * 10 + e;
        dd8 = a * 10000 + b * 1000 + c * 100 + d8 * 10 + e;
        dd9 = a * 10000 + b * 1000 + c * 100 + d9 * 10 + e;


        ee1 = a * 10000 + b * 1000 + c * 100 + d * 10 + e1;
        ee2 = a * 10000 + b * 1000 + c * 100 + d * 10 + e2;
        ee3 = a * 10000 + b * 1000 + c * 100 + d * 10 + e3;
        ee4 = a * 10000 + b * 1000 + c * 100 + d * 10 + e4;
        ee5 = a * 10000 + b * 1000 + c * 100 + d * 10 + e5;
        ee6 = a * 10000 + b * 1000 + c * 100 + d * 10 + e6;
        ee7 = a * 10000 + b * 1000 + c * 100 + d * 10 + e7;
        ee8 = a * 10000 + b * 1000 + c * 100 + d * 10 + e8;
        ee9 = a * 10000 + b * 1000 + c * 100 + d * 10 + e9;


        ab1 = a1 * 10000 + b1 * 1000 + c * 100 + d * 10 + e;
        ab2 = a2 * 10000 + b2 * 1000 + c * 100 + d * 10 + e;
        ab3 = a3 * 10000 + b3 * 1000 + c * 100 + d * 10 + e;
        ab4 = a4 * 10000 + b4 * 1000 + c * 100 + d * 10 + e;
        ab5 = a5 * 10000 + b5 * 1000 + c * 100 + d * 10 + e;
        ab6 = a6 * 10000 + b6 * 1000 + c * 100 + d * 10 + e;
        ab7 = a7 * 10000 + b7 * 1000 + c * 100 + d * 10 + e;
        ab8 = a8 * 10000 + b8 * 1000 + c * 100 + d * 10 + e;
        ab9 = a9 * 10000 + b9 * 1000 + c * 100 + d * 10 + e;


        bc1 = a * 10000 + b1 * 1000 + c1 * 100 + d * 10 + e;
        bc2 = a * 10000 + b2 * 1000 + c2 * 100 + d * 10 + e;
        bc3 = a * 10000 + b3 * 1000 + c3 * 100 + d * 10 + e;
        bc4 = a * 10000 + b4 * 1000 + c4 * 100 + d * 10 + e;
        bc5 = a * 10000 + b5 * 1000 + c5 * 100 + d * 10 + e;
        bc6 = a * 10000 + b6 * 1000 + c6 * 100 + d * 10 + e;
        bc7 = a * 10000 + b7 * 1000 + c7 * 100 + d * 10 + e;
        bc8 = a * 10000 + b8 * 1000 + c8 * 100 + d * 10 + e;
        bc9 = a * 10000 + b9 * 1000 + c9 * 100 + d * 10 + e;


        cd1 = a * 10000 + b * 1000 + c1 * 100 + d1 * 10 + e;
        cd2 = a * 10000 + b * 1000 + c2 * 100 + d2 * 10 + e;
        cd3 = a * 10000 + b * 1000 + c3 * 100 + d3 * 10 + e;
        cd4 = a * 10000 + b * 1000 + c4 * 100 + d4 * 10 + e;
        cd5 = a * 10000 + b * 1000 + c5 * 100 + d5 * 10 + e;
        cd6 = a * 10000 + b * 1000 + c6 * 100 + d6 * 10 + e;
        cd7 = a * 10000 + b * 1000 + c7 * 100 + d7 * 10 + e;
        cd8 = a * 10000 + b * 1000 + c8 * 100 + d8 * 10 + e;
        cd9 = a * 10000 + b * 1000 + c9 * 100 + d9 * 10 + e;


        de1 = a * 10000 + b * 1000 + c * 100 + d1 * 10 + e1;
        de2 = a * 10000 + b * 1000 + c * 100 + d2 * 10 + e2;
        de3 = a * 10000 + b * 1000 + c * 100 + d3 * 10 + e3;
        de4 = a * 10000 + b * 1000 + c * 100 + d4 * 10 + e4;
        de5 = a * 10000 + b * 1000 + c * 100 + d5 * 10 + e5;
        de6 = a * 10000 + b * 1000 + c * 100 + d6 * 10 + e6;
        de7 = a * 10000 + b * 1000 + c * 100 + d7 * 10 + e7;
        de8 = a * 10000 + b * 1000 + c * 100 + d8 * 10 + e8;
        de9 = a * 10000 + b * 1000 + c * 100 + d9 * 10 + e9;

        if(i == 1) {
            wcnmd1[aa1] = true;
            wcnmd1[aa2] = true;
            wcnmd1[aa3] = true;
            wcnmd1[aa4] = true;
            wcnmd1[aa5] = true;
            wcnmd1[aa6] = true;
            wcnmd1[aa7] = true;
            wcnmd1[aa8] = true;
            wcnmd1[aa9] = true;

            wcnmd1[bb1] = true;
            wcnmd1[bb2] = true;
            wcnmd1[bb3] = true;
            wcnmd1[bb4] = true;
            wcnmd1[bb5] = true;
            wcnmd1[bb6] = true;
            wcnmd1[bb7] = true;
            wcnmd1[bb8] = true;
            wcnmd1[bb9] = true;

            wcnmd1[cc1] = true;
            wcnmd1[cc2] = true;
            wcnmd1[cc3] = true;
            wcnmd1[cc4] = true;
            wcnmd1[cc5] = true;
            wcnmd1[cc6] = true;
            wcnmd1[cc7] = true;
            wcnmd1[cc8] = true;
            wcnmd1[cc9] = true;

            wcnmd1[dd1] = true;
            wcnmd1[dd2] = true;
            wcnmd1[dd3] = true;
            wcnmd1[dd4] = true;
            wcnmd1[dd5] = true;
            wcnmd1[dd6] = true;
            wcnmd1[dd7] = true;
            wcnmd1[dd8] = true;
            wcnmd1[dd9] = true;

            wcnmd1[ee1] = true;
            wcnmd1[ee2] = true;
            wcnmd1[ee3] = true;
            wcnmd1[ee4] = true;
            wcnmd1[ee5] = true;
            wcnmd1[ee6] = true;
            wcnmd1[ee7] = true;
            wcnmd1[ee8] = true;
            wcnmd1[ee9] = true;

            wcnmd1[ab1] = true;
            wcnmd1[ab2] = true;
            wcnmd1[ab3] = true;
            wcnmd1[ab4] = true;
            wcnmd1[ab5] = true;
            wcnmd1[ab6] = true;
            wcnmd1[ab7] = true;
            wcnmd1[ab8] = true;
            wcnmd1[ab9] = true;

            wcnmd1[bc1] = true;
            wcnmd1[bc2] = true;
            wcnmd1[bc3] = true;
            wcnmd1[bc4] = true;
            wcnmd1[bc5] = true;
            wcnmd1[bc6] = true;
            wcnmd1[bc7] = true;
            wcnmd1[bc8] = true;
            wcnmd1[bc9] = true;

            wcnmd1[cd1] = true;
            wcnmd1[cd2] = true;
            wcnmd1[cd3] = true;
            wcnmd1[cd4] = true;
            wcnmd1[cd5] = true;
            wcnmd1[cd6] = true;
            wcnmd1[cd7] = true;
            wcnmd1[cd8] = true;
            wcnmd1[cd9] = true;

            wcnmd1[de1] = true;
            wcnmd1[de2] = true;
            wcnmd1[de3] = true;
            wcnmd1[de4] = true;
            wcnmd1[de5] = true;
            wcnmd1[de6] = true;
            wcnmd1[de7] = true;
            wcnmd1[de8] = true;
            wcnmd1[de9] = true;
        }

        if(i == 2) {
            wcnmd2[aa1] = true;
            wcnmd2[aa2] = true;
            wcnmd2[aa3] = true;
            wcnmd2[aa4] = true;
            wcnmd2[aa5] = true;
            wcnmd2[aa6] = true;
            wcnmd2[aa7] = true;
            wcnmd2[aa8] = true;
            wcnmd2[aa9] = true;

            wcnmd2[bb1] = true;
            wcnmd2[bb2] = true;
            wcnmd2[bb3] = true;
            wcnmd2[bb4] = true;
            wcnmd2[bb5] = true;
            wcnmd2[bb6] = true;
            wcnmd2[bb7] = true;
            wcnmd2[bb8] = true;
            wcnmd2[bb9] = true;

            wcnmd2[cc1] = true;
            wcnmd2[cc2] = true;
            wcnmd2[cc3] = true;
            wcnmd2[cc4] = true;
            wcnmd2[cc5] = true;
            wcnmd2[cc6] = true;
            wcnmd2[cc7] = true;
            wcnmd2[cc8] = true;
            wcnmd2[cc9] = true;

            wcnmd2[dd1] = true;
            wcnmd2[dd2] = true;
            wcnmd2[dd3] = true;
            wcnmd2[dd4] = true;
            wcnmd2[dd5] = true;
            wcnmd2[dd6] = true;
            wcnmd2[dd7] = true;
            wcnmd2[dd8] = true;
            wcnmd2[dd9] = true;

            wcnmd2[ee1] = true;
            wcnmd2[ee2] = true;
            wcnmd2[ee3] = true;
            wcnmd2[ee4] = true;
            wcnmd2[ee5] = true;
            wcnmd2[ee6] = true;
            wcnmd2[ee7] = true;
            wcnmd2[ee8] = true;
            wcnmd2[ee9] = true;

            wcnmd2[ab1] = true;
            wcnmd2[ab2] = true;
            wcnmd2[ab3] = true;
            wcnmd2[ab4] = true;
            wcnmd2[ab5] = true;
            wcnmd2[ab6] = true;
            wcnmd2[ab7] = true;
            wcnmd2[ab8] = true;
            wcnmd2[ab9] = true;

            wcnmd2[bc1] = true;
            wcnmd2[bc2] = true;
            wcnmd2[bc3] = true;
            wcnmd2[bc4] = true;
            wcnmd2[bc5] = true;
            wcnmd2[bc6] = true;
            wcnmd2[bc7] = true;
            wcnmd2[bc8] = true;
            wcnmd2[bc9] = true;

            wcnmd2[cd1] = true;
            wcnmd2[cd2] = true;
            wcnmd2[cd3] = true;
            wcnmd2[cd4] = true;
            wcnmd2[cd5] = true;
            wcnmd2[cd6] = true;
            wcnmd2[cd7] = true;
            wcnmd2[cd8] = true;
            wcnmd2[cd9] = true;

            wcnmd2[de1] = true;
            wcnmd2[de2] = true;
            wcnmd2[de3] = true;
            wcnmd2[de4] = true;
            wcnmd2[de5] = true;
            wcnmd2[de6] = true;
            wcnmd2[de7] = true;
            wcnmd2[de8] = true;
            wcnmd2[de9] = true;
        }

        if(i == 3) {
            wcnmd3[aa1] = true;
            wcnmd3[aa2] = true;
            wcnmd3[aa3] = true;
            wcnmd3[aa4] = true;
            wcnmd3[aa5] = true;
            wcnmd3[aa6] = true;
            wcnmd3[aa7] = true;
            wcnmd3[aa8] = true;
            wcnmd3[aa9] = true;

            wcnmd3[bb1] = true;
            wcnmd3[bb2] = true;
            wcnmd3[bb3] = true;
            wcnmd3[bb4] = true;
            wcnmd3[bb5] = true;
            wcnmd3[bb6] = true;
            wcnmd3[bb7] = true;
            wcnmd3[bb8] = true;
            wcnmd3[bb9] = true;

            wcnmd3[cc1] = true;
            wcnmd3[cc2] = true;
            wcnmd3[cc3] = true;
            wcnmd3[cc4] = true;
            wcnmd3[cc5] = true;
            wcnmd3[cc6] = true;
            wcnmd3[cc7] = true;
            wcnmd3[cc8] = true;
            wcnmd3[cc9] = true;

            wcnmd3[dd1] = true;
            wcnmd3[dd2] = true;
            wcnmd3[dd3] = true;
            wcnmd3[dd4] = true;
            wcnmd3[dd5] = true;
            wcnmd3[dd6] = true;
            wcnmd3[dd7] = true;
            wcnmd3[dd8] = true;
            wcnmd3[dd9] = true;

            wcnmd3[ee1] = true;
            wcnmd3[ee2] = true;
            wcnmd3[ee3] = true;
            wcnmd3[ee4] = true;
            wcnmd3[ee5] = true;
            wcnmd3[ee6] = true;
            wcnmd3[ee7] = true;
            wcnmd3[ee8] = true;
            wcnmd3[ee9] = true;

            wcnmd3[ab1] = true;
            wcnmd3[ab2] = true;
            wcnmd3[ab3] = true;
            wcnmd3[ab4] = true;
            wcnmd3[ab5] = true;
            wcnmd3[ab6] = true;
            wcnmd3[ab7] = true;
            wcnmd3[ab8] = true;
            wcnmd3[ab9] = true;

            wcnmd3[bc1] = true;
            wcnmd3[bc2] = true;
            wcnmd3[bc3] = true;
            wcnmd3[bc4] = true;
            wcnmd3[bc5] = true;
            wcnmd3[bc6] = true;
            wcnmd3[bc7] = true;
            wcnmd3[bc8] = true;
            wcnmd3[bc9] = true;

            wcnmd3[cd1] = true;
            wcnmd3[cd2] = true;
            wcnmd3[cd3] = true;
            wcnmd3[cd4] = true;
            wcnmd3[cd5] = true;
            wcnmd3[cd6] = true;
            wcnmd3[cd7] = true;
            wcnmd3[cd8] = true;
            wcnmd3[cd9] = true;

            wcnmd3[de1] = true;
            wcnmd3[de2] = true;
            wcnmd3[de3] = true;
            wcnmd3[de4] = true;
            wcnmd3[de5] = true;
            wcnmd3[de6] = true;
            wcnmd3[de7] = true;
            wcnmd3[de8] = true;
            wcnmd3[de9] = true;
        }

        if(i == 4) {
            wcnmd4[aa1] = true;
            wcnmd4[aa2] = true;
            wcnmd4[aa3] = true;
            wcnmd4[aa4] = true;
            wcnmd4[aa5] = true;
            wcnmd4[aa6] = true;
            wcnmd4[aa7] = true;
            wcnmd4[aa8] = true;
            wcnmd4[aa9] = true;

            wcnmd4[bb1] = true;
            wcnmd4[bb2] = true;
            wcnmd4[bb3] = true;
            wcnmd4[bb4] = true;
            wcnmd4[bb5] = true;
            wcnmd4[bb6] = true;
            wcnmd4[bb7] = true;
            wcnmd4[bb8] = true;
            wcnmd4[bb9] = true;

            wcnmd4[cc1] = true;
            wcnmd4[cc2] = true;
            wcnmd4[cc3] = true;
            wcnmd4[cc4] = true;
            wcnmd4[cc5] = true;
            wcnmd4[cc6] = true;
            wcnmd4[cc7] = true;
            wcnmd4[cc8] = true;
            wcnmd4[cc9] = true;

            wcnmd4[dd1] = true;
            wcnmd4[dd2] = true;
            wcnmd4[dd3] = true;
            wcnmd4[dd4] = true;
            wcnmd4[dd5] = true;
            wcnmd4[dd6] = true;
            wcnmd4[dd7] = true;
            wcnmd4[dd8] = true;
            wcnmd4[dd9] = true;

            wcnmd4[ee1] = true;
            wcnmd4[ee2] = true;
            wcnmd4[ee3] = true;
            wcnmd4[ee4] = true;
            wcnmd4[ee5] = true;
            wcnmd4[ee6] = true;
            wcnmd4[ee7] = true;
            wcnmd4[ee8] = true;
            wcnmd4[ee9] = true;

            wcnmd4[ab1] = true;
            wcnmd4[ab2] = true;
            wcnmd4[ab3] = true;
            wcnmd4[ab4] = true;
            wcnmd4[ab5] = true;
            wcnmd4[ab6] = true;
            wcnmd4[ab7] = true;
            wcnmd4[ab8] = true;
            wcnmd4[ab9] = true;

            wcnmd4[bc1] = true;
            wcnmd4[bc2] = true;
            wcnmd4[bc3] = true;
            wcnmd4[bc4] = true;
            wcnmd4[bc5] = true;
            wcnmd4[bc6] = true;
            wcnmd4[bc7] = true;
            wcnmd4[bc8] = true;
            wcnmd4[bc9] = true;

            wcnmd4[cd1] = true;
            wcnmd4[cd2] = true;
            wcnmd4[cd3] = true;
            wcnmd4[cd4] = true;
            wcnmd4[cd5] = true;
            wcnmd4[cd6] = true;
            wcnmd4[cd7] = true;
            wcnmd4[cd8] = true;
            wcnmd4[cd9] = true;

            wcnmd4[de1] = true;
            wcnmd4[de2] = true;
            wcnmd4[de3] = true;
            wcnmd4[de4] = true;
            wcnmd4[de5] = true;
            wcnmd4[de6] = true;
            wcnmd4[de7] = true;
            wcnmd4[de8] = true;
            wcnmd4[de9] = true;
        }

        if(i == 5) {
            wcnmd5[aa1] = true;
            wcnmd5[aa2] = true;
            wcnmd5[aa3] = true;
            wcnmd5[aa4] = true;
            wcnmd5[aa5] = true;
            wcnmd5[aa6] = true;
            wcnmd5[aa7] = true;
            wcnmd5[aa8] = true;
            wcnmd5[aa9] = true;

            wcnmd5[bb1] = true;
            wcnmd5[bb2] = true;
            wcnmd5[bb3] = true;
            wcnmd5[bb4] = true;
            wcnmd5[bb5] = true;
            wcnmd5[bb6] = true;
            wcnmd5[bb7] = true;
            wcnmd5[bb8] = true;
            wcnmd5[bb9] = true;

            wcnmd5[cc1] = true;
            wcnmd5[cc2] = true;
            wcnmd5[cc3] = true;
            wcnmd5[cc4] = true;
            wcnmd5[cc5] = true;
            wcnmd5[cc6] = true;
            wcnmd5[cc7] = true;
            wcnmd5[cc8] = true;
            wcnmd5[cc9] = true;

            wcnmd5[dd1] = true;
            wcnmd5[dd2] = true;
            wcnmd5[dd3] = true;
            wcnmd5[dd4] = true;
            wcnmd5[dd5] = true;
            wcnmd5[dd6] = true;
            wcnmd5[dd7] = true;
            wcnmd5[dd8] = true;
            wcnmd5[dd9] = true;

            wcnmd5[ee1] = true;
            wcnmd5[ee2] = true;
            wcnmd5[ee3] = true;
            wcnmd5[ee4] = true;
            wcnmd5[ee5] = true;
            wcnmd5[ee6] = true;
            wcnmd5[ee7] = true;
            wcnmd5[ee8] = true;
            wcnmd5[ee9] = true;

            wcnmd5[ab1] = true;
            wcnmd5[ab2] = true;
            wcnmd5[ab3] = true;
            wcnmd5[ab4] = true;
            wcnmd5[ab5] = true;
            wcnmd5[ab6] = true;
            wcnmd5[ab7] = true;
            wcnmd5[ab8] = true;
            wcnmd5[ab9] = true;

            wcnmd5[bc1] = true;
            wcnmd5[bc2] = true;
            wcnmd5[bc3] = true;
            wcnmd5[bc4] = true;
            wcnmd5[bc5] = true;
            wcnmd5[bc6] = true;
            wcnmd5[bc7] = true;
            wcnmd5[bc8] = true;
            wcnmd5[bc9] = true;

            wcnmd5[cd1] = true;
            wcnmd5[cd2] = true;
            wcnmd5[cd3] = true;
            wcnmd5[cd4] = true;
            wcnmd5[cd5] = true;
            wcnmd5[cd6] = true;
            wcnmd5[cd7] = true;
            wcnmd5[cd8] = true;
            wcnmd5[cd9] = true;

            wcnmd5[de1] = true;
            wcnmd5[de2] = true;
            wcnmd5[de3] = true;
            wcnmd5[de4] = true;
            wcnmd5[de5] = true;
            wcnmd5[de6] = true;
            wcnmd5[de7] = true;
            wcnmd5[de8] = true;
            wcnmd5[de9] = true;
        }

        if(i == 6) {
            wcnmd6[aa1] = true;
            wcnmd6[aa2] = true;
            wcnmd6[aa3] = true;
            wcnmd6[aa4] = true;
            wcnmd6[aa5] = true;
            wcnmd6[aa6] = true;
            wcnmd6[aa7] = true;
            wcnmd6[aa8] = true;
            wcnmd6[aa9] = true;

            wcnmd6[bb1] = true;
            wcnmd6[bb2] = true;
            wcnmd6[bb3] = true;
            wcnmd6[bb4] = true;
            wcnmd6[bb5] = true;
            wcnmd6[bb6] = true;
            wcnmd6[bb7] = true;
            wcnmd6[bb8] = true;
            wcnmd6[bb9] = true;

            wcnmd6[cc1] = true;
            wcnmd6[cc2] = true;
            wcnmd6[cc3] = true;
            wcnmd6[cc4] = true;
            wcnmd6[cc5] = true;
            wcnmd6[cc6] = true;
            wcnmd6[cc7] = true;
            wcnmd6[cc8] = true;
            wcnmd6[cc9] = true;

            wcnmd6[dd1] = true;
            wcnmd6[dd2] = true;
            wcnmd6[dd3] = true;
            wcnmd6[dd4] = true;
            wcnmd6[dd5] = true;
            wcnmd6[dd6] = true;
            wcnmd6[dd7] = true;
            wcnmd6[dd8] = true;
            wcnmd6[dd9] = true;

            wcnmd6[ee1] = true;
            wcnmd6[ee2] = true;
            wcnmd6[ee3] = true;
            wcnmd6[ee4] = true;
            wcnmd6[ee5] = true;
            wcnmd6[ee6] = true;
            wcnmd6[ee7] = true;
            wcnmd6[ee8] = true;
            wcnmd6[ee9] = true;

            wcnmd6[ab1] = true;
            wcnmd6[ab2] = true;
            wcnmd6[ab3] = true;
            wcnmd6[ab4] = true;
            wcnmd6[ab5] = true;
            wcnmd6[ab6] = true;
            wcnmd6[ab7] = true;
            wcnmd6[ab8] = true;
            wcnmd6[ab9] = true;

            wcnmd6[bc1] = true;
            wcnmd6[bc2] = true;
            wcnmd6[bc3] = true;
            wcnmd6[bc4] = true;
            wcnmd6[bc5] = true;
            wcnmd6[bc6] = true;
            wcnmd6[bc7] = true;
            wcnmd6[bc8] = true;
            wcnmd6[bc9] = true;

            wcnmd6[cd1] = true;
            wcnmd6[cd2] = true;
            wcnmd6[cd3] = true;
            wcnmd6[cd4] = true;
            wcnmd6[cd5] = true;
            wcnmd6[cd6] = true;
            wcnmd6[cd7] = true;
            wcnmd6[cd8] = true;
            wcnmd6[cd9] = true;

            wcnmd6[de1] = true;
            wcnmd6[de2] = true;
            wcnmd6[de3] = true;
            wcnmd6[de4] = true;
            wcnmd6[de5] = true;
            wcnmd6[de6] = true;
            wcnmd6[de7] = true;
            wcnmd6[de8] = true;
            wcnmd6[de9] = true;
        }

        if(i == 7) {
            wcnmd7[aa1] = true;
            wcnmd7[aa2] = true;
            wcnmd7[aa3] = true;
            wcnmd7[aa4] = true;
            wcnmd7[aa5] = true;
            wcnmd7[aa6] = true;
            wcnmd7[aa7] = true;
            wcnmd7[aa8] = true;
            wcnmd7[aa9] = true;

            wcnmd7[bb1] = true;
            wcnmd7[bb2] = true;
            wcnmd7[bb3] = true;
            wcnmd7[bb4] = true;
            wcnmd7[bb5] = true;
            wcnmd7[bb6] = true;
            wcnmd7[bb7] = true;
            wcnmd7[bb8] = true;
            wcnmd7[bb9] = true;

            wcnmd7[cc1] = true;
            wcnmd7[cc2] = true;
            wcnmd7[cc3] = true;
            wcnmd7[cc4] = true;
            wcnmd7[cc5] = true;
            wcnmd7[cc6] = true;
            wcnmd7[cc7] = true;
            wcnmd7[cc8] = true;
            wcnmd7[cc9] = true;

            wcnmd7[dd1] = true;
            wcnmd7[dd2] = true;
            wcnmd7[dd3] = true;
            wcnmd7[dd4] = true;
            wcnmd7[dd5] = true;
            wcnmd7[dd6] = true;
            wcnmd7[dd7] = true;
            wcnmd7[dd8] = true;
            wcnmd7[dd9] = true;

            wcnmd7[ee1] = true;
            wcnmd7[ee2] = true;
            wcnmd7[ee3] = true;
            wcnmd7[ee4] = true;
            wcnmd7[ee5] = true;
            wcnmd7[ee6] = true;
            wcnmd7[ee7] = true;
            wcnmd7[ee8] = true;
            wcnmd7[ee9] = true;

            wcnmd7[ab1] = true;
            wcnmd7[ab2] = true;
            wcnmd7[ab3] = true;
            wcnmd7[ab4] = true;
            wcnmd7[ab5] = true;
            wcnmd7[ab6] = true;
            wcnmd7[ab7] = true;
            wcnmd7[ab8] = true;
            wcnmd7[ab9] = true;

            wcnmd7[bc1] = true;
            wcnmd7[bc2] = true;
            wcnmd7[bc3] = true;
            wcnmd7[bc4] = true;
            wcnmd7[bc5] = true;
            wcnmd7[bc6] = true;
            wcnmd7[bc7] = true;
            wcnmd7[bc8] = true;
            wcnmd7[bc9] = true;

            wcnmd7[cd1] = true;
            wcnmd7[cd2] = true;
            wcnmd7[cd3] = true;
            wcnmd7[cd4] = true;
            wcnmd7[cd5] = true;
            wcnmd7[cd6] = true;
            wcnmd7[cd7] = true;
            wcnmd7[cd8] = true;
            wcnmd7[cd9] = true;

            wcnmd7[de1] = true;
            wcnmd7[de2] = true;
            wcnmd7[de3] = true;
            wcnmd7[de4] = true;
            wcnmd7[de5] = true;
            wcnmd7[de6] = true;
            wcnmd7[de7] = true;
            wcnmd7[de8] = true;
            wcnmd7[de9] = true;
        }

        if(i == 8) {
            wcnmd8[aa1] = true;
            wcnmd8[aa2] = true;
            wcnmd8[aa3] = true;
            wcnmd8[aa4] = true;
            wcnmd8[aa5] = true;
            wcnmd8[aa6] = true;
            wcnmd8[aa7] = true;
            wcnmd8[aa8] = true;
            wcnmd8[aa9] = true;

            wcnmd8[bb1] = true;
            wcnmd8[bb2] = true;
            wcnmd8[bb3] = true;
            wcnmd8[bb4] = true;
            wcnmd8[bb5] = true;
            wcnmd8[bb6] = true;
            wcnmd8[bb7] = true;
            wcnmd8[bb8] = true;
            wcnmd8[bb9] = true;

            wcnmd8[cc1] = true;
            wcnmd8[cc2] = true;
            wcnmd8[cc3] = true;
            wcnmd8[cc4] = true;
            wcnmd8[cc5] = true;
            wcnmd8[cc6] = true;
            wcnmd8[cc7] = true;
            wcnmd8[cc8] = true;
            wcnmd8[cc9] = true;

            wcnmd8[dd1] = true;
            wcnmd8[dd2] = true;
            wcnmd8[dd3] = true;
            wcnmd8[dd4] = true;
            wcnmd8[dd5] = true;
            wcnmd8[dd6] = true;
            wcnmd8[dd7] = true;
            wcnmd8[dd8] = true;
            wcnmd8[dd9] = true;

            wcnmd8[ee1] = true;
            wcnmd8[ee2] = true;
            wcnmd8[ee3] = true;
            wcnmd8[ee4] = true;
            wcnmd8[ee5] = true;
            wcnmd8[ee6] = true;
            wcnmd8[ee7] = true;
            wcnmd8[ee8] = true;
            wcnmd8[ee9] = true;

            wcnmd8[ab1] = true;
            wcnmd8[ab2] = true;
            wcnmd8[ab3] = true;
            wcnmd8[ab4] = true;
            wcnmd8[ab5] = true;
            wcnmd8[ab6] = true;
            wcnmd8[ab7] = true;
            wcnmd8[ab8] = true;
            wcnmd8[ab9] = true;

            wcnmd8[bc1] = true;
            wcnmd8[bc2] = true;
            wcnmd8[bc3] = true;
            wcnmd8[bc4] = true;
            wcnmd8[bc5] = true;
            wcnmd8[bc6] = true;
            wcnmd8[bc7] = true;
            wcnmd8[bc8] = true;
            wcnmd8[bc9] = true;

            wcnmd8[cd1] = true;
            wcnmd8[cd2] = true;
            wcnmd8[cd3] = true;
            wcnmd8[cd4] = true;
            wcnmd8[cd5] = true;
            wcnmd8[cd6] = true;
            wcnmd8[cd7] = true;
            wcnmd8[cd8] = true;
            wcnmd8[cd9] = true;

            wcnmd8[de1] = true;
            wcnmd8[de2] = true;
            wcnmd8[de3] = true;
            wcnmd8[de4] = true;
            wcnmd8[de5] = true;
            wcnmd8[de6] = true;
            wcnmd8[de7] = true;
            wcnmd8[de8] = true;
            wcnmd8[de9] = true;
        }
    }
    for(int i = 0; i <= 99999; i++) {
        if(n == 1) {
            if(wcnmd1[i] == true) {
                cnt++;
                //cout << i << endl;
            }
        }
        if(n == 2) {
            if(wcnmd1[i] == true && wcnmd2[i] == true) {
                cnt++;
                //cout << i << endl;
            }
        }

        if(n == 3) {
            if(wcnmd1[i] == true && wcnmd2[i] == true && wcnmd3[i] == true) {
                cnt++;
            }
        }
        if(n == 4) {
            if(wcnmd1[i] == true && wcnmd2[i] == true && wcnmd3[i] == true && wcnmd4[i] == true) {
                cnt++;
            }
        }
        if(n == 5) {
            if(wcnmd1[i] == true && wcnmd2[i] == true && wcnmd3[i] == true && wcnmd4[i] == true && wcnmd5[i] == true) {
                cnt++;
            }
        }
        if(n == 6) {
            if(wcnmd1[i] == true && wcnmd2[i] == true && wcnmd3[i] == true && wcnmd4[i] == true && wcnmd5[i] == true && wcnmd6[i] == true) {
                cnt++;
            }
        }
        if(n == 7) {
            if(wcnmd1[i] == true && wcnmd2[i] == true && wcnmd3[i] == true && wcnmd4[i] == true && wcnmd5[i] == true && wcnmd6[i] == true && wcnmd7[i] == true) {
                cnt++;
            }
        }
        if(n == 8) {
            if(wcnmd1[i] == true && wcnmd2[i] == true && wcnmd3[i] == true && wcnmd4[i] == true && wcnmd5[i] == true && wcnmd6[i] == true && wcnmd7[i] == true && wcnmd8[i] == true) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}

