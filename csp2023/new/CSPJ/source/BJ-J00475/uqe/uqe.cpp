#include<bits/stdc++.h>
using namespace std;
long long q[100001],c = 1,e;

long long gcd(long long a1,long long a2)
{
    for(int i = 2;i<=min(a1,a2);i++)
    {
        if(a1 % i == 0&& a2 % i == 0)
        {
            c = i;
        }
    }
    return c;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long a,b,c,d,T,M,x,f;
        cin >> T >> M;
        for(int i = 0;i < T;i++)
        {
            cin >> a >> b >> c;
            d =  b*b-4 * a * c;
            if(d < 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                if(sqrt(d) == int(sqrt(d)))
                {
                    d = sqrt(d);
                    if(a > 0)
                    {
                        if(((-b) + d) % (2 * a) == 0)
                        {
                            cout << ((-b) + d) / 2 * a << endl;
                        }
                        else
                        {
                            f = gcd(((-b) + d) % 2 * a,2 *a);
                            cout << ((-b) + d) /f << "/" << 2 * a / f << endl;
                        }
                    }
                    else
                    {
                        if(b != 0)
                        {
                            if((-b) % (2 * a) == 0)
                            {
                                cout << (-b) / 2 * a << "+";
                            }
                            else
                            {
                                f = gcd((-b) % 2 * a,2 * a);
                                cout << (-b)  /f << "/" << 2 * a / f<<"+";
                            }
                        }
                        e = 1;
                        for(int i = 2;i * i < d;i++)
                        {
                            if(d % i == 0)
                                {
                                    e *= i;
                                    d /= i * i;
                                    i--;
                                }
                        }
                    }
                }
            }
        }

    fclose(stdin);
    fclose(stdout);
    return 0;
}