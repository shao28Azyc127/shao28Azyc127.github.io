#include <bits/stdc++.h>
using namespace std;

int T, M;
struct Uqe
{
    double dval;
    int c, r, d, p, q;
    bool type;//type == true:p/q ; type == false : c * sqrt(r) / d
};

int gcd(int x, int y)
{
    if(x > y)
    {
        if(x % y)
            return gcd(x % y, y);
        else
            return y;
    }
    if(x < y)
    {
        if(y % x)
            return gcd(x, y % x);
        else
            return x;
    }
}

void output(int a, int b, int c, bool type)
{
    bool flag = true;
    if(c == 0 && type == false)
    {
        if(a * b < 0)
            flag = false;
        a = abs(a), b = abs(b);
        int gcdv = (a, b);
        if(gcdv == a && flag)
            cout << b / gcdv;
        else if(gcdv == a && !flag)
            cout << -b / gcdv;
        else if(flag)
            cout << b / gcdv << "/" << a / gcdv;
        else if(a * b == 0)
            cout << 0;
        else
            cout << "-" << b / gcdv << "/" << a / gcdv;
        cout << endl;
    }
    else if(c == 0 && type)
    {
        if(a == 0)
            return ;
        if(a * b < 0)
            flag = false;
        a = abs(a), b = abs(b);
        int gcdv = gcd(a, b);
        if(gcdv == b && flag)
            cout << a / gcdv << "+";
        else if(gcdv == a && !flag)
            cout << -a / gcdv << "+";
        else if(flag)
            cout << a / gcdv << "/" << b / gcdv << "+";
        else
            cout << "-" << a / gcdv << "/" << b / gcdv << "+";
    }
    else
    {
        int c1 = 1, r = c;
        for(int i = 2;i <= sqrt(r);i ++)
        {
            if(r % (i * i) == 0)
            {
                r /= (i * i);
                c1 *= i;
            }
        }
        c1 = abs(c1), b = abs(b);
        int gcdv = gcd(c1, b);
        cout << "c1,b:"<< c1 << " " << b << " " << r << " ";
        if(c1 / b == 1)
            printf("sqrt(%d)", r);
        else if(gcdv == b)
            printf("%d*sqrt(%d)", c1 / b, r);
        else if(gcdv == c1)
            printf("sqrt(%d)/%d", r, b / c1);
        else
            printf("%d*sqrt(%d)/%d", c1 / gcdv, r, b / gcdv);
        printf("\n");
    }
    return ;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> M;
    while(T --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int dval = b * b - 4 * a * c;
        //cout << 9 - T << ":  ";
        if(dval < 0)
            cout << "NO" << endl;
        else if(b == 0)
        {
            int c1 = 1, r = dval;
            for(int i = 2;i <= sqrt(r);i ++)
            {
                if(r % (i * i) == 0)
                {
                    r /= (i * i);
                    c1 *= i;
                }
            }
            if(r == 1)
            {
                output(c1, a * 2, 0, false);
            }
            else
            {
                int gcdv = gcd(c1, a * 2);
                if(c1 == gcdv)
                    printf("sqrt(%d)/%d\n", r, a * 2 / gcdv);
                else if(a * 2 == gcdv)
                    printf("%d*sqrt(%d)\n", c1 / gcdv, r);
                else
                    printf("%d*sqrt(%d)/%d\n", c1 / gcdv, r, a * 2 / gcdv);
            }
        }
        else if(c == 0)
        {
            if(a * b < 0)
                output(-b, a, 0, false);
            else
                printf("0\n");
        }
        else
        {
            //(-b + sqrt(b^2 - 4ac))/2a
            int ans = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
            printf("%d\n", ans);
        }
        /*else if(dval == 0)
        {
            output(-b, 2 * a, 0, false);
        }
        else
        {
            output(-b, 2 * a, 0, true);
            //printf("**output(%d, %d, 0, true)**", -b, 2 * a);
            //printf("**output(1, %d, %d, true)**", 2 * a, dval);
            output(1, 2 * a, dval, true);

        }*/
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
x^2 + 5x + 4 = 0
-5 / 2 + sqrt(9) / 2
-b/a
*/
