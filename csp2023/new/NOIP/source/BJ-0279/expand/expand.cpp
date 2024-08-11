

#include <set>
#include <cstdio>

using namespace std;

int C;
int N;
int M;
int Q;
int X[500009];
int Y[500009];
set<int> sX;
set<int> sY;

int Max (set<int> &a) {
    return *(prev(a.end()));
}

int Min (set<int> &a) {
    return *(a.begin());
}

int main () {
    int kx;
    int ky;
    int p;
    int v;

    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &C, &N, &M, &Q);
    for (int i = 1; i <= N; i++) scanf("%d", &X[i]), sX.insert(X[i]);
    for (int i = 1; i <= M; i++) scanf("%d", &Y[i]), sY.insert(Y[i]);
    if (X[1] < Y[1] && X[N] < Y[M] && Min(sX) < Min(sY) && Max(sX) < Max(sY)) putchar('1');
    else if (X[1] > Y[1] && X[N] > Y[M] && Min(sX) > Min(sY) && Max(sX) > Max(sY)) putchar('1');
    else putchar('0');
    while (Q--) {
        scanf("%d%d", &kx, &ky);
        while (kx--) {
            scanf("%d%d", &p, &v);
            sX.erase(X[p]), sX.insert(v), X[p] = v;
        }
        while (ky--) {
            scanf("%d%d", &p, &v);
            sY.erase(Y[p]), sY.insert(v), Y[p] = v;
        }
        if (X[1] < Y[1] && X[N] < Y[M] && Min(sX) < Min(sY) && Max(sX) < Max(sY)) putchar('1');
        else if (X[1] > Y[1] && X[N] > Y[M] && Min(sX) > Min(sY) && Max(sX) > Max(sY)) putchar('1');
        else putchar('0');
    }
    fclose(stdin), fclose(stdout);
    return 0;
}