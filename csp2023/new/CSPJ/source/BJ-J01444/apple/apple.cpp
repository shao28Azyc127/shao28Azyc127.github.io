#include<bits/stdc++.h>
int a[1000000010];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int p=0,n,day=0,ans;
    scanf("%d",n);
    for(int i=1;i<=n;i++)
        a[i]=1;
    while(p<n)
    {
        int j=2;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=0);
               j++;
            if(j==3)
            {
                a[i]=0;
                p++;
            }
        }
        if(a[n]==0)
            ans=day;
        day++;
    }
    printf("%d",day);
    printf("%d",ans);
    return 0;
}
