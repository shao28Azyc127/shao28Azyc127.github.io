#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t, M;
ll a, b, c;
ll a1[1000005];
ll gcd(ll x, ll y)
{
    if(y == 0)
    {
        return x;
    }
    else{
        return gcd(y, x % y);
    }
}
void solve(ll p, ll q, ll r)
{
    ll d = q*q - 4*p*r;
    if(d < 0)
    {
        printf("NO\n");
    }
    else if(d == 0)
    {
        ll tmp1 = gcd(max(abs(q), abs(2*p)), min(abs(q), abs(2*p)));
        if(tmp1 == 0)
        {
            tmp1 = 1;
        }
        q = -q;
        q /= tmp1;
        ll tmp2 = 2*p;
        tmp2 /= tmp1;
        if(q == 0)
        {
            printf("%d\n", 0);
            return;
        }
        else if (tmp2 == 1)
        {
            printf("%lld\n", q);
            return;
        }
        else if(tmp2 == -1)
        {
            printf("%lld\n", -q);
            return;
        }
        else  if(tmp2 > 0)
        {
            printf("%lld/%lld\n", q, tmp2);
            return;
        }
        else
        {
            printf("%lld/%lld\n", -q, -tmp2);
            return;
        }
    }
    else
    {
        ll tmp;
        tmp = sqrt(d);
        if(tmp * tmp != d)
        {
            ll tmp1 = gcd(max(abs(q), abs(2*p)), min(abs(q), abs(2*p)));
            if(tmp1 == 0)
            {
                tmp1 = 1;
            }
            ll q1 = q;
            q1 /= tmp1;
            ll tmp2 = 2*p;
            tmp2 /= tmp1;
            if(q1 == 0)
            {

            }
            else if(tmp2 == 1)
            {
                printf("%lld+", -q1);
            }
            else if(tmp2 == -1)
            {
                printf("%lld+", q1);
            }
            else if(tmp2 > 0 && tmp1 != 0)
            {
                printf("%lld/%lld+", -q1, tmp2);
            }
            else
            {
                printf("%lld/%lld+", q1, -tmp2);
            }
            ll tmp3 = a1[d];
            ll tmp4 = d / (a1[d] * a1[d]);
            if(p > 0)
            {
                ll tmp5 = gcd(max(2*p, tmp3), min(2*p, tmp3));
                if(tmp5 == 0)
                {
                    tmp5 = 1;
                }
                ll tmp6 = 2*p;
                tmp6 /= tmp5;
                tmp3 /= tmp5;
                if(tmp3 == 1 && tmp6 == 1)
                {
                    printf("sqrt(%lld)\n", tmp4);
                    return;
                }
                else if(tmp3 == 1)
                {
                    printf("sqrt(%lld)/%lld\n", tmp4, tmp6);
                    return;
                }
                else if(tmp6 == 1)
                {
                    printf("%lld*sqrt(%lld)\n", tmp3, tmp4);
                    return;
                }
                else
                {
                    printf("%lld*sqrt(%lld)/%lld\n", tmp3, tmp4, tmp6);
                    return;
                }
            }
            else
            {
                ll tmp5 = gcd(max(abs(2*p), tmp3), min(abs(2*p), tmp3));
                if(tmp5 == 0)
                {
                    tmp5 = 1;
                }
                ll tmp6 = 2*p;
                tmp6 /= tmp5;
                tmp3 /= tmp5;
                tmp6 = -tmp6;
                tmp3 = -tmp3;
                if(tmp3 == 1 && tmp6 == 1)
                {
                   printf("-sqrt()%lld\n", tmp4);
                    return;
                }
                else if(tmp3 == -1)
                {
                    printf("-sqrt(%lld)/%lld\n", tmp4, tmp6);
                    return;
                }
                else if(tmp6 == 1)
                {
                    printf("%lld*sqrt(%lld)\n", tmp3, tmp4);
                    return;
                }
                else
                {
                    printf("%lld*sqrt(%lld)/%lld\n", tmp3, tmp4, tmp6);
                    return;
                }
            }
        }
        else
        {
            if(p > 0)
            {
                ll tmp3 = -q + tmp;
                ll tmp4 = gcd(max(abs(tmp3), abs(2*p)), min(abs(tmp3), abs(2*p)));
                if(tmp4 == 0)
                {
                    tmp4 = 1;
                }
                tmp3 /= tmp4;
                ll tmp5 = 2*p;
                tmp5 /= tmp4;
                if(tmp3 == 0)
                {
                    printf("%d\n", 0);
                    return;
                }
                else if(tmp5 == 1)
                {
                    printf("%lld\n", tmp3);
                    return;
                }
                else
                {
                    printf("%lld/%lld\n", tmp3, tmp5);
                    return;
                }
            }
            else
            {
                ll tmp3 = -q - tmp;
                ll tmp4 = gcd(max(abs(tmp3), abs(2*p)), min(abs(tmp3), abs(2*p)));
                if(tmp4 == 0)
                {
                    tmp4 = 1;
                }
                tmp3 /= tmp4;
                ll tmp5 = 2*p;
                tmp5 /= tmp4;
                if(tmp3 == 0)
                {
                    printf("%d\n", 0);
                    return;
                }
                else if(tmp5 == -1)
                {
                    printf("%lld", -tmp3);
                    return;
                }
                else
                {
                    printf("%lld/%lld\n", -tmp3, -tmp5);
                    return;
                }
            }
        }
    }
}
void sqr()
{
    for(int i = 1;i <= 5*M*M;i ++)
    {
        for(int j = 1;j * j <= i;j ++)
        {
            if(i % (j * j) == 0)
            {
                a1[i] = j;
            }
        }
        if(a1[i] == 0)
        {
            a1[i] = 1;
        }
    }
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &t, &M);
    sqr();
    for(int i = 1;i <= t;i ++)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        solve(a, b, c);
    }
    return 0;
}
