#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;

bool sqr[5000010];
int nsqrt[5000010];

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, M;
    cin >> T >> M;

    for(int i = 1;i <= M*M*5;i++) nsqrt[i] = 1;
    for(int i = 0;i * i <= M*M*5;i++)
    {
        sqr[i*i] = 1;
        nsqrt[i*i] = i;
    }
    for(int i = 1;i * i <= M*M*5;i++)
    {
        if(!sqr[i])continue;
        for(int j = 1;j * i <= M*M*5;j++)
        {
            if(sqr[j])continue;
            nsqrt[j * i] = nsqrt[j] * nsqrt[i];
        }
    }
    //for(int i = 0;i <= M*M*5;i++) cout << i << " " << nsqrt[i] << "\n";
    while(T--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int delta = b*b - 4*a*c;
        //cout << delta << " " << nsqrt[delta] << " ";
        if(delta < 0) puts("NO");
        else
        {
            if(sqr[delta])
            {
                int p;
                if(a > 0)
                    p = -b + nsqrt[delta];
                else p = -b - nsqrt[delta];
                int q = 2 * a;
                bool f = 0;
                if(p < 0) p = -p, f = !f;
                if(q < 0) q = -q, f = !f;
                int gcd = __gcd(p,q);
                p/=gcd;q/=gcd;
                if(p != 0 && f) printf("-");
                if(q == 1) printf("%d\n",p);
                else printf("%d/%d\n",p, q);
            }
            else{
                int p = -b; int q = 2*a;
                if(p != 0)
                {
                    bool f = 0;
                    if(p < 0) p = -p, f = !f;
                    if(q < 0) q = -q, f = !f;
                    int gcd = __gcd(p,q);
                    p/=gcd;q/=gcd;
                    if(f) printf("-");
                    if(q == 1) printf("%d+",p);
                    else printf("%d/%d+",p, q);
                }
                int x = delta / (nsqrt[delta]*nsqrt[delta]);
                p = nsqrt[delta];q = abs(2*a);
                bool f = 0;
                int gcd = __gcd(p,q);
                p/=gcd;q/=gcd;
                if(q == 1)
                {
                    if(p == 1) printf("sqrt(%d)\n",x);
                    else printf("%d*sqrt(%d)\n",p,x);
                }
                else{
                    if(p == 1) printf("sqrt(%d)/%d\n",x,q);
                    else printf("%d*sqrt(%d)/%d\n",p,x,q);
                }
            }
        }
    }
    return 0;
}
