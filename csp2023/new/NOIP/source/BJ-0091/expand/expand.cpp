//#include <iostream>
#include <fstream>
using namespace std;

ifstream cin("expand.in");
ofstream cout("expand.out");

int ori_x[20004], ori_y[20004];
int x[20004], y[20004];
bool dp[20004][20004];

int get_ans(int n, int m)
{
    dp[0][1] = true;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = (((x[1] > y[1] && x[i] > y[j]) || (x[1] < y[1] && x[i] < y[j])) && (dp[i - 1][j] || dp[i][j - 1]));
        }
    }
    if(dp[n][m]) return 1;
    return 0;
}

int main()
{
    int c, n, m, q;
    cin >> c >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> ori_x[i];
    for(int i = 1; i <= m; i++) cin >> ori_y[i];
    for(int i = 1; i <= n; i++) x[i] = ori_x[i];
    for(int i = 1; i <= m; i++) y[i] = ori_y[i];
    cout << get_ans(n, m);
    while(q--)
    {
        for(int i = 1; i <= n; i++) x[i] = ori_x[i];
        for(int i = 1; i <= m; i++) y[i] = ori_y[i];
        int kx, ky;
        cin >> kx >> ky;
        for(int i = 1; i <= kx; i++)
        {
            int p, v;
            cin >> p >> v;
            x[p] = v;
        }
        for(int i = 1; i <= ky; i++)
        {
            int p, v;
            cin >> p >> v;
            y[p] = v;
        }
        cout << get_ans(n, m);
    }
    cout << endl;
}
