#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c, n, m, q, x[N], y[N], bakx[N], baky[N];
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for(int i = 1; i <= n; i++) scanf("%d", &x[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &y[i]);
    if(c == 1) {
        if(x[1] != y[1]) printf("1");
        else printf("0");
        while(q--) {
            for(int i = 1; i <= n; i++) bakx[i] = x[i];
            for(int i = 1; i <= m; i++) baky[i] = y[i];
            int kx, ky; scanf("%d%d", &kx, &ky);
            while(kx--) { int px, vx; scanf("%d%d", &px, &vx); x[px] = vx; }
            while(ky--) { int py, vy; scanf("%d%d", &py, &vy); y[py] = vy; }
            if(x[1] != y[1]) printf("1");
            else printf("0");
            for(int i = 1; i <= n; i++) x[i] = bakx[i];
            for(int i = 1; i <= m; i++) y[i] = baky[i];
        }
    }
    else if(c == 2) {
        if(n == 2 && m == 2) {
            if(x[1] == y[1] || x[2] == y[2]) printf("0");
            else {
                if((x[1] - y[1]) * (x[2] - y[2]) > 0) printf("1");
                else printf("0");
            }
            while(q--) {
                for(int i = 1; i <= n; i++) bakx[i] = x[i];
                for(int i = 1; i <= m; i++) baky[i] = y[i];
                int kx, ky; scanf("%d%d", &kx, &ky);
                while(kx--) { int px, vx; scanf("%d%d", &px, &vx); x[px] = vx; }
                while(ky--) { int py, vy; scanf("%d%d", &py, &vy); y[py] = vy; }
                if(x[1] == y[1] || x[2] == y[2]) printf("0");
                else {
                    if((x[1] - y[1]) * (x[2] - y[2]) > 0) printf("1");
                    else printf("0");
                }
                for(int i = 1; i <= n; i++) x[i] = bakx[i];
                for(int i = 1; i <= m; i++) y[i] = baky[i];
            }
        }
        else if(n == 1 && m == 1) {
            if(x[1] != y[1]) printf("1");
            else printf("0");
            while(q--) {
                for(int i = 1; i <= n; i++) bakx[i] = x[i];
                for(int i = 1; i <= m; i++) baky[i] = y[i];
                int kx, ky; scanf("%d%d", &kx, &ky);
                while(kx--) { int px, vx; scanf("%d%d", &px, &vx); x[px] = vx; }
                while(ky--) { int py, vy; scanf("%d%d", &py, &vy); y[py] = vy; }
                if(x[1] != y[1]) printf("1");
                else printf("0");
                for(int i = 1; i <= n; i++) x[i] = bakx[i];
                for(int i = 1; i <= m; i++) y[i] = baky[i];
            }
        }
        else if(n == 1) {
            if((y[1] < x[1] && y[2] < x[1]) || (y[1] > x[1] && y[2] > x[1])) printf("1");
            else printf("0");
            while(q--) {
                for(int i = 1; i <= n; i++) bakx[i] = x[i];
                for(int i = 1; i <= m; i++) baky[i] = y[i];
                int kx, ky; scanf("%d%d", &kx, &ky);
                while(kx--) { int px, vx; scanf("%d%d", &px, &vx); x[px] = vx; }
                while(ky--) { int py, vy; scanf("%d%d", &py, &vy); y[py] = vy; }
                if((y[1] < x[1] && y[2] < x[1]) || (y[1] > x[1] && y[2] > x[1])) printf("1");
                else printf("0");
                for(int i = 1; i <= n; i++) x[i] = bakx[i];
                for(int i = 1; i <= m; i++) y[i] = baky[i];
            }
        }
        else if(m == 1) {
            if((x[1] < y[1] && x[2] < y[1]) || (x[1] > y[1] && x[2] > y[1])) printf("1");
            else printf("0");
            while(q--) {
                for(int i = 1; i <= n; i++) bakx[i] = x[i];
                for(int i = 1; i <= m; i++) baky[i] = y[i];
                int kx, ky; scanf("%d%d", &kx, &ky);
                while(kx--) { int px, vx; scanf("%d%d", &px, &vx); x[px] = vx; }
                while(ky--) { int py, vy; scanf("%d%d", &py, &vy); y[py] = vy; }
                if((x[1] < y[1] && x[2] < y[1]) || (x[1] > y[1] && x[2] > y[1])) printf("1");
                else printf("0");
                for(int i = 1; i <= n; i++) x[i] = bakx[i];
                for(int i = 1; i <= m; i++) y[i] = baky[i];
            }
        }
    }
    return 0;
}