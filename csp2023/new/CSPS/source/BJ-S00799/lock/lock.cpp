#ifdef OJ
#include <iostream>
#else
#include <fstream>
#endif
#include <cstring>

using namespace std;

#ifndef OJ
ifstream cin("lock.in");
ofstream cout("lock.out");
#endif

int a, b, c, d, e, n, cnt[10][10][10][10][10], res;

inline int r(int x, int y)
{
    return (x+y)%10;
}
inline int s(int x, int y)
{
    return (x+10-y)%10;
}

int main(int argc, char **argv)
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d >> e;
        for(int j = 1; j < 5; j++)
        {
            cnt[r(a,j)][b][c][d][e]++,
            cnt[a][r(b,j)][c][d][e]++,
            cnt[a][b][r(c,j)][d][e]++,
            cnt[a][b][c][r(d,j)][e]++,
            cnt[a][b][c][d][r(e,j)]++,
            cnt[r(a,j)][r(b,j)][c][d][e]++,
            cnt[a][r(b,j)][r(c,j)][d][e]++,
            cnt[a][b][r(c,j)][r(d,j)][e]++,
            cnt[a][b][c][r(d,j)][r(e,j)]++,
            cnt[s(a,j)][b][c][d][e]++,
            cnt[a][s(b,j)][c][d][e]++,
            cnt[a][b][s(c,j)][d][e]++,
            cnt[a][b][c][s(d,j)][e]++,
            cnt[a][b][c][d][s(e,j)]++,
            cnt[s(a,j)][s(b,j)][c][d][e]++,
            cnt[a][s(b,j)][s(c,j)][d][e]++,
            cnt[a][b][s(c,j)][s(d,j)][e]++,
            cnt[a][b][c][s(d,j)][s(e,j)]++;
        }
        int j = 5;
        cnt[r(a,j)][b][c][d][e]++,
        cnt[a][r(b,j)][c][d][e]++,
        cnt[a][b][r(c,j)][d][e]++,
        cnt[a][b][c][r(d,j)][e]++,
        cnt[a][b][c][d][r(e,j)]++,
        cnt[r(a,j)][r(b,j)][c][d][e]++,
        cnt[a][r(b,j)][r(c,j)][d][e]++,
        cnt[a][b][r(c,j)][r(d,j)][e]++,
        cnt[a][b][c][r(d,j)][r(e,j)]++;
    }
    for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
    for(int k = 0; k < 10; k++)
    for(int l = 0; l < 10; l++)
    for(int m = 0; m < 10; m++)
    {
        if(cnt[i][j][k][l][m] >= n) res++;
    }
    cout << res << endl;
    return 0;
}