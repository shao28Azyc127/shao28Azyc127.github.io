#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
struct var
{
    bool ifreversed;
    int stat;//-3=T,-2=F,-1=U,i=x[i]
    var() {ifreversed=0,stat=0;}
    void print()
    {
        cout << ifreversed << ' ';
        if(stat==-3)
            cout << 'T';
        else if(stat==-2)
            cout << 'F';
        else if(stat==-1)
            cout << 'U';
        else if(stat>=1)
            cout << "a[" << stat << ']';
        cout << endl;
    }
};
int n,m,ans,tests;
var a[200005];
int f[200005];
int determined[200005];
inline var makevar(bool ifreversed,int stat)
{
    var vv;
    vv.ifreversed=ifreversed,vv.stat=stat;
    return vv;
}
inline int rev(int x)
{
    if(x==-3)
        x=-2;
    else if(x==-2)
        x=-3;
    return x;
}
inline int find(int x)
{
    if(f[x]==x)
        return x;
    return (f[x]=find(f[x]));
}
inline void add_same(int x,int y)
{
    f[find(y)]=find(x);
    f[find(y+n)]=find(x+n);
    return;
}
inline void add_diff(int x,int y)
{
    f[find(y)]=find(x+n);
    f[find(y+n)]=find(x);
    return;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >> ans >> tests;
    while(tests--)
    {
        ans=0;
        cin >> n >> m;
        for(register int i=1;i<=n;i++)
            a[i]=makevar(0,i);
        for(register int i=1;i<=2*n;i++)
        {
            f[i]=i;
            determined[i]=0;
        }
        for(register int i=1;i<=m;i++)
        {
            char opt;
            int x,y;
            cin >> opt;
            if(opt=='T' || opt=='F' || opt=='U')
            {
                cin >> x;
                if(opt=='T')
                    a[x]=makevar(0,-3);
                if(opt=='F')
                    a[x]=makevar(0,-2);
                if(opt=='U')
                    a[x]=makevar(0,-1);
            }
            else
            {
                cin >> x >> y;
                if(a[y].stat==-1 || a[y].stat==-2 || a[y].stat==-3)
                {
                    if(opt=='+')
                        a[x]=makevar(0,a[y].stat);
                    else
                        a[x]=makevar(0,rev(a[y].stat));
                }
                else
                {
                    if(opt=='+')
                        a[x]=a[y];
                    else
                        a[x]=makevar(!a[y].ifreversed,a[y].stat);
                }
            }
        }
        /*
        for(register int i=1;i<=n;i++)
            a[i].print();
        cout << endl;
        //*/
        for(register int i=1;i<=n;i++)
        {
            if(a[i].stat>=1)
            {
                if(a[i].ifreversed)
                    add_diff(i,a[i].stat);
                else
                    add_same(i,a[i].stat);
            }
        }
        for(register int i=1;i<=n;i++)
        {
            if(a[i].stat<=-1)
            {
                determined[find(i)]=a[i].stat;
                determined[find(i+n)]=rev(a[i].stat);
            }
        }
        for(register int i=1;i<=n;i++)
        {
            if(find(i)==find(i+n))
                determined[find(i)]=-1;
        }
        for(register int i=1;i<=n;i++)
        {
            if(determined[find(i)]<0)
                determined[i]=determined[find(i)];
            else if(determined[find(i+n)]<0)
                determined[i]=rev(determined[find(i+n)]);
        }
        for(register int i=1;i<=n;i++)
            if(determined[i]==-1)
                ans++;
        cout << ans << endl;
    }
    return 0;
}
