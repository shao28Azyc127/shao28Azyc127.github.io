#include<bits/stdc++.h>
#define ll long long
#ifdef llfor
#define F(a,b,c) for(ll a=b;a<=c;a++)
#define f(a,b,c) for(ll a=b;a>=c;a--)
#else
#define F(a,b,c) for(int a=b;a<=c;a++)
#define f(a,b,c) for(int a=b;a>=c;a--)
#endif // llfor
using namespace std;

template<typename T>
void read(T& x)
{
    char ch=getchar();
    int _f=1;
    x=0;
    for(; ch<'0'||ch>'9'; ch=getchar())if(ch=='-') _f=-1;
    for(; ch>='0'&&ch<='9'; ch=getchar())
    {
        x*=10;
        x+=ch-48;
    }
    x*=_f;
}

ll c, t;
ll n,m,k,d;
ll ans;

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    read(c);
    read(t);
    while(t--)
    {
        ans = 0;
        read(n);
        read(m);
        read(k);
        read(d);
        F(i,1,m)
        {
            ll x,y,v;
            read(x);
            read(y);
            read(v);
            if(y>k) continue;
            ans = max(ans, ans-d*y+v);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
