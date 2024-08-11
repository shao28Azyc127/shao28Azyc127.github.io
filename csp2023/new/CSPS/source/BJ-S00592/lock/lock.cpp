#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 10;

int n;

int num[N][7];

vector <int> book [90];

bool can[90];
int ans, cnt;
int a[8];

void dfs_1(int x, int p) {
    //cout << x << " " << p << endl;
    if (x == 6) {
        ++ cnt;
        for (int i = 1; i <= 5; i ++ ) {
            book[cnt].push_back (a[i]);
        }
        return ;
    }
    if (x == p) {
        for (int i = 0; i <= 9; i ++ ) {
            if (i == num[1][x]) continue;
            a[x] = i;
            dfs_1(x + 1, p);
        }
    }
    else {
        a[x] = num[1][x];
        dfs_1(x + 1, p);
    }

}

bool check (int na, int nb, int a, int b) {
    //cout << na << " " << nb << " " << a << " " << b << endl;

    if (na == a || nb == b) return false;
    if (na - a == nb - b) return true;
    if (na + 10 - a == nb + 10 - b) return true;
    if (na + 10 - a == nb - b) return true;
    if (na - a == nb + 10 - b) return true;
    return false;
}

void dfs_2 (int x, int p) {
    if (x >= 5) {
        ++ cnt;
        for (int i = 1; i <= 5; i ++ ) {
            book[cnt].push_back (a[i]);
        }
        return ;
    }
    //cout << x << " " << p << endl;
    if (x == p) {
        //cout << x << endl;
        for (int i = 0; i <= 9; i ++ ) {
            for (int j = 0; j <= 9; j ++ ) {
                if (check (i, j, num[1][x], num[1][x + 1])) {
                    //cout << "-" << i << " " << j << endl;
                    a[x] = i;
                    a[x + 1] = j;
                    dfs_2(x + 2, p);
                }
            }
        }
    }
    else {
        //cout << " " << x << endl;
        a[x] = num[1][x];
        dfs_2(x + 1, p);
    }
}

int peter = -1;
int diff (int a, int b ) {
    int res = 0;
    int pos1 = 0, pos2 = 0;
    for (int i = 0; i < 5; i ++ ) {
        int p1 = book[a][i];
        int p2 = num[b][i + 1];
        if (p1 != p2) {
            res ++ ;
            if (!pos1) pos1 = i;
            else pos2 = i;
        }
    }

    if (pos1 + 1 == pos2 && check (book[a][pos1], book[a][pos2], num[b][pos1 + 1], num[b][pos2 + 1])) peter = 1;
    return res;
}


int main () {
    freopen ("lock.in", "r", stdin);
    freopen ("lock.out", "w", stdout);

    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= 5; j ++ ) {
            cin >> num[i][j];
        }
    }

    if (n == 1) {
        cout << "81" << endl;
        return 0;
    }
    for (int i = 1; i <= 5; i ++ )
        dfs_1 (1, i);
    //cout << cnt <<endl;

    for (int i = 1; i <= 4; i ++ )
        dfs_2 (1, i);

    //for (int i = 1; i <= cnt; i ++ ) {
      //  for (int j = 0; j < 5; j ++ ) {
        //    cout << book[i][j] << " ";
       // }
        //cout << endl;
    //}
    //cout << cnt << endl;
    for (int i = 2; i <= n; i ++ ) {
        for (int j = 1; j <= cnt; j ++ ) {
            if (can[j]) continue;
            peter = -1;
            if (diff(j, i) == 0) {
                can[j] = true;
                continue;
            }
            if (diff(j, i) == 1) continue;
            else if (diff (j, i) > 2) {
                can[j] = true;
                continue;
            }
            else if (peter == -1) {
                can[j] = true;
                continue;
            }

        }
    }

   // cout << cnt << endl;
    for (int i = 1; i <= cnt; i ++ ) {
        if (!can[i]) {
                ans ++ ;
        }
    }

    cout << ans << endl;

    return 0;
}
