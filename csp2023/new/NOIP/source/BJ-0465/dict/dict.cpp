#include<bits/stdc++.h>
using namespace std;
const int N=3010;
char a[N][N],b[N],c[N];
int num[N][30];
inline int read()
{
    int S=0,W=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') W=-1; ch=getchar();}
    while(ch>='0' && ch<='9') S=(S<<1)+(S<<3)+(ch^48),ch=getchar();
    return S*W;
}
int chk(int x,int y) //x<y:1,x>y:0,x=y;2
{
    for(int i=25;i>=0;i--)
    {
        if(num[x][i]<num[y][i]) return 1;
        if(num[x][i]>num[y][i]) return 0;
    }
    return 2;
}
bool chk2(int m)// i,mi
{
    for(int i=1;i<=m;i++)
    {
        if(c[i]<b[i]) return 1;
        if(b[i]<c[i]) return 0;
    }
    return 0;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n=read(),m=read(),mi;
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) num[i][a[i][j]-'a']++;
    mi=1; int cnt=0;
    for(int i=2;i<=n;i++)
        if(chk(i,mi)==1) mi=i;
    for(int i=25;i>=0;i--)
        while(num[mi][i]) b[++cnt]='a'+i,num[mi][i]--; 
    for(int i=1;i<=n;i++)
    {
        if(i==mi) {printf("1"); continue;}
        cnt=0;
        for(int j=0;j<26;j++)
            while(num[i][j]) c[++cnt]='a'+j,num[i][j]--; 
        if(chk2(m)) printf("1");
        else printf("0");
    }
    puts("");
    return 0;
}