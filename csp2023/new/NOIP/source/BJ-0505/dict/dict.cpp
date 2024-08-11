#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int NR = 3e3 + 10;
const int MR = 3e3 + 10;

string s[NR], s_min[NR];

struct Node
{
    int id;
    string ss;
}s_max[NR];

bool cmp(Node x, Node y)
{
    return x.ss < y.ss;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s_min[i] = s[i];
        sort(s_min[i].begin(), s_min[i].end());
        for(int j = 0; j < m; j++) s_max[i].ss += s_min[i][m - j - 1];
        s_max[i].id = i;
    }
    sort(s_max + 1, s_max + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        if(s_min[i] < s_max[1].ss)
        {
            cout << 1;
            continue;
        }
        if(i == s_max[1].id)
        {
            if(s_min[i] < s_max[2].ss) cout << 1;
            else cout << 0;
            continue;
        }
        cout << 0;
    }
    cout << endl;
    return 0;
}
