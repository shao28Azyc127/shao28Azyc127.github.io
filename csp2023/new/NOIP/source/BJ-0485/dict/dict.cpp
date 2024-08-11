#include <iostream>

using namespace std;

const int NR = 3010;
string w[NR], maxs = "{{";
int n, m, pos = -1;
bool flag[NR];

void dfs(int step)
{
    if (step > n)
    {
        maxs = "{{", pos = -1;
        for (int i = 1; i <= n; i++)
            if (w[i] < maxs) maxs = w[i], pos = i;
        for (int i = 1; i <= n; i++)
            if (maxs == w[i] && pos != i) pos = -1;
        if (pos != -1) flag[pos] = true;
        return;
    }
    dfs(step + 1);
    string temp = w[step];
    w[step][0] = temp[1], w[step][1] = temp[0];
    dfs(step + 1);
    w[step] = temp;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    cin >> n >> m;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    if (m == 1)
    {
        for (int i = 1; i <= n; i++)
            if (w[i] < maxs) maxs = w[i], pos = i;
        for (int i = 1; i <= n; i++)
            if (maxs == w[i] && pos != i) pos = -1;
        for (int i = 1; i <= n; i++)
            cout << ((pos == i) ? (1) : (0));
    }
    else if(m == 2)
    {
        dfs(1);
        for (int i = 1; i <= n; i++)
            cout << flag[i];
    }
    return 0;
}