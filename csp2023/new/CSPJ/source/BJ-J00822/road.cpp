#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
#define int long long
struct St
{
    int v;
    int a;
}s[1000010],s2[1000010];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    deque<St> dq;
    s[1].v = 0;
    for(int i = 2; i <= n; i++)
    {
         cin >> s[i].v;
    }
    int minn = 2147483600;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i].a;
    }
    int cur = 0,vv = 0;
    bool f = 0;
    for(int i = 1; i <= n; i++)
    {
        vv += s[i].v;
        if(s[i].a < minn)
        {
            minn = s[i].a;
            s2[++cur].a = minn;
            s2[cur].v = vv;
            //cerr << vv <<endl;
            vv = 0;
            if(i == n) f = 1;
        }
    }
    int m = 0,yx = 0;
    for(int i = 1; i <= cur; i++)
    {
        if(i != cur)
        {
            yx -= s2[i].v;
            //cerr << yx <<endl;
            if((s2[i + 1].v - yx) % d != 0)
            {
                int x = ((s2[i +1].v - yx)/ d + 1);
                yx += ((s2[i +1].v - yx)/ d + 1) * d;
                m += x* s2[i].a;
            }
            else
            {
                int x = s2[i + 1].v - yx;
                yx += s2[i + 1].v - yx;
                m += x / d * s2[i].a;
            }

        }
        else if(!f){
            yx -= s2[i].v;
            //cerr << yx <<endl;
            if((vv - yx) % d != 0)
            {
                int x = ((vv - yx)/ d + 1);
                yx += ((vv - yx)/ d + 1) * d,m += x * s2[i].a;
            }
            else
            {
                int x = vv - yx;
                yx += vv - yx,m += x / d * s2[i].a;
            }

        }
        //cerr << yx <<endl;

    }
    cout << m;
    return 0;
}
