#include<iostream>
#include<cstdio>
#define rep(i) for(int i=0;i<=9;i++)
using namespace std;
int n,m,i,j,k,ans;
int f[10][6];
bool same(int x,int y,int xx,int yy)
{
    //use add
    int add,add2;
    if(yy<xx) add=10-xx+yy;
    else add=yy-xx;
    if(y<x) add2=10-x+y;
    else add2=y-x;
    return add==add2;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=5;j++) cin>>f[i][j];
    int a,b,c,d,e;
    for(a=0;a<=9;a++)
    for(b=0;b<=9;b++)
    for(c=0;c<=9;c++)
    for(d=0;d<=9;d++)
    for(e=0;e<=9;e++)
    {
        int diff=0;
        bool no=0;
        for(int i=1;i<=n;i++)
        {
            diff=0;
            diff+=((f[i][1]!=a)+(f[i][2]!=b)+(f[i][3]!=c)+(f[i][4]!=d)+(f[i][5]!=e));
            if(diff>2)
            {
                no=1;
                break;
            }
            if(diff==1) continue;
            if(f[i][1]!=a&&f[i][2]!=b&&same(f[i][1],a,f[i][2],b)||
               f[i][2]!=b&&f[i][3]!=c&&same(f[i][2],b,f[i][3],c)||
               f[i][3]!=c&&f[i][4]!=d&&same(f[i][3],c,f[i][4],d)||
               f[i][4]!=d&&f[i][5]!=e&&same(f[i][4],d,f[i][5],e)) continue;
            no=1;break;
        }
        if(!no) ans++;
    }
    cout<<ans;
    return 0;
}
//florr&M28 bless me AC!!!
