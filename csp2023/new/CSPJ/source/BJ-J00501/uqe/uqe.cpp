#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long gcd(ll a, ll b)
{
    if (a - b == 1 or a - b == -1) return 1;
    for(ll i=min(a,b);i>=1;i++)
    {
        if (a%i==0&&b%i==0)
        {
            return i;
        }
    }
}
int main()
{
    //freopen("uqe.in", "r", stdin);
    //freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    for (t; t > 0; t --)
    {
        long long a, b, c, derrta;
        cin >> a >> b >> c;
        derrta = b * b - 4 * a * c;
        if (derrta < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        else if (derrta == 0)
        {
            if (b % (2 * a) == 0)
            {
                cout << b / 2 / a << endl;
            }
            else
            {
                int gccd = gcd(b, a * 2);
                cout << gccd << "/" << (a * 2) / gccd;
            }
        }
        else
        {
            int tong[10010];
            int flag = 1;
            for (int i = 1; i * i <= derrta; i ++)
            {
                if (derrta == 1) break;
                while (derrta % i == 0)
                {
                    derrta /= i;
                    tong[i] ++;
                }
            }
            int subq2 = 1;
            for (int i = 1; i * i <= derrta; i ++)
            {
                if (tong[i] % 2)
                {
                    flag *= i;
                    //zhegeshubushipingfangshu

                }
                if (tong[i])
                {
                    subq2 *= pow(i, tong[i] / 2);
                }
            }
            if (flag==1)
            {
                //cout << 514 << "\n";
                int subans = subq2 - b;
                if (subans % (2 * a) ==0)
                {
                    cout << subans/(2*a)<<endl;
                }
                else
                {
                    int gccd = gcd(subans, a * 2);
                    cout << gccd << "/" << (a * 2) / gccd;
                }
            }
            else
            {
                //cout<<1919810<<endl;
                if (b % (2 * a) == 0)
                {
                    cout << b / 2 / a << '+';
                }
                else
                {
                    int gccd = gcd(b, a * 2);
                    cout << gccd << "/" << (a * 2) / gccd;
                }
                cout <<'+';
                if (subq2 != 1)
                    cout << subq2<<"*";
                cout << "pow(" << flag << ")"<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
