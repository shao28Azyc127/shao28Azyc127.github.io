#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
char s[3001][3001],ss[3001][3001];
bool cmp(char x[],char y[])
{
    for(int i = 1;i <= m;i++)
    {
        if(x[i] < y[i]) return 1;
        if(x[i] > y[i]) return 0;
    }
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int mx = 0,mxx = 0;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i++) s[0][i] = ss[0][i] = 'z';
    if(n == 1)
    {
        printf("1\n");
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        scanf("%s",s[i]+1);
        sort(s[i]+1,s[i]+1+m);
        for(int j = 1;j <= m;j++)
            ss[i][j] = s[i][m-j+1];
        if(cmp(ss[i],ss[mx]))
        {
            mxx = mx;
            mx = i;
        }
        else if(cmp(ss[i],ss[mxx])) mxx = i;
    }
    for(int i = 1;i <= n;i++)
        if((mx != i && cmp(s[i],ss[mx])) || (mx == i && cmp(s[i],ss[mxx]))) printf("1");
        else printf("0");
    return 0;
}
