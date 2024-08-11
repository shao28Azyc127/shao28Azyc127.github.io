#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=3005;
int n,m;
char a[maxn][maxn];
int num[maxn][26];
char mn[maxn][maxn],mx[maxn][maxn];
char ln[maxn];

bool cmp1(int x)
{
    for(int i=1;i<=m;i++)
        if(mx[x][i]<ln[i]) return true;
        else if(mx[x][i]>ln[i]) return false;
    return false;
}

bool cmp2(int x)
{
    for(int i=1;i<=m;i++)
        if(mn[x][i]<ln[i]) return true;
        else if(mn[x][i]>ln[i]) return false;
    return true;
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) ln[i]='z';
    for(int i=1;i<=n;i++)
        cin>>(a[i]+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            num[i][a[i][j]-'a']++;
        for(int j=1,k=0;j<=m;j++)
        {
            while(!num[i][k]) k++;
            mn[i][j]=char('a'+k);
            num[i][k]--;
        }
        for(int j=1;j<=m;j++)
            mx[i][j]=mn[i][m+1-j];
        if(cmp1(i))
            for(int j=1;j<=m;j++)
                ln[j]=mx[i][j];
/*
        cout<<"#"<<i<<endl;
        for(int j=1;j<=m;j++) cout<<ln[j];
        cout<<endl<<endl;
*/
    }
    for(int i=1;i<=n;i++)
        if(cmp2(i)) printf("1");
        else printf("0");
    return 0;
}
