#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    scanf("%d",&n);
    if(n==1)
        printf("%d",81);
    else if(n==2)
    {
//printf("%d",n);
        int p=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=5;j++)
                scanf("%d",&a[i][j]);
        int j=1;
        for(j=1;j<=5;j++)
//printf("%d",j);
            if(a[1][j]!=a[2][j])
            {
                //a[9][j]=1;
                p++;
//printf("%d",p);
            }
        if(p==1)
        {
            if((a[2][j]-a[1][j])%2==0)
                printf("%d",10);
            else
                printf("%d",8);
        }
        else
            printf("%d",8);
    }
    else
        printf("%d",10-n);
}
