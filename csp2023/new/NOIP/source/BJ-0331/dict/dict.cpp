#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n, m;

struct Str {
    int s[26];
    int st;
    int pos;

    Str() {
        memset(s, 0, sizeof(s));
        st = pos = 0;
    }

    Str(string str, int p = 0) {
        memset(s, 0, sizeof(s));
        for(int i = 0;i < m;i++) s['z' - str[i]]++;
        for(int i = 0;i < 26;i++) {
            if(s[i] > 0) {
                st = i;
                break;
            }
        }
        pos = p;
    }

    inline int operator [](int x) {
        return s[x];
    }

    friend bool operator < (Str A, Str B) {
        if(A.st != B.st || m == 1) return (A.st > B.st);
        for(int i = 0;i < 26;i++) {
            if(A[i] != B[i]) {
                return (A[i] > B[i]);
            }
        }
        return false;
    }

    friend bool operator == (Str A, Str B) {
        if(A.st != B.st) return false;
        if(m == 1) return (A.st == B.st);
        for(int i = 0;i < 26;i++) {
            if(A[i] != B[i]) {
                return false;
            }
        }
        return true;
    }

    void print() {
        printf("%d %d\n", st, pos);
        for(int i = 0;i < 26;i++) printf("%d ", s[i]);
        putchar('\n');
    }
} St[3001];

struct RevStr : Str {
    RevStr() {}

    RevStr(Str str) {
        pos = str.pos;
        for(int i = 0;i < 26;i++) {
            s[i] = str.s[i];
            if(s[i] > 0) st = i;
        }
    }

    friend bool operator < (RevStr A, Str B) {
        if(A.st != B.st) return (A.st > B.st);
        return false;
    }
};

int ans[3001];

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    if(n == 1) {
        printf("1\n");
        return 0;
    }
    string s;
    for(int i = 1;i <= n;i++) {
        cin >> s;
        St[i] = Str(s, i);
//        St[i].print();
    }
    sort(St + 1, St + n + 1);
    RevStr rs;
    bool flag;
    for(int i = 1;i <= n;i++) {
        rs = RevStr(St[i]);
//        rs.print();
        flag = true;
        for(int j = 1;j <= n;j++) {
            if(i == j) continue;
            if(!(rs < St[j])) {
                flag = false;
                break;
            }
        }
        ans[rs.pos] = flag ? 1 : 0;
    }
    for(int i = 1;i <= n;i++) printf("%d", ans[i]);
    return 0;
}
