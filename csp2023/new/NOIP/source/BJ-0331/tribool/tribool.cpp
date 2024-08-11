#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct Query {
    char type;
    int from, to;

    Query(char p = 'O', int f = 0, int t = 0) {
        type = p;
        from = f;
        to = t;
    }
} Q[100001];

int c, t;
int n, m;
int tag[100001];

int dfs(int x, int d = 0) {
    if(tag[x] < 1) return tag[x];
    int temp = tag[x];
    tag[x] = 0;
    tag[x] = dfs(temp, d + 1);
    return tag[x];
}

int d[12];
int td[11];

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while(t--) {
        memset(Q, 0, sizeof(Q));
        memset(tag, 0, sizeof(tag));
        scanf("%d%d", &n, &m);
        for(int i = 1, p, t, f = 0;i <= m;i++) {
            do p = getchar();
            while(p != 'U' && p != 'T' && p != 'F' && p != '+' && p != '-');
            scanf("%d", &t);
            if(p == '+' || p == '-') scanf("%d", &f);
            else f = 0;
            Q[i] = Query(p, f, t);
        }
        if(c <= 2) {
            int ans = n;
            memset(d, 0, sizeof(d));
            d[1] = -1;
            while(d[n + 1] == 0) {
                d[1]++;
                for(int i = 1;i <= n;i++) {
                    if(d[i] > 2) {
                        d[i] = 0;
                        d[i + 1]++;
                    }
                    td[i] = d[i];
                }
                for(int i = 1;i <= m;i++) {
                    if(Q[i].type == 'T') td[Q[i].to] = 2;
                    if(Q[i].type == 'F') td[Q[i].to] = 0;
                    if(Q[i].type == 'U') td[Q[i].to] = 1;
                    if(Q[i].type == '+') td[Q[i].to] = td[Q[i].from];
                    if(Q[i].type == '-') td[Q[i].to] = 2 - td[Q[i].from];
                }
                bool flag = true;
                int s = 0;
                for(int i = 1;i <= n;i++) {
                    if(td[i] != d[i]) {
                        flag = false;
                        break;
                    }
                    s += (d[i] & 1);
                }
                if(flag) ans = min(ans, s);
            }
            printf("%d\n", ans);
        }
        if(c == 3 || c == 4) {
            for(int i = 1;i <= m;i++) tag[Q[i].to] = Q[i].type;
            int ans = 0;
            for(int i = 1;i <= n;i++) {
                if(tag[i] == 'U') {
                    ans++;
                }
            }
            printf("%d\n", ans);
        }
        if(c == 5) {
            for(int i = 1;i <= m;i++) {
                if(Q[i].type == 'U') tag[Q[i].to] = -1;
                else tag[Q[i].to] = tag[Q[i].from];//dfs(Q[i].from);
            }
            for(int i = 1;i <= n;i++) {
                if(tag[i] > 0) {
                    dfs(i);
                }
            }
            int ans = 0;
            for(int i = 1;i <= n;i++) ans -= tag[i];
            printf("%d\n", ans);
        }
    }
    return 0;
}
