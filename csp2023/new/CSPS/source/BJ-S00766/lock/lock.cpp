#include <iostream>

using namespace std;
constexpr int N = 10;

int a[N][10];
int n;
int b[10];

//int cnt_type1 = 0, cnt_type2 = 0;

inline bool check(int *c) {
    int diff1 = 0, diff2 = 0;
    int diff1_pos;
    for (int i = 0; i < 5; i++) {
        if (b[i] != c[i]) {
            if (diff1 == 0) {
                diff1 = b[i] - c[i];
                if (diff1 < 0)
                    diff1 += 10;
                diff1_pos = i;
            } else if (diff2 == 0 && diff1_pos == i - 1) {
                diff2 = b[i] - c[i];
                if (diff2 < 0)
                    diff2 += 10;
            } else
                return false;   //more than 2 diffs
        }
    }
    if (diff1 == 0)
        return false;   //no diff
    if (diff2 == 0) {
        //cnt_type1++;
        //cout << "1 ";
        //for (int i = 0; i < 5; i++) cout << b[i] << ' ';
        //cout << '\n';
        return true;    //only 1 diff
    }
    if (diff1 == diff2) {
        //cnt_type2++;
        //cout << "2 ";
        //for (int i = 0; i < 5; i++) cout << b[i] << ' ';
        //cout << '\n';
        return true;    //2 same diffs
    }
    return false;
}

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
    int cnt = 0;
    for (b[0] = 0; b[0] < 10; b[0]++)
        for (b[1] = 0; b[1] < 10; b[1]++)
            for (b[2] = 0; b[2] < 10; b[2]++)
                for (b[3] = 0; b[3] < 10; b[3]++)
                    for (b[4] = 0; b[4] < 10; b[4]++) {
                        int i;
                        for (i = 1; i <= n; i++)
                            if (!check(a[i]))
                                break;
                        if (i > n)
                            cnt++;
                    }
    cout << cnt;
    //cout << ' ' << cnt_type1 << ' ' << cnt_type2 << endl;
    return 0;
}

