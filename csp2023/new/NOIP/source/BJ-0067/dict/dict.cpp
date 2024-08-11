//明月几时有？把酒问青天。不知天上宫阙，今夕是何年。
#include <bits/stdc++.h>
using namespace std;

const int maxn = 3005;

int posfir, possec, n, m;
int r[maxn], sec[maxn], fir[maxn];
int t[maxn][maxn];
int cnt[26], cnt2[26];

void compse(int pos)
{
    int op = 0;
    for (int i = 1; i <= m; i++)
        if (!op && r[i] < sec[i]) op = 1;
        else if (!op && r[i] > sec[i]) op = -1;
    if (op == 1)
    {
        for (int i = 1; i <= m; i++) sec[i] = r[i];
        possec = pos;
    }
    else if (op == 0) possec = pos;
}

void compfi()
{
    int op = 0;
    for (int i = 1; i <= m; i++)
        if (!op && sec[i] < fir[i]) op = 1;
        else if (!op && sec[i] > fir[i]) op = -1;
    if (op == 1)
    {
        for (int i = 1; i <= m; i++) swap(fir[i], sec[i]);
        swap(posfir, possec);
    }
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) fir[i] = sec[i] = 0x3f3f3f3f;
    posfir = possec = 0;
    for (int i = 1; i <= n; i++)
    {
        char s[maxn];
        cin >> s + 1;
        memset(cnt, 0, sizeof(cnt));
        memset(cnt2, 0, sizeof(cnt2));
        for (int j = 1; j <= m; j++) cnt[s[j] - 'a']++, cnt2[s[j] - 'a']++;

        int pos1 = 0, pos2 = 0;
        for (int j = 0; j < 26; j++)
            while (cnt[j]) t[i][++pos1] = j, cnt[j]--;
        for (int j = 25; ~j; j--)
            while (cnt2[j]) r[++pos2] = j, cnt2[j]--;
        
        compse(i);
        compfi();
    }

    for (int i = 1; i <= n; i++)
    {
        int op = 0;
        if (i == posfir)
        {
            for (int j = 1; j <= m; j++)
                if (!op && t[i][j] < sec[j]) op = 1;
                else if (!op && t[i][j] > sec[j]) op = -1;
        }
        else
        {
            for (int j = 1; j <= m; j++)
                if (!op && t[i][j] < fir[j]) op = 1;
                else if (!op && t[i][j] > fir[j]) op = -1;
        }
        cout << (op > 0 ? 1 : 0);
    }
    cout << "\n";
    return 0;
}