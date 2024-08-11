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

int cnt[3010][30];
int tmpa[30], tmpb[30];
ll n, m;

void cp2a(int a[])
{
    F(i,1,26)
    {
        tmpa[i] = a[i];
    }
}

void cp2b(int a[])
{
    F(i,1,26)
    {
        tmpb[i] = a[i];
    }
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    read(n);
    read(m);
    if(m==1)
    {
        int _min = 114514;
        int ans;
        F(i,1,n)
        {
            string str;
            cin>>str;
            if(str[0] < _min){
                _min = str[0];
                ans = i;
            }
        }
        F(i,1,n) {
            if(i == ans) {
                printf("1");
            }
            else printf("0");
        }
        printf("\n");
        return 0;
    }
    F(i,1,n)
    {
        string str;
        cin>>str;
        F(j,0,m-1)
        {
            cnt[i][str[j] - 'a' + 1]++;
        }
    }
    F(i,1,n)
    {
        bool flag = true;
        F(j,1,n)
        {
            if(i==j)continue;
            int _mina=114514, _maxb=0;
            cp2a(cnt[i]);
            cp2b(cnt[j]);
            F(k,1,26)
            {
                if(tmpa[k])
                {
                    _mina = min(_mina, k);
                }
                if(tmpb[k])
                {
                    _maxb = max(_maxb, k);
                }
            }
            if(_mina<_maxb)
            {
                continue;
            }
            _mina=114514, _maxb=0;
            F(k,1,26)
            {
                int minnum;
                minnum = min(tmpa[k], tmpb[k]);
                tmpa[k] -= minnum;
                tmpb[k] -= minnum;
            }
            F(k,1,26)
            {
                if(tmpa[k])
                {
                    _mina = min(_mina, k);
                }
                if(tmpb[k])
                {
                    _maxb = max(_maxb, k);
                }
            }
            if(_mina>_maxb)
            {
                flag = false;
                break;
            }
        }
        if(flag) printf("1");
        else printf("0");
    }
    printf("\n");
    return 0;
}
