#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int f[100005];
int v[100005];
int a[100005];
int s[100005];
int T,M;

void print(double x)
{
    if(floor(x) == ceil(x))
    {
        cout << x;
        return;
    }
    else
    {
        for(int i = 1;i <= M;i++)
        {
            for(int j = 1;j <= M;j++)
            {
                if(__gcd(i,j) == 1 && i / (1.0 * j) == abs(x))
                {
                    if(x <= 0) cout << "-";
                    cout << i << "/" << j;
                    return;
                }
            }
        }
    }
    return;
}

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> T >> M;
    while(T--)
    {
        double a,b,c;
        cin >> a >> b >> c;
        double A = b * b - 4 * a * c;
        if(A < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        double B1 = (-b + sqrt(A)) / (2 * a);
        double B2 = (-b - sqrt(A)) / (2 * a);
        double x = max(B1,B2);
        if(sqrt(A) * sqrt(A) == A)
        {
            print(x);
            cout << endl;
            continue;
        }
        double q1,q2;
        if(x == B1)
        {
            q1 = -b / (2 * a);
            q2 = 1 / (2 * a);
        }
        else
        {
            q1 = -b / (2 * a);
            q2 = -1 / (2 * a);
        }
        if(q1 != 0)
        {
            print(q1);
            cout << "+";
        }
        if(q2 == 1)
        {
            cout << "sqrt(" << q2 << ")" << endl;
        }
        else if(ceil(q2) == floor(q2))
        {
            cout << q2 << "*sqrt(" << A << ")" << endl;
        }
        else if(ceil(1 / q2) == floor(1 / q2))
        {
            cout << "sqrt(" << A << ")/" << ceil(1 / q2) << endl;
        }
        else
        {
            bool flag = true;
            for(int i = 2;i <= M;i++)
            {
                for(int j = 2;j <= M;j++)
                {
                    if(__gcd(i,j) == 1 && i / (1.0 * j) == q2)
                    {
                        cout << i << "*sqrt(" << A << ")/" << j << endl;
                        flag = false;
                        break;
                    }
                }
                if(!flag)break;
            }
        }
    }
    return 0;
}
