

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int M;
int rt;
int tr[9000009][27];
int idx;
char s[3009][3009];
bool hv[9000009][27];

bool Cmp (char a, char b) {
    return a > b;
}

void Add (char s[]) {
    int t = rt;
    for (int i = 1; i <= M; i++) {
        if (!tr[t][s[i] - 'a']) {
            tr[t][s[i] - 'a'] = ++idx;
            for (int j = s[i] - 'a'; j < 27; j++)
                if (!hv[t][j]) hv[t][j] = true;
                else break;
        }
        t = tr[t][s[i] - 'a'];
    }
}

bool Query (char s[]) {
    int t = rt;
    for (int i = M; i >= 1; i--) {
        if (s[i] != 'a' && hv[t][s[i] - 'a' - 1]) return false;
        else if (!tr[t][s[i] - 'a']) return true;
        t = tr[t][s[i] - 'a'];
    }
    return true;
}

int main () {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &N, &M), rt = ++idx;
    for (int i = 1; i <= N; i++) {
        scanf("%s", s[i] + 1);
        sort(s[i] + 1, s[i] + M + 1, Cmp);
        Add(s[i]);
    }
    for (int i = 1; i <= N; i++)
        if (Query(s[i])) putchar('1');
        else putchar('0');
    puts("");
    fclose(stdin), fclose(stdout);
    return 0;
}