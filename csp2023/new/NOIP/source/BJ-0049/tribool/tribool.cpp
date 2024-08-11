#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#ifdef int
#define inf 0x3f3f3f3f3f3f3f3fll
#else
#define inf 0x3f3f3f3f
#endif

#define maxn 100055
#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);

using namespace std;

int cid, n, m, a[maxn], x, y, en, h[maxn], c[maxn], cnt;
char op;

struct edge {
    int u, v, w, next;
} e[maxn * 2];
void add(int u, int v, int w) {
    //cout << u << '-' << v << '~' << w << endl;
    e[en] = (edge){u, v, w, h[u]}; h[u] = en++;
}

bool col(int r, int x) {
    if(c[r] > -inf) {
        return c[r] == x;
    }
    c[r] = x;
    if(r > 0 && r <= n) cnt++;
    bool abl = true;
    for(int j = h[r]; ~j; j = e[j].next) {
        int v = e[j].v;
        if(!col(v, e[j].w ? -x : x)) abl = false;
    }
    return abl;
}

void work() {
    en = 0;
    int sum = 0;
    cin >> n >> m;
    h[0] = -1, a[0] = 0;
    for(int i = 1; i <= n; i++) a[i] = i, h[i] = -1;
    for(int i = 0; i <= n + 1; i++) c[i] = -inf;
    a[n + 1] = n + 1; h[n + 1] = -1;
    for(int i = 1; i <= m; i++) {
        cin >> op;
        switch(op) {
            case 'T': {
                cin >> x; a[x] = n + 1;
                break;
            }
            case 'F': {
                cin >> x; a[x] = -n - 1;
                break;
            }
            case 'U': {
                cin >> x; a[x] = 0;
                break;
            }
            case '+': {
                cin >> x >> y; a[x] = a[y];
                break;
            }
            case '-': {
                cin >> x >> y; a[x] = -a[y];
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        //cout << a[i] << ' ';
        add(i, abs(a[i]), a[i] < 0);
        add(abs(a[i]), i, a[i] < 0);
    }
    col(0, 0);
    cnt = 0;
    col(n + 1, 1);
    sum += cnt;
    for(int i = 1; i <= n; i++) {
        if(c[i] == -inf) {
            cnt = 0;
            if(col(i, 1)) sum += cnt;
        }
    }
    cout << n - sum << '\n';
}

int main() {
    fopen("tribool")
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> cid; int _; cin >> _; while(_--) work();
}