#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int N=10;
const int INF=0x3f3f3f3f;

int a[N], n, b[N][N];
int res=0;
int d[6];
int test=0;

void calc()
{
    bool add=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=5;j++) d[j]=a[j]-b[i][j];
        if (d[1]==0 && d[2]==0 && d[3]==0 && d[4]==0 && d[5]==0)
        {
            add=false;
            break;
        }

        int flag=0;
        while (d[flag+1]==0) flag++;
        int yu=6;
        while (d[yu-1]==0) yu--;
        int t=d[flag+1];
        bool op=1;
        if ((yu-1-flag)>2)
        {
            add=false;
            break;
        }
        for (int j=flag+1;j<yu;j++)
        {
            if (t!=d[j] && t!=d[j]+10)
            {
                op=0;
                break;
            }
        }
        if (!op)
        {
            add=false;
            break;
        }
    }
    if (add)
    {
        res++;
    }
}

void dfs(int lvl)
{
    if (lvl==5)
    {
        calc();
        return ;
    }

    for (int i=0;i<10;i++)
    {
        a[lvl+1]=i;
        dfs(lvl+1);
        a[lvl+1]=0;
    }

}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=5;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }

    dfs(0);
    printf("%d",res);
    return 0;
}
