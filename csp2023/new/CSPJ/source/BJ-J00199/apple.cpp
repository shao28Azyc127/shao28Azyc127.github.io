#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005

bool used[MAXN];
int n, getn;

void out_array(bool *arr, int n)
{
    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
#endif
    cin >> n;
    int startidx = 1, i = 1;
    while (true) {
        int step = 0;
        used[startidx] = true;
        for (int i = startidx; i <= n; i++) {
            if (!used[i]) step++;
            if (step == 3) {
                step = 0;
                used[i] = true;
            }
        }
        if (!getn && used[n]) getn = i;
        while (used[startidx]) startidx++;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            flag &= used[i];
        }
        if (flag) break;
        i++;
    }
    cout << i << " " << getn << endl;
    return 0;
}