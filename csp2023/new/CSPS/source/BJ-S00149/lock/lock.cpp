#include<bits/stdc++.h>
using namespace std;
int n,a[10],f[10][1005][6],len[10],ans;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            scanf("%d",&a[j]);
        }
        for(int j=1;j<=5;j++)
        {
            for(int t=0;t<=9;t++)
            {
                if(a[j]==t) continue;
                bool flag;
                if(j!=5) flag=(t+a[j+1]-a[j]+10)%10<a[j+1];
                len[i]++;
                for(int k=1;k<=5;k++) f[i][len[i]][k]=a[k];
                f[i][len[i]][j]=t;
                if(j==5) continue;
                if(flag) f[i][len[i]][j+1]=(t+a[j+1]-a[j]+10)%10;
                len[i]++;
                for(int k=1;k<=5;k++) f[i][len[i]][k]=a[k];
                f[i][len[i]][j]=t;
                if(!flag) f[i][len[i]][j+1]=(t+a[j+1]-a[j]+10)%10;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int t=1;t<=len[i];t++)
        {
            for(int j=1;j<len[i];j++)
            {
                for(int k=1;k<=5;k++)
                {
                    if(f[i][j][k]>f[i][j+1][k])
                    {
                        int tmp;
                        for(int l=1;l<=5;l++)
                        {
                            tmp=f[i][j][l];
                            f[i][j][l]=f[i][j+1][l];
                            f[i][j+1][l]=tmp;
                        }
                        break;
                    }
                    if(f[i][j][k]<f[i][j+1][k]) break;
                }
            }
        }
    }
    if(n==1)
    {
        cout<<len[1];
        return 0;
    }
    bool flag=1;
    while(flag)
    {
        for(int i=1;i<=n;i++)
        {
            int s[10],cnt=0,t;
            t=i;
            for(int j=1;j<=5;j++)
            {
                s[j]=f[i][len[i]][j];
            }
            for(int j=i+1;j<=n;j++)
            {
                int k;
                for(k=1;k<=5;k++)
                {
                    if(f[j][len[j]][k]<s[k])
                    {
                        --len[t];
                        t=j;
                        for(int l=1;l<=5;l++)
                        {
                            s[l]=f[j][len[j]][l];
                        }
                        break;
                    }
                    else if(f[j][len[j]][k]>s[k])
                    {
                        --len[j];
                        break;
                    }
                }
                if(k>5)
                {
                    cnt++;
                }
            }
            if(cnt==n-1)
            {
                ans++;
                for(int j=1;j<=n;j++)
                {
                    len[j]--;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!len[i])
            {
                flag=0;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
