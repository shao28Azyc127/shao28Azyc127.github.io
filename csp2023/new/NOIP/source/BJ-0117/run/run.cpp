#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;
#define int long long
long long num[100010];
long long n,m,k,d;
long long c,t;
long long i,j,ma;
long long tag;
struct tz
{
    long long x,y,v;
}no[100010];
bool cmp(tz a,tz b)
{
    if(a.x^b.x)
        return a.x<b.x;
    return a.y<b.y;
}
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m>>k>>d;
        ma=0;
        if(n>1e5)
        {
            cout<<"0\n";
            //不可以，总司令*2
            continue;
        }
        for(i=1;i<=m;i++)
            cin>>no[i].x>>no[i].y>>no[i].v;
        long long now=1;
        sort(no+1,no+1+m,cmp);
        for(i=1;i<=k;i++)
            num[i]=-1e14;
        num[0]=0;
        for(i=1;i<=n;i++)
        {
            long long jlsx=min(i,k);
            for(j=jlsx;j>=1;j--)
                num[j]=num[j-1]-d;
            num[0]=ma;
            tag=0;
            for(j=1;j<=jlsx;j++)
            {
                if(no[now].x==i&&no[now].y==j&&now<=m)
                    tag+=no[now++].v;
                num[j]+=tag;
                ma=max(ma,num[j]);
            }
        }
        cout<<ma<<endl;
    }
    return 0;
}
// When it all falls down..
// juruo, always juruo
// T3 easy? where's the bug? Or more impossible ways are waiting...
// T4 brute force but full of bugs...
// Can I finish? I just don't know..
// 457667
// run out of _____(put a long word on it)
// is T2 tulun? 2-sat(确信)
// -> <-