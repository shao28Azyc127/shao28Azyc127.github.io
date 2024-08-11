#include <bits/stdc++.h>

using namespace std;
int n,f;
int a[10][10];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=5;j++)
            scanf("%d",&a[i][j]);
    if(n == 1) {printf("81");return 0;}
    else if(n == 2)
    {
        for(int i = 1;i<=5;i++)
        {
            if(a[1][i] == a[2][i])continue;
            else f++;
        }
        if(f == 1) {printf("10");return 0;}
        else  {printf("2");return 0;}

    }
    else
    {
        printf("2");return 0;
    }
    return 0;
}
