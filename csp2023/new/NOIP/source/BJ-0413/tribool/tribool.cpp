#include<bits/stdc++.h>
#define ll long long
#ifdef llfor
#define F(a,b,c) for(ll a=b;a<=c;a++)
#define f(a,b,c) for(ll a=b;a>=c;a--)
#else
#define F(a,b,c) for(int a=b;a<=c;a++)
#define f(a,b,c) for(int a=b;a>=c;a--)
#endif // llfor
#define FA_T 100001
#define FA_F 100002
#define FA_U 100003
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

struct node
{
    char type;
    int fa;
} result[100010];

int c,q;
ll n,m;
bool vis[100010];

int getfa(int x)
{
    if(vis[x]) return result[x].fa;
    vis[x] = true;
    if(x!=result[x].fa)
    {
        return result[x].fa = getfa(result[x].fa);
    }
    return x;
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    result[100001].type = 'T';
    result[100001].fa = 100001;
    result[100002].type = 'F';
    result[100002].fa = 100002;
    result[100003].type = 'U';
    result[100003].fa = 100003;
    read(c);
    read(q);
    while(q--)
    {
        memset(vis, 0, sizeof(vis));
        read(n);read(m);
        F(i,1,n)
        {
            result[i].type = '?';
            result[i].fa = 0;
        }
        F(i,1,m)
        {
            char ch;
            scanf("%c", &ch);
            if(ch == 'T' || ch == 'U' || ch == 'F')
            {
                int p;
                read(p);
                result[p].type = ch;
                if(result[p].type == 'U') result[p].fa = FA_U;
                if(result[p].type == 'T') result[p].fa = FA_T;
                if(result[p].type == 'F') result[p].fa = FA_F;
                continue;
            }
            if(ch == '-' || ch == '+')
            {
                int p,q;
                read(p);
                read(q);
                result[p].type = ch;
                result[p].fa = q;
            }
        }
        if(c == 3 || c == 4)
        {
            ll ans = 0;
            F(i,1,n)
            {
                if(result[i].type == 'U') ans++;
            }
            printf("%lld\n", ans);

        }
        else
        {
            ll ans = 0;
            F(i,1,n)
            {
                if(!result[i].fa) continue;
                if(getfa(i) == FA_U) ans++;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
