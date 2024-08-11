#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
int u[N];
int a[N];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n, d, y = 0;
    ll cost = 0;
    cin>>n>>d;

    for(int i = 1; i < n; i++)
        cin>>u[i];

    for(int i = 1; i <= n; i++)
        cin>>a[i];

    if(u[1] % d == 0)
    {
        y = u[1];
        cost = u[1] / d * a[1];
    }
    else
    {
        y = (u[1] / d + 1) * d;
        cost = (u[1] / d + 1) * a[1];
    }

    for(int i = 1; i < n; i++)
    {
        if(u[i] <= y)
        {
            y -= u[i];
            continue;
        }
        else
        {
            int x = u[i] - y;
            if(x % d == 0)
            {
                y += x;
                cost += x / d * a[i];
            }
            else
            {
                y += (x / d + 1) * d;
                cost += (x / d + 1) * a[i];
            }
        }
        int v = 1;
        while(a[i + v] > a[i])
        {
            if(u[i + v - 2] % d == 0)
            {
                y += u[i + v - 2];
                cost += u[i + v - 1] / d * a[i + v];
            }
            else
            {
                y += (u[i + v - 2] / d + 1) * d;
                cost += (u[i + v - 1] / d + 2) * a[i + v];
            }
            v++;
        }

    }

    cout<<cost;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
/*
·ð×æ±£ÓÓAC£¡£¡£¡
*/
