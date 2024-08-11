#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<iomanip>
#include<cstdlib>

using namespace std;

typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mkp make_pair

int c,n,m,q;
int x[500010],y[500010];

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin >> c >> n >> m >> q;
    for(int i = 1;i <= n;i++)
        cin >> x[i];
    for(int i = 1;i <= m;i++)
        cin >> y[i];
    if(c == 1)
    {
        for(int i = 0;i <= q;i++)
            cout << 1;
        cout << endl;
    }
    else if(c == 2)
    {
        int xx[10],yy[10];
        cout << ((x[1] - y[1]) * (x[n] - y[m]) > 0);
        while(q--)
        {
            int kx,ky;
            cin >> kx >> ky;
            memcpy(xx,x,32);
            memcpy(yy,y,32);
            for(int i = 1;i <= kx;i++)
            {
                int p,v;
                cin >> p >> v;
                xx[p] = v;
            }
            for(int i = 1;i <= ky;i++)
            {
                int p,v;
                cin >> p >> v;
                yy[p] = v;
            }
            cout << ((xx[1] - yy[1]) * (xx[n] - yy[m]) > 0);
        }
        cout << endl;
    }
    else
    {
        cout << ((x[1] - y[1]) * (x[n] - y[m]) > 0);
        while(q--)
        {
            int xx[500010],yy[500010];
            int kx,ky;
            cin >> kx >> ky;
            for(int i = 1;i <= kx;i++)
            {
                int p,v;
                cin >> p >> v;
                xx[p] = v;
            }
            for(int i = 1;i <= ky;i++)
            {
                int p,v;
                cin >> p >> v;
                yy[p] = v;
            }
            for(int i = 1;i <= n;i++)
                if(xx[i] == 0)
                    xx[i] = x[i];
            for(int i = 1;i <= m;i++)
                if(yy[i] == 0)
                    yy[i] = y[i];
            cout << ((xx[1] - yy[1]) * (xx[n] - yy[m]) > 0);
        }
        cout << endl;
    }
    return 0;
}
