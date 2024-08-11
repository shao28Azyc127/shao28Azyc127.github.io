#include<bits/stdc++.h>
using namespace std;
char a[10000];
char al[10000];
int lb(int q,int z)
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    for(int i=q;i<=z;i++)
        al[i]=1;
    int p=0,s=0,zc=z-q;
    while(s<=zc)
    {
        int pd=s;
        char h=q;
        for(int i=q+1;i<=z;i++)
        {
            if(a[i]=a[h]&&a[i])
            {
                a[i]=0;
                a[h]=0;
                h=0;
                s++;
            }
            else if(a[i])
                h=i;
        }
        if(pd==s)
            return 0;
    }
    return 1;
}
int main()
{
    int n,m,ans=0;
    scanf("%d",&n);
    for(int i=i;i<=n;i++)
    {
        scanf("%s",&a[i]);
printf("%s",a[i]);
    }
    for(int i=2;i<=n;i+=2)
        for(int j=1;j+n<=10000;j++)
            if(lb(j,j+i))
                ans++;
    if(ans==0)
        for(int i=1;i+2<=n;i+=2)
            ans+=i;
    printf("%d",ans);
}
