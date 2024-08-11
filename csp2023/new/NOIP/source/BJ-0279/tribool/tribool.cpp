

#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Opt {
    int op;
    int a;
    int b;
} Q[100009];

int C;
int T;
int N;
int M;
int fa[400009];
int idx;
int inv[100009];
int tg[400009];
int res;
int q[100009];
int hh;
int tt;
int is_inv[400009];
vector<int> blk[400009];
bool vis[400009];

int Get_Fa (int x) {
    if (x == fa[x]) return x;
    return fa[x] = Get_Fa(fa[x]);
}

bool Vis (int x) {
    return tg[Get_Fa(x)] == -1;
}

void Get_Tg () {
    int t;

    while (hh <= tt) {
        t = q[hh++];
        if (is_inv[t]) {
            if (!vis[is_inv[t]]) {
                q[++tt] = is_inv[t], vis[is_inv[t]] = true, tg[Get_Fa(is_inv[t])] = -1;
                q[++tt] = is_inv[t] + N + M, vis[is_inv[t] + N + M] = true, tg[Get_Fa(is_inv[t] + N + M)] = -1;
            }
        }
        else if (t >= 3 && t <= N + 2)
            for (int v : blk[Get_Fa(t)])
                if (!vis[v]) {
                    q[++tt] = v, tg[v] = -1;
                    vis[v] = true;
                }
    }
}

int main () {
    char op[9];
    int u;
    int v;

    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &C, &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i <= 2 * (N + M) + 2; i++) fa[i] = i, tg[i] = is_inv[i] = 0, blk[i].clear();
        for (int i = 1; i <= M; i++) {
            scanf("%s", op);
            if (op[0] == '+') scanf("%d%d", &u, &v), Q[i] = {1, u, v};
            else if (op[0] == '-') scanf("%d%d", &u, &v), Q[i] = {0, u, v};
            else if (op[0] == 'T') scanf("%d", &u), Q[i] = {-1, u};
            else if (op[0] == 'F') scanf("%d", &u), Q[i] = {-2, u};
            else scanf("%d", &u), Q[i] = {-3, u};
        }
        idx = N + 2;
        for (int i = 1; i <= N; i++) inv[i] = i + 2;
        for (int i = 1; i <= M; i++) {
            inv[Q[i].a] = ++idx;
            if (Q[i].op == -1) fa[idx] = 0, fa[idx + N + M] = 1;
            else if (Q[i].op == -2) fa[idx] = 1, fa[idx + N + M] = 0;
            else if (Q[i].op == -3) fa[idx] = fa[idx + N + M] = 2;
            else if (Q[i].op == 0) fa[idx] = Get_Fa(inv[Q[i].b] + N + M), fa[idx + N + M] = Get_Fa(inv[Q[i].b]);
            else fa[idx] = Get_Fa(inv[Q[i].b]), fa[idx + N + M] = Get_Fa(inv[Q[i].b] + N + M);
        }
        for (int i = 3; i <= idx; i++) {
            if (Get_Fa(i) == Get_Fa(i + N + M)) tg[Get_Fa(i)] = -1;
            blk[Get_Fa(i)].push_back(i);
        }
        for (int i = 1; i <= N; i++) {
            if (Get_Fa(inv[i] + N + M) == Get_Fa(i + 2)) tg[Get_Fa(inv[i])] = tg[Get_Fa(inv[i] + N + M)] = -1;
            if (Get_Fa(inv[i]) == 2) tg[Get_Fa(i + 2)] = tg[Get_Fa(i + 2 + N + M)] = -1;
            is_inv[inv[i]] = i + 2;
        }
        hh = 0, tt = -1;
        for (int i = 3; i <= idx; i++)
            if (tg[Get_Fa(i)] == -1) q[++tt] = i, vis[i] = true;
        Get_Tg();
        res = 0;
        for (int i = 1; i <= N; i++)
            if (tg[Get_Fa(inv[i])] == -1) res++;
        printf("%d\n", res);
    }
    fclose(stdin), fclose(stdout);
    return 0;
}