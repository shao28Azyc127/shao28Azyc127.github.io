

#include <iostream>
#include <cstring>

const int MAXN = 1e5+9;
using namespace std;

int T, N, Q, C, def[MAXN], res[MAXN<<1], ans;
int fa[MAXN<<1];

//2N+1 -> T, 2N+2 -> F, 2N+3 -> U
inline int re (int x) {
    if (x <= 2*N) return x > N ? x-N : x+N;
    if (x == 2*N+3) return x;
    return x == 2*N+1 ? 2*N+2 : 2*N+1;
}

int find (int x) {return x == fa[x] ? x : fa[x]=find(fa[x]);}

int main () {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    cin >> C >> T;
    while (T--) {
        memset(res, 0, sizeof(res));
        cin >> N >> Q;
        for (int i = 1; i < N+1; i++) def[i] = i;
        for (int i = 1; i < 2*N+4; i++) fa[i] = i;
        char op;
        int a, b;
        while (Q--) {
            cin >> op;
            if (op == '-') {
                cin >> a >> b;
                def[a] = re(def[b]);
            }
            else if (op == '+') {
                cin >> a >> b;
                def[a] = def[b];
            }
            else {
                cin >> a;
                if (op == 'T') def[a] = 2*N+1;
                else if (op == 'F') def[a] = 2*N+2;
                else def[a] = 2*N+3;
            }
        }

        for (int i = 1; i < N+1; i++) fa[find(i)] = find(def[i]), fa[find(re(i))] = find(re(def[i]));
        res[find(2*N+3)] = 2*N+3;
        for (int i = 1; i < N+1; i++) if (find(i) == find(i+N)) res[find(i)] = 2*N+3;

        ans = 0;
        for (int i = 1; i < N+1; i++) if (res[find(i)] == 2*N+3) ans++;
        cout << ans << '\n';
    }

    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}