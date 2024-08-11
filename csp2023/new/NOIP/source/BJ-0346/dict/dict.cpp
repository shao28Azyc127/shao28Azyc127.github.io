#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N = 3010;

int n, m;
string s[N], t[N];
int buc[30];

signed main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < m; j++)
            buc[s[i][j] - 'a']++;
        int cnt = 0;
        for (int j = 0; j < 26; j++)
            while (buc[j])
                s[i][cnt++] = char(j + 'a'), buc[j]--;
        t[i] = string(s[i].rbegin(), s[i].rend());
    }
    int pos1 = 0, pos2 = 0;
    for (int i = 1; i <= n; i++)
        if (t[i] < t[pos1] || !pos1)
            pos2 = pos1, pos1 = i;
        else if (t[i] < t[pos2] || !pos2)
            pos2 = i;
    for (int i = 1; i <= n; i++)
        if ((i != pos1 && s[i] < t[pos1]) || (i != pos2 && s[i] < t[pos2]))
            cout << 1;
        else
            cout << 0;
    cout << endl;
}
