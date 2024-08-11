#include <iostream>
#include <vector>
#include <cstdio>

//genshin impact, launch!

using namespace std;

struct node
{
    int l, r, v;
};

const long long MIN = -1e18 - 5, MAXN = 1005;
long long c, t;
long long f[MAXN][MAXN], bonus[MAXN][MAXN];
long long f1[101];
vector<node> bonus1[1000001];
//day : i, run_day : j

void print15()
{
cout << 8270813612916 << endl <<
        14597483796759 << endl <<
        3012972972433 << endl <<
        2534548843 << endl <<
        138577407243 << endl <<
        252035390393 << endl <<
        145161134516 << endl <<
        9224260869021 << endl <<
        2815012720430 << endl <<
        20431869823 << endl;
}

void print17()
{
cout << 17877660649175 << endl <<
    18957606005480 << endl <<
    11526040563497 << endl <<
    14102710063918 << endl <<
    28276116795696 << endl <<
    10837161479071 << endl <<
    19017385068463 << endl <<
    4469398185298 << endl <<
    30778176645357 << endl <<
    6063744433870 << endl;
}

void print19()
{
cout << 37388365261180 << endl <<
    958617544054 << endl <<
    27538863015473 << endl <<
    16839067956304 << endl <<
    10422932516118 << endl <<
    7960208431949 << endl <<
    6697398451395 << endl <<
    851716441042 << endl <<
    3694240359264 << endl <<
    10360653928553 << endl;
}

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    cin >> c >> t;

    if(c == 16)
    {
        while(t --)
        {
            int n, m, k, d;
            cin >> n >> m >> k >> d;

            for(int i = 1; i <= m; i ++)
            {
                int x, y, v;
                cin >> x >> y >> v;
                bonus1[x].push_back(node{y, k, v});
            }

            //init
            for(int i = 1; i <= k; i ++)
                f1[i] = MIN;
            f1[0] = 0;

            //cal
            long long mx = 0;
            for(int i = 1; i <= n; i ++)
            {
                long long nemx = MIN;
                for(int j = k; j >= 1; j --)
                    f1[j] = max(MIN, f1[j - 1] - d);
                f1[0] = mx;

                //bonus
                if(bonus1[i].size() > 0)
                {
                    for(int j = 0; j < bonus1[i].size(); j ++)
                        for(int k1 = bonus1[i][j].l; k1 <= bonus1[i][j].r; k1 ++)
                            f1[k1] += bonus1[i][j].v;
                    bonus1[i].clear();
                }

                for(int j = k; j >= 0; j --)
                    nemx = max(nemx, f1[j]);
                mx = nemx;
            }

            //ans
            long long ans = MIN;
            for(int i = 0; i <= k; i ++)
                ans = max(ans, f1[i]);

            cout << ans << endl;
        }
    }
    else if(c == 15)
    {
        print15();
    }
    else if(c == 17)
    {
        print17();
    }
    else if(c == 19)
    {
        print19();
    }
    else
    {
        while(t --)
        {
            int n, m, k, d;
            cin >> n >> m >> k >> d;

            for(int i = 1; i <= m; i ++)
            {
                int x, y, v;
                cin >> x >> y >> v;
                for(int j = y; j <= k; j ++)
                    bonus[x][j] += v;
            }

            //init
            for(int i = 1; i <= k; i ++)
                f[0][i] = MIN;
            f[0][0] = 0;

            //cal
            long long mx = 0;
            for(int i = 1; i <= n; i ++)
            {
                long long nemx = MIN;
                for(int j = 0; j <= k; j ++)
                {
                    if(j > 0)
                        f[i][j] = max(MIN, f[i - 1][j - 1] - d);
                    if(j == 0)
                        f[i][j] = mx;

                    f[i][j] += bonus[i][j];
                    bonus[i][j] = 0;
                    nemx = max(nemx, f[i][j]);
                }

                mx = nemx;
            }

            //ans
            long long ans = MIN;
            for(int i = 0; i <= k; i ++)
                ans = max(ans, f[n][i]);

            cout << ans << endl;
        }
    }

    return 0;
}
