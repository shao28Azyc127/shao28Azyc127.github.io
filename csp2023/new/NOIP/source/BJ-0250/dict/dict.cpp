#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

//genshin impact, launch!

#define MAXN 3005

//s -> min, s1 -> max
int n, m;
char maxi[MAXN], mini[MAXN];
int h[MAXN][26];

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    cin >> n >> m;

    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    for(int i = 1; i <= n; i ++)
    {
        maxi[i] = 'a', mini[i] = 'z';
        for(int j = 1; j <= m; j ++)
        {
            char c;
            cin >> c;
            maxi[i] = max(maxi[i], c), mini[i] = min(mini[i], c);
            h[i][c - 'a'] ++;
        }
    }

    for(int i = 1; i <= n; i ++)
    {
        bool flag = true;
        for(int j = 1; j <= n; j ++)
            if((i != j) && (mini[i] >= maxi[j]))  flag = false;

        if(!flag)  cout << 0;
        else  cout << 1;
    }
    return 0;
}
