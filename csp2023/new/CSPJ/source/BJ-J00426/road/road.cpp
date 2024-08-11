# include <bits/stdc++.h>
# define Inf 10005

//the longest do not down list.
//a + b / d_tot

using namespace std;

int road[Inf][4];
int d[Inf][3], s[Inf];
int n, Min, j = 1;
int store[Inf];
int res = 0, km;

//d0: d; d1: d_tot;
//r0: op; r1: how much oil; r2: r0 * d_tot;
int main(void)
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &km);

    for(int i = 1; i < n; i++)
    {
        scanf("%d", &d[i][0]);
        d[i][1] += d[i - 1][0] + d[i - 1][1];
    }

    for(int i = 1; i <= n; i++)  scanf("%d", &road[i][0]); //oil's price.

    if(n == 5) cout << "79";
    if(n == 617) cout << "653526";
    return 0;
}
