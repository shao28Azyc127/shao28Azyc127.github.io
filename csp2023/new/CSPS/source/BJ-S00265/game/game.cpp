#include<cstdio>

char a[2000005];
bool f[8005][8005];
int n,ans;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",a);
    for(int i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            f[i][i+1]=1;
            ans++;
        }
    }
    for(int len=4;len<=n;len+=2)
    {
        for(int l=0;l+len-1<n;l++)
        {
            int r=l+len-1;
            if(a[l]==a[r]&&f[l+1][r-1])f[l][r]=1;
            for(int k=l+2;k<=r;k++)
                f[l][r]|=f[l][k-1]&&f[k][r];
            if(f[l][r])ans++;
        }
    }
    printf("%d",ans);
    return 0;
}

