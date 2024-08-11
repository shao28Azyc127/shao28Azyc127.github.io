#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct de
{
    int o;
    int r;
};
struct abc
{
    de a;
    de b;
    int c;
};

abc l[100000];
int n,m,k;
queue <de> q;
bool cmp(abc x,abc y)
{
    return x.a.o<y.a.o;
}
void dui(int p)
{
    for(int i=1;i<=m;i++)
    {
        if(l[i].a.o==p)
        {
            l[p].b.r=l[i].a.r+1;
            q.push(l[p].b);
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>l[i].a.o>>l[i].b.o>>l[i].c;
        if(l[i].a.o==1)
        {
            l[i].a.r=k;
        }
    }
    dui(l[1].a.o);
    while(q.front().o!=n)
    {
        de u=q.front();
        q.pop();
        dui(u.o);
    }
    cout<<q.front().r+1;
}
