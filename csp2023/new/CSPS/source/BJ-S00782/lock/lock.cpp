#include <bits/stdc++.h>
using namespace std;

int read()
{
    int x=0,f=1;
    char c=getchar();
    while (!isdigit(c))
    {
        if (c=='-')
        {
            f=-1;
        }
        c=getchar();
    }
    while (isdigit(c))
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
const int maxn=10;
int rad[maxn][6];
int all[10][100][6];
string alls[10][100];
int n;
int cnt1=0;
bool check(int j,string s)
{
    bool flag=false;
    for (int i=1;i<=81;i++)
    {
        if (alls[j][i]==s)
        {
            return true;
        }
    }
    return flag;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    n=read();
    if (n==1)
    {
        cout << 81;
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=5;j++)
        {
            rad[i][j]=read();
        }
    }
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        cnt=0;
        for (int j=1;j<=2;j++)
        {
            if (j==1)
            {
                for(int k=1;k<=5;k++)
                {
                    for (int y=1;y<=9;y++)
                    {
                        cnt++;
                        for (int x=1;x<=5;x++)
                        {
                            if (x!=k)
                            {
                                all[i][cnt][x]=rad[i][x];
                            }
                            else
                            {
                                all[i][cnt][x]=(rad[i][x]+y)%10;
                            }
                        }
                    }
                }
            }
            if (j==2)
            {
                for (int k=1;k<=4;k++)
                {
                    for (int y=1;y<=9;y++)
                    {
                        cnt++;
                        for (int x=1;x<=5;x++)
                        {
                            if (x!=k&&x!=k+1)
                            {
                                all[i][cnt][x]=rad[i][x];
                            }
                            else
                            {
                                all[i][cnt][x]=(rad[i][x]+y)%10;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=cnt;j++)
        {
            for (int k=1;k<=5;k++)
            {
                alls[i][j]+=char(all[i][j][k]+'0');
            }
        }
    }
    for (int i=1;i<=81;i++)
    {
        bool flag1=true;
        for (int j=2;j<=n;j++)
        {
            if (!check(j,alls[1][i]))
            {
                flag1=false;
                break;
            }
        }
        if (flag1)
        {
            cnt1++;
        }
    }
    cout << cnt1;
    return 0;
}
