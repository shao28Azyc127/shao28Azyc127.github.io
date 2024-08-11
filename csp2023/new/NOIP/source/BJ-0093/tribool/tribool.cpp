#include <bits/stdc++.h>

#define getchar getchar_unlocked

using namespace std;

template<typename T = int>
inline T read() {
    int x = 0, f = 1;
    char ch = 0;
    while(!isdigit(ch = getchar())) {
        if (ch == '-') f = -1;
    }
    do x = x * 10 + ch - '0';
    while (isdigit(ch = getchar()));
    return x * f;
}

struct Object{
    bool is;
    char typ;
    int target;
    Object() {}
    Object(bool is, char typ, int target = -1)
        : is(is), typ(typ), target(target) {}
};

const int N = 100005;
int C, T, n, m, pow3[N], cur[N];
Object obj[N];
multiset<int> lk[N];

char calc_num(char opt, char BOOL) {
    if (BOOL == 'U') return 'U';
    if (opt == '+') return BOOL;
    if (BOOL == 'T') return 'F';
    return 'T';
}

char calc_conn(char opt, char CONN) {
    if (CONN == '?') return opt;
    if (opt == '+') return CONN;
    if (CONN == '+') return '-';
    return '+';
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    C = read(), T = read();
    while(T--) {
        if (C == 5 || C == 6) {
            n = read(), m = read();
            for (int i = 1; i <= n; i++) {
                obj[i] = Object(false, '?', i);
                lk[i].clear();
                lk[i].insert(i);
            }
            for (int i = 1; i <= m; i++) {
                char v = getchar();
                int a = read();
                if (obj[a].target != -1) lk[obj[a].target].erase(lk[obj[a].target].find(a));
                if (v == 'T' || v == 'F' || v == 'U') obj[a] = Object(true, v);
                else {
                    int b = read();
                    if (obj[b].is) obj[a] = Object(true, calc_num(v, obj[b].typ));
                    else {
                        obj[a] = Object(false, calc_conn(v, obj[b].typ), obj[b].target);
                        lk[obj[a].target].insert(a);
                    }
                }
                // cout << "Step: " << i << endl;
                // for (int i = 1; i <= n; i++) obj[i].debug(to_string(i));
            }
            // int cnt = 0;
            // for (int i = 1; i <= n; i++) if (obj[i].target == i) cnt++;
            // cout << cnt << endl;
            for (int i = 1; i <= n; i++) 
                if (!obj[i].is && obj[i].target == i && obj[i].typ == '-')
                    obj[i] = Object(true, 'U');
            queue<int> q;
            for (int i = 1; i <= n; i++)
                if (!obj[i].is && obj[obj[i].target].is) {
                    obj[i] = Object(true, 'U');
                    q.push(i);
                }
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for (const int& o : lk[u]) {
                    if (obj[o].is) continue;
                    q.push(o);
                    obj[o] = Object(true, 'U');
                }
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++)
                if (obj[i].typ == 'U') cnt++;
            // for (int i = 1; i <= n; i++) obj[i].debug(to_string(i));
            cout << cnt << endl;
        }
        else {
            int ans12 = INT_MAX;
            n = read(), m = read();
            pow3[0] = 1;
            for (int i = 1; i <= n; i++) pow3[i] = 3 * pow3[i - 1];
            for (int i = 1; i <= n; i++)
                obj[i] = Object(false, '?', i);
            for (int i = 1; i <= m; i++) {
                char v = getchar();
                int a = read();
                // cout << v << " " << a << endl;
                if (v == 'T' || v == 'F' || v == 'U') obj[a] = Object(true, v);
                else {
                    int b = read();
                    // cout << a << " " << b << endl;
                    if (obj[b].is) obj[a] = Object(true, calc_num(v, obj[b].typ));
                    else obj[a] = Object(false, calc_conn(v, obj[b].typ), obj[b].target);
                }
            }
            if (C == 3 || C == 4) {
                int cnt = 0;
                for (int i = 1; i <= n; i++)
                    if (obj[i].typ == 'U') cnt++;
                cout << cnt << endl;
                continue;
            }
            // for (int i = 1; i <= n; i++) obj[i].debug(to_string(i));
            for (int i = 1; i <= n; i++) cur[i] = 0;
            const char to[] = {'F', 'T', 'U'};
            for (int i = 0; i < pow3[n]; i++) {
                cur[1]++;
                for (int j = 1; cur[j] == 3; j++)
                    if (cur[j] == 3) cur[j] = 0, cur[j + 1]++;
                // for (int j = 1; j <= n; j++) cout << to[cur[j]] << " ";
                // cout << endl;
                bool fg = true;
                for (int j = 1; j <= n && fg; j++) {
                    // obj[j].debug("obj j");
                    if (obj[j].is && to[cur[j]] != obj[j].typ) fg = false;
                    else if (!obj[j].is && obj[j].typ != '?' && to[cur[j]] != calc_num(obj[j].typ, to[cur[obj[j].target]])) fg = false;
                }
                if (fg) {
                    int cnt = 0;
                    for (int j = 1; j <= n; j++)
                        if (cur[j] == 2) cnt++;
                    // cout << "cnt:" << cnt << endl;
                    ans12 = min(ans12, cnt);
                    // if (cnt == 0) exit(-1);
                }
            }
            cout << ans12 << endl;
        }
        // for (int i = 1; i <= n; i++) obj[i].debug(to_string(i));
    }
    fflush(stdout);
    return 0;
}
/*
- 7 6
+ 4 1
+ 6 4
T 1
+ 2 9
- 9 10
U 10
+ 5 5
U 8
T 3
*/