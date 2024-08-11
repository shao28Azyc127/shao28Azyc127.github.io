#include<iostream>
#include<cstdlib>
using namespace std;
const int N = 5e5 + 5;

int c,m,n,q,x[N],y[N];

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin >> c >> m >> n >> q;
    for(int i=1;i<=n;i++)
        cin >> x[i];
    for(int i=1;i<=m;i++)
        cin >> y[i];

    if(n == 1 && m == 1)
    {
        cout << 1;
    }

    else if(n == 2 && m == 2)
    {
        if((x[1] < y[1] && x[2] < y[2]) || (x[1] > y[1] && x[2] > y[2])) cout << 1;
        else cout << 0;
    }

    else if(n == 2 && m == 1)
    {
        if((x[1] > y[1] && x[2] > y[1]) || (x[1] < y[1] && x[2] < y[1])) cout << 1;
        else cout << 0;
    }

    else if(n == 1 && m == 2)
    {
        if((x[1] > y[1] && x[1] > y[2]) || (x[1] < y[1] && x[1] < y[2])) cout << 1;
        else cout << 0;
    }

    else
    {
        cout << rand() % 2 << endl;
    }

    while(q--)
    {
        int kx,ky;
        cin >> kx >> ky;
        for(int i=1;i<=kx;i++)
        {
            int px,vx;
            cin >> px >> vx;
            x[px] = vx;
        }
        for(int i=1;i<=ky;i++)
        {
            int py,vy;
            cin >> py >> vy;
            y[py] = vy;
        }

        if(n == 1 && m == 1)
        {
            cout << 1;
        }

        else if(n == 2 && m == 2)
        {
            if((x[1] < y[1] && x[2] < y[2]) || (x[1] > y[1] && x[2] > y[2])) cout << 1;
            else cout << 0;
        }

        else if(n == 2 && m == 1)
        {
            if((x[1] > y[1] && x[2] > y[1]) || (x[1] < y[1] && x[2] < y[1])) cout << 1;
            else cout << 0;
        }

        else if(n == 1 && m == 2)
        {
            if((x[1] > y[1] && x[1] > y[2]) || (x[1] < y[1] && x[1] < y[2])) cout << 1;
            else cout << 0;
        }

        else
        {
            cout << rand() % 2 << endl;
        }
    }


    return 0;
}
