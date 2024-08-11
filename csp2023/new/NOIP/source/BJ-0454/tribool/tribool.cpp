#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define int long long
using namespace std;
int n,m;
struct op
{
    char op;
    int a,b;
}o[1000010];
void clearop()
{
    for(int i = 1; i <= 1000000; i++)
    {
        o[i].op = '\0';
        o[i].a = o[i].b = 0;
    }
}
int x[1000010];
int tx[100010];
bool cmmp()
{
    for(int i = 1; i <= n; i++)
    {
        if(tx[i] != x[i]) return 0;
    }
    return 1;
}
void print()
{
    for(int i = 1; i <= n; i++) cout << x[i] << " " << tx[i] << endl;
    cout << endl;
}
int mincnt = 100000000;
void bl(int st)
{
    if(st > n)
    {
        for(int i = 1; i <= n; i++) tx[i] = x[i];
        //print();
        for(int i = 1; i <= m; i++)
        {
            if(o[i].op == '+')
            {
                tx[o[i].a] = tx[o[i].b];
            }
            else if(o[i].op == '-')
            {
                if(tx[o[i].b] == -1) tx[o[i].a] = -2;
                else if(tx[o[i].b] == -2) tx[o[i].a] = -1;
                else if(tx[o[i].b] == -3) tx[o[i].a] = -3;
            }
            else if(o[i].op == 'T') tx[o[i].a] = -1;
            else if(o[i].op == 'F') tx[o[i].a] = -2;
            else if(o[i].op == 'U') tx[o[i].a] = -3;
        }
        //print();
        if(cmmp() == 1)
        {
            int cnt = 0;
            for(int i = 1; i <= n; i++)
            {
                if(tx[i] == -3) cnt++;
            }
            //cerr << cnt <<endl;
            mincnt = min(mincnt,cnt);
        }
        return;
    }
    x[st] = -1;
    bl(st + 1);
    x[st] = -2;
    bl(st + 1);
    x[st] = -3;
    bl(st + 1);
}
signed main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin >> c >> t;
    if(c == 1 || c == 2 || c > 4)
    {
        while(t--)
        {
            clearop();
            mincnt = 100000000;
            cin >> n >> m;
            for(int i = 1; i <= m; i++)
            {
                cin >> o[i].op;
                if(o[i].op == '+' || o[i].op == '-') cin >> o[i].a >> o[i].b;
                else cin >> o[i].a;
            }
            bl(1);
            cout << mincnt << endl;
        }
    }
    else if(c == 3 || c == 4)
    {
        while(t--)
        {
            clearop();
            cin >> n >> m;
            for(int i = 1; i <= m; i++)
            {
                char op;
                int a;
                cin >> op >> a;
                if(op == 'T')
                {
                    x[a] = -1;
                }
                else if(op == 'F')
                {
                    x[a] = -2;
                }
                else
                {
                    x[a] = -3;
                }
            }
            int cnt = 0;
            for(int i = 1; i <= n; i++)
            {
                if(x[i] == -3) cnt++;
            }
            cout << cnt;
        }
    }
    return 0;
}
//lym真的烦，有hzl还不够非要hjx, 40pts
