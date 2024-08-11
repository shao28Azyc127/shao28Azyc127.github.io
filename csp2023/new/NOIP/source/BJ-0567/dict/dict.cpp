#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=3005;
int n,m;
char a[N][N],maxn[N][N],minn[N][N];
int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
bool cmp1(char x,char y) {return x<y;}
bool cmp2(char x,char y) {return x>y;}
bool check(int pos)
{
    for(int i=1;i<=n;i++)
    {
        if(i==pos) continue;
        bool flag=false;
        for(int j=1;j<=m;j++)
        {
            if(maxn[i][j]>minn[pos][j]) {flag=true;break;}
            if(maxn[i][j]<minn[pos][j]) return false;
        }
        // if(pos==14) cout<<flag;
        if(!flag) return false;
    }
    return true;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
    {
        sort(a[i]+1,a[i]+m+1,cmp1);
        for(int j=1;j<=m;j++) minn[i][j]=a[i][j];
        
    }
    for(int i=1;i<=n;i++)
    {
        sort(a[i]+1,a[i]+m+1,cmp2);
        for(int j=1;j<=m;j++) maxn[i][j]=a[i][j];
        // for(int j=1;j<=m;j++) cout<<maxn[i][j];
        // puts("");
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=0;
        if(check(i)) ans=1;
        printf("%d",ans);
    }
    // puts("");
    return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/