#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3000 + 5;
int n, m;
struct Node{
    int l, ch[30], cnt[30];
}a[MAXN];
int tot[26];
bool cmp(int xx, int yy){
    Node x = a[xx], y = a[yy];
    int posx = 1, posy = y.l;
    while (posx <= x.l && posy >= 1){
        if (x.ch[posx] != y.ch[posy]) return x.ch[posx] < y.ch[posy];
        int d = min(x.cnt[posx], y.cnt[posy]);
        x.cnt[posx] -= d, y.cnt[posy] -= d;
        if (!x.cnt[posx]) posx++;
        if (!y.cnt[posy]) posy--;
    }
    return false;
}
int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < 26; j++) tot[j] = 0;
        for (int j = 0; j < m; j++)
            tot[s[j] - 'a']++;
        for (int j = 0; j < 26; j++)
            if (tot[j]) a[i].ch[++a[i].l] = j, a[i].cnt[a[i].l] = tot[j];
    }
    for (int i = 1; i <= n; i++){
        bool flag = true;
        for (int j = 1; j <= n; j++)
            if (i != j) flag &= cmp(i, j);
        cout << (int)flag;
    }
    cout << endl;

    return 0;
}
