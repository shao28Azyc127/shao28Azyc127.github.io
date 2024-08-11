#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e4 + 5;
int T, m, n, pri[N], a, b, c;
bool prime[N];

inline int gcd(int x, int y){x=x<0?-x:x;y=y<0?-y:y;if(x<y){swap(x,y);}while(y){x=x%y;if(x<y){swap(x,y);}}return x;}

inline int sq(int x)
{
    int res = 1;
    for(register int i = 1;i <= n && pri[i] * pri[i] <= x && x > 1;i++)
        while(x > 1 && x % (pri[i] * pri[i]) == 0)
            res *= pri[i], x /= (pri[i] * pri[i]);
    return res;
}

inline void pre()
{
    for(register int i = 2;i <= 10000;i++)
    {
        if(prime[i])
            continue;
        pri[++n] = i;
        for(register int j = i + i;j <= 10000;j += i)
            prime[j] = true;
    }
    return ;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    pre();
    scanf("%d %d", &T, &m);
    while(T--)
    {
        scanf("%d %d %d", &a, &b, &c);
        int Delt = b * b - 4 * a * c;
        if(Delt < 0)
        {
            printf("NO\n");
            continue;
        }
        int m1 = -b, z1 = a + a;
        if(z1 < 0)  z1 = -z1, m1 = -m1;
        int m2 = 1, z2 = a + a;
        if(z2 < 0)  z2 = -z2;
        if(m2 < 0)  m2 = -m2;
        int S = sq(Delt);
        m2 *= S;
        Delt /= S * S;
        if(Delt == 1)
            m1 += m2;
        int G1 = gcd(m1, z1);
        m1 /= G1, z1 /= G1;
        int G2 = gcd(m2, z2);
        m2 /= G2, z2 /= G2;
        if(Delt == 1)
        {
            printf("%d", m1);
            if(z1 != 1)
                printf("/%d", z1);
            printf("\n");
            continue;
        }
        bool flag = false;
        if(m1 != 0)
        {
            printf("%d", m1);
            if(z1 != 1)
                printf("/%d", z1);
            flag = true;
        }
        if(Delt != 0)
        {
            if(flag)
                printf("+");
            if(m2 != 1)
                printf("%d*", m2);
            if(Delt != 1)
                printf("sqrt(%d)", Delt);
            if(z2 != 1)
                printf("/%d", z2);
        }
        if(m1 == 0 && Delt == 0)
            printf("0");
        printf("\n");
    }
    return 0;
}
