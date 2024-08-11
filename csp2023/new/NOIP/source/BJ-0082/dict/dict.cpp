#include <iostream>
#include <cstring>

using namespace std;

constexpr int N = 3005;

char a[N][N], mx[N][N], mn[N][N];

int bucket[27], temp[27];

int tot, len;

inline void output(char *str) {
    for (int i = 0; i < len; i++)
        cout << (char)(str[i] | 96);
    cout << ' ';
}

inline void calc(const int x) {
    //sort
    memset(temp, 0, sizeof temp);
    for (int i = 0; i < len; i++)
        temp[a[x][i]]++;
    //calculate mx
    memcpy(mx[x], a[x], len);
    memcpy(bucket, temp, sizeof bucket);
    for (int i = 0, j = 1; i < len; i++) {
        if (bucket[j] == 0)
            for (j++; bucket[j] == 0; j++);
        if (mx[x][i] != j) {
            for (int k = len - 1; k >= 0; k--)
                if (mx[x][k] == j) {
                    swap(mx[x][i], mx[x][k]);
                    //cout << i << ' ' << k << endl;
                }
            break;
        }
        bucket[j]--;
    }
    //calculate mn
    memcpy(mn[x], a[x], len);
    memcpy(bucket, temp, sizeof bucket);
    for (int i = 0, j = 26; i < len; i++) {
        if (bucket[j] == 0)
            for (j--; bucket[j] == 0; j--);
        if (mn[x][i] != j) {
            for (int k = len - 1; k >= 0; k--)
                if (mn[x][k] == j) {
                    swap(mn[x][i], mn[x][k]);
                    //cout << i << ' ' << k << endl;
                }
            break;
        }
        bucket[j]--;
    }
}

//dict order: a > b ==> true
bool cmp(char *a, char *b) {
    for (int i = 0; i < len; i++)
        if (a[i] != b[i])
            return a[i] > b[i];
    return false;
}

int dalao;  //max of {mn[i]}

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> tot >> len;
    for (int i = 0; i < tot; i++) {
        cin >> a[i];
        for (int j = 0; j < len; j++)
            a[i][j] ^= (char)96;
        calc(i);
        if (cmp(mn[dalao], mn[i]))
            dalao = i;
    }
    for (int i = 0; i < tot; i++) {
        if (cmp(mx[i], mn[dalao]))
            cout << '0';
        else
            cout << '1';
    }
    cout << '\n';
    return 0;
}

