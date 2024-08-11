#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int N = 2000010;
int n;
string s;
struct node {
    int l, r;
    int able;
    long long sum;
} tree[N * 4];
void update(int p) {
    int l = tree[p].l, r = tree[p].r;
    int mid = l + r >> 1;
    if (l == r) return;
    l = mid; r = mid + 1;
    while (s[l] == s[r] && l >= tree[p].l && r <= tree[p].r) {
        tree[p].sum++;
        l--; r++;
    }
    if (l == tree[p].l - 1 && r == tree[p].r + 1) {
        tree[p].able = 1;
        return;
    }
    tree[p].sum += tree[p << 1].sum + tree[p << 1 | 1].sum;
    if (tree[p << 1].able && tree[p << 1 | 1].able) tree[p].sum++;
    return;
}
void build(int l, int r, int p = 1) {
    tree[p].l = l;
    tree[p].r = r;
    if (l == r) {
        tree[p].sum = 0;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    update(p);
    return;
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> s;
    s = ' ' + s;
    build(1, n);
    //printf("%d %d\n", tree[3].l, tree[3].r);
    cout << tree[1].sum << endl;
    return 0;
}
