#include<bits/stdc++.h>
using namespace std;
const int N=3005;
char s[N][N];
int n,m,cnt[N],mx[N],mi[N];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf(" %s",s[i]+1);
    for(int i=1;i<=n;i++)
    {
        mx[i]=-1,mi[i]=100;
        for(int j=1;j<=m;j++)
        {
            mx[i]=max(mx[i],s[i][j]-'a');
            mi[i]=min(mi[i],s[i][j]-'a');
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(mi[i]<mx[j])cnt[i]++;
            if(mi[j]<mx[i])cnt[j]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]==n-1)putchar('1');
        else putchar('0');
    }
    putchar('\n');
    return 0;
}
