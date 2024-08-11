

#include <set>
#include <vector>
#include <cstdio>
#define PII pair<int, int>
#define ll long long

using namespace std;

int N;
char A[2000009];
set<int> visL[200009];
set<int> visR[200009];
set<PII> t[2];
ll res;

int main () {
    int c = 0;

    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%s", &N, A + 1);
    for (int i = 2; i <= N; i++)
        if (A[i] == A[i - 1]) visL[i - 1].insert(i), visR[i].insert(i - 1), t[0].insert({i - 1, i});
    while (t[c & 1].size()) {
        res += t[c & 1].size();
        t[(c + 1) & 1].clear();
        for (auto x : t[c & 1]) {
            if (x.first - 1 >= 1 && x.second + 1 <= N && A[x.first - 1] == A[x.second + 1] && !visL[x.first - 1].count(x.second + 1)) visL[x.first - 1].insert(x.second + 1), visR[x.second + 1].insert(x.first - 1), t[(c + 1) & 1].insert({x.first - 1, x.second + 1});
            for (auto y : visR[x.first - 1])
                if (!visL[y].count(x.second))
                    visL[y].insert(x.second), visR[x.second].insert(y), t[(c + 1) & 1].insert({y, x.second});
            for (auto y : visL[x.second + 1])
                if (!visL[x.first].count(y))
                    visL[x.first].insert(y), visR[y].insert(x.first), t[(c + 1) & 1].insert({x.first, y});
        }
        c++;
    }
    printf("%lld\n", res);
    fclose(stdin), fclose(stdout);
    return 0;
}
