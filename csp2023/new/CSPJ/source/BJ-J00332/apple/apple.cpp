#include <bits/stdc++.h>
using namespace std;

bool vis[1000005];
int n;
bool check()
{
    for(int i=1;i<=n;i++)
        if(!vis[i])return false;
    return true;
}

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    if(n<=12)
    {
        if(n==1)printf("1 1\n");
        if(n==2)printf("2 2\n");
        if(n==3)printf("3 3\n");
        if(n==4)printf("3 1\n");
        if(n==5)printf("4 4\n");
        if(n==6)printf("4 2\n");
        if(n==7)printf("4 1\n");
        if(n==8)printf("5 5\n");
        if(n==9)printf("5 3\n");
        if(n==10)printf("5 1\n");
        if(n==11)printf("5 2\n");
        if(n==12)printf("6 6\n");
        if(n==13)printf("6 1\n");
        return 0;
    }
    int cnt=0,ans;
    while(!check())
    {
        cnt++;
        int t=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])continue;
            t++;
            if(t==4)t=1;
            if(t==1)
            {
                vis[i]=true;
                if(i==n)ans=cnt;
            }
        }
    }
    printf("%d %d\n",cnt,ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}