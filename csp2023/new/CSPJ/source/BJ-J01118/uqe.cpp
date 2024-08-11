#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t,m;
ll GCD(ll a,ll b)
{
    if(b == 0)
        return a;
    return GCD(b,a % b);
}

bool Do(ll t)
{
    if(t == 0) return false;
    if((long double)sqrt(t) * (long double)sqrt(t) == (long double)t)
        return true;
    return false;
}

/*
炸了……调不出来……
*/

int main()
{
    ios::sync_with_stdio(false);
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    cin >> t >> m;
    while(t--)
    {
        //cout << "---------------\n";
        ll a,b,c;
        bool ttttt = false;
        cin >> a >> b >> c;
        ll delta = b * b - 4 * a * c;

        if(b == 0 && c == 0)
        {
            cout << 0 << endl;
            continue;
        }

        if(b == 0)
        {
            if((a == 1 || a == -1) && !(a > 0 && c > 0) && !(a < 0 && c < 0))
            {
                if(Do(c))
                {
                    cout << sqrt(c) << endl;
                    continue;
                }
            }
        }
        //cout << "AAAA " << delta << endl;
        if(delta < 0)
        {
            cout << "NO" << endl;
            continue;
        }

        ll t1 = 2 * a,t2 = -b;
        //cout << "t1t2: " << t1 << " " << t2 << endl;
        if(t2 != 0)
        {
            if(t1 < 0)
                t1 = -t1,t2 = -t2;
            if(t2 % t1 == 0)
            {
                if(!Do(delta))
                    cout << t2 / t1,ttttt = true;
            }
            else
            {
                if(t2 < 0)
                {
                    ll gcd = GCD(t1,-t2);
                    if(!Do(delta))
                    {
                        t1 /= gcd,t2 /= gcd;
                        cout << t2,ttttt = true;
                        if(t1 != 1)
                            cout << "/" << t1,ttttt = true;
                    }
                }
                else
                {
                    ll gcd = GCD(t1,t2);
                    if(!Do(delta))
                    {
                        t1 /= gcd,t2 /= gcd;
                        cout << t2,ttttt = true;
                        if(t1 != 1)
                            cout << "/" << t1,ttttt = true;
                    }
                }
            }

            if(delta != 0 && !Do(delta))
                cout << '+',ttttt = true;
        }
        
        if(delta == 0)
        {
            if(!ttttt)
                cout << 0;
            cout << endl;
            continue;
        }
        if(Do(delta))
        {
            t2 += sqrt(delta);
            ll gcd = GCD(t1,max(-t2,t2));
            t1 /= gcd,t2 /= gcd;
            //cout << "t1t2: " << t1 << " " << t2 << endl;
            cout << t2,ttttt = true;
            if(t1 != 1)
                cout << "/" << t1,ttttt = true;
        }
        else
        {
            ll s = 1;
            for(ll i = 2;i * i <= delta;i++)
            {
                if(delta % (i * i) == 0)
                {
                    while(delta % (i * i) == 0)
                    {
                        delta /= (i * i);
                        s *= i;
                    }
                }
            }

            ll t3 = 2 * a;
            ll gcd = GCD(s,t3);
            s /= gcd;
            t3 /= gcd;
            s = max(s,-s);
            t3 = max(t3,-t3);
            if(s != 1)
                cout << s << "*",ttttt = true;
            cout << "sqrt(" << delta << ")",ttttt = true;
            if(t3 != 1)
                cout << "/" << t3,ttttt = true;
        }
        if(!ttttt)
            cout << 0;
        cout << endl;
    }

    return 0;
}