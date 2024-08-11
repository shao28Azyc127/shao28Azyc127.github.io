#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<cstring>

using namespace std;

int T,m;
int a,b,c;

int gcd(int a,int b)
{
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    if(a > b)
    {
        return gcd(a % b,b);
    }
    else
        return gcd(b % a,a);
}

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> T >> m;
    while(T--)
    {
        cin >> a >> b >> c;
        if(a < 0)
        {
            a = -a,b = -b,c = -c;
        }
        int delta = b * b - 4 * a * c;
        if(delta < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        int e = sqrt(delta);
        if(e * e == delta)//根号不存在，有理数
        {
            int down = a * 2;
            int up = -b + e;
            if(0 == up  % down)//分母不存在
            {
                cout << up / down << endl;
            }
            else
            {
                int v = gcd(abs(up),abs(down));//最简整数比
                up /= v,down /= v;
                if(up / down > 0)
                    cout << up << '/' << down << endl;
                else
                    cout << '-' << abs(up) << '/' << abs(down) << endl;
            }
        }
        else
        {
            int q2 = 1;
            int down = a * 2;
            int del = delta;
            for(int i = 2;i * i <= del;i++)
            {
                while(del % (i * i) == 0)
                {
                    del /= i * i;
                    q2 *= i;
                }
            }//delta剩下的为根号里的r
            // cout << "*******" << delta << ' ' << del << ' ' << q2 << endl;
            int q1 = -b;
            //处理第一部分有理数
            if(q1 != 0)
            {
                if(0 == q1 % down)
                {
                    cout << q1 / down;
                }
                else
                {
                    int v = gcd(abs(q1),abs(down));
                    q1 /= v;
                    int down1 = down / v;
                    if(q1 / down1 > 0)
                    {
                        cout << q1 << '/' << down1;
                    }
                    else
                    {
                        cout << '-' << abs(q1) << '/' << abs(down1);
                    }
                }
                cout<<'+';
            }
            //处理无理数
            if(q2 == down)
            {
                cout << "sqrt(" << del << ")\n";
                // cout << 1 << endl;
            }
            else if(q2 % down == 0 )
            {
                cout << abs(q2 / down) << "*sqrt(" << del << ")\n";
                // cout << 2 << endl;
            }
            else if(down % q2 == 0)
            {
                cout << "sqrt(" << del << ")/" << abs(down / q2) << endl;
                // cout << 3 << endl;
            }
            else
            {
                int v = gcd(abs(q2),abs(down));
                q2 /= v;
                int down2 = down / v;
                cout << q2 << "*sqrt(" << del << ")/" << down2 << endl;
                // cout << 4 << endl;
            }
        }
    }
    return 0;
}
