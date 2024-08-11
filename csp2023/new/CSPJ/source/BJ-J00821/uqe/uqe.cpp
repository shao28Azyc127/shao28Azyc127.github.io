#include <bits/stdc++.h>
using namespace std;

/*
    gei wo ti jiao qian qu diao freopen zhu shi!!!
    qu diao freopen zhu shi!!!
    da kai freopen!!!
*/

// chu shi hua yao jia a = 0

int T, m;

int gcd(int x, int y)
{
    x = abs(x); y = abs(y);
    int nx = max(x, y), ny = min(x, y);
    while(ny != 0)
    {
        nx %= ny;
        if(nx < ny) swap(nx, ny);
    }
    return nx;
}

bool check(int wasd)
{
    for(int i = 2; i * i <= wasd; i++)
    {
        if(wasd % i == 0) return 0;
    }
    return 1;
}

int getsqrt(int gjr)
{
    int ans = 1;
    for(int i = 2; i * i <= gjr; i++)
    {
        if(check(i) && gjr % i == 0)
        {
            int cnt = 0, gjr2 = gjr;
            while(gjr2 % i == 0)
            {
                cnt++;
                gjr2 /= i;
            }
            cnt /= 2;
            for(int j = 1; j <= cnt; j++)
            {
                ans *= i;
            }
        }
    }
    return ans;
}

// xo /= gcd(xo, yo); yo /= gcd(xo, yo);

int main()
{
    // freopen("uqe.in", "r", stdin);
    // freopen("uqe.out", "w", stdout);

    cin>>T>>m;
    while(T--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        int derta = b * b - 4 * a * c;
        if(derta < 0) cout << "NO" << endl;
        else
        {
            double sqrtd = sqrt(derta);

            if(sqrtd == int(sqrtd)) // neng kai da lei zhu yi!!
            {
                bool f = 0;
                int xo = -b + sqrtd, yo = 2 * a;
                f = ((xo!=abs(xo)||yo!=abs(yo)) && (xo==abs(xo)||yo==abs(yo)));
                if(f) cout << "-";
                xo = abs(xo); yo = abs(yo);
                int t = gcd(xo, yo);
                xo /= t; yo /= t;
                if(yo == 1) cout << xo;
                else cout << xo << "/" << yo;
            }

            if(b != 0 && sqrtd != int(sqrtd)) // bu neng kai qian ban
            {
                bool f = 0;
                int xo = -b, yo = 2 * a;
                f = ((xo!=abs(xo)||yo!=abs(yo)) && (xo==abs(xo)||yo==abs(yo)));
                if(f) cout << "-";
                xo = abs(xo); yo = abs(yo);
                int t = gcd(xo, yo);
                xo /= t; yo /= t;
                if(yo == 1) cout << xo;
                else cout << xo << "/" << yo;
            }

            if(sqrtd != int(sqrtd)) // bu neng kai hou ban
            {
                if(getsqrt(derta) == 1) // gen qian wu
                {
                    if(a != abs(a)) cout<<"-";
                    else if(b != 0) cout<<"+";
                    a = abs(a);
                    if(2*a != 1) cout<<"sqrt("<<derta<<")"<<"/"<<abs(2*a);
                    else cout<<"sqrt("<<derta<<")";
                }
                else // gen qian you
                {
                    bool f = 0;
                    int xo = getsqrt(derta), yo = 2 * a;
                    f = ((xo!=abs(xo)||yo!=abs(yo)) && (xo==abs(xo)||yo==abs(yo)));
                    if(f) cout << "-";
                    else if(b != 0) cout<<"+";
                    xo = abs(xo); yo = abs(yo);
                    int tx = xo;
                    int t = gcd(xo, yo);
                    xo /= t; yo /= t;
                    if(xo != 1) cout <<xo <<"*";
                    cout<<"sqrt("<<derta/(tx*tx)<<")"; // gen xia wu
                    if(yo != 1) cout<<"/"<<yo;
                }
            }
            cout << endl;
        }
    }
    return 0;
}
