#include <bits/stdc++.h>
using namespace std;
const int MAXN=3005;
char s[MAXN][MAXN];
int buc[MAXN][150];
int f[MAXN],g[MAXN];
int flag[MAXN];
int N,M;
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++)
    {
        scanf("%s",s[i]+1);
        for(int j=1;j<=M;j++) buc[i][s[i][j]]++;
        flag[i]=1;
    }
    for(int i=1;i<=M;i++) f[i]='z'+1;
    for(int i=1;i<=N;i++)
    {
        int ind=0;
        for(int j='a';j<='z';j++)
        {
            for(int k=1;k<=buc[i][j];k++) g[++ind]=j;
        }
        for(int j=1;j<=M;j++)
        {
            if(f[j]>g[j]) break;
            if(f[j]<g[j]) flag[i]=0;
            if(f[j]==g[j]&&flag[i]&&j==M) flag[i]=0;
        }
      /*  for(int j=1;j<=M;j++) printf("[%d]",f[j]);
        puts("");
        for(int j=1;j<=M;j++) printf("[%d]",g[j]);
        puts("");
        printf("Flag:%d\n",flag[i]);*/
        ind=0;
        for(int j='z';j>='a';j--)
        {
            for(int k=1;k<=buc[i][j];k++) g[++ind]=j;
        }
        for(int j=1;j<=M;j++)
        {
            f[j]=min(f[j],g[j]);
        }
    }
    for(int i=1;i<=M;i++) f[i]='z'+1;
    for(int i=N;i;i--)
    {
        int ind=0;
        for(int j='a';j<='z';j++)
        {
            for(int k=1;k<=buc[i][j];k++) g[++ind]=j;
        }
        for(int j=1;j<=M;j++)
        {
            if(f[j]>g[j]) break;
            if(f[j]<g[j]) flag[i]=0;
            if(f[j]==g[j]&&flag[i]&&j==M) flag[i]=0;
        }
       /* for(int j=1;j<=M;j++) printf("[%d]",f[j]);
        puts("");
        for(int j=1;j<=M;j++) printf("[%d]",g[j]);
        puts("");
        printf("Flag:%d\n",flag[i]);*/
        ind=0;
        for(int j='z';j>='a';j--)
        {
            for(int k=1;k<=buc[i][j];k++) g[++ind]=j;
        }
        for(int j=1;j<=M;j++)
        {
            f[j]=min(f[j],g[j]);
        }
    }
    for(int i=1;i<=N;i++) printf("%d",flag[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}