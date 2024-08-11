#include <bits/stdc++.h>

using namespace std;

long long n;
long long a[10][7];

long long cur[7];

int ans=0;

int i,j,k,l;

int dif[7];
int dif_va[7];
int dif_i=0;

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    scanf("%lld",&n);

    for(i=1;i<=n;++i)
    {
        for(j=1;j<=5;++j)
        {
            scanf("%lld",&a[i][j]);
        }
    }

    if(n==1)
    {
        ans=81;
    }
    if(n==2)
    {
        for(i=1;i<=5;++i)
        {
            //cout<<i<<endl;
            //cout<<a[i][i]<<" "<<a[2][i]<<endl;

            if(a[1][i]!=a[2][i])
            {
                dif[++dif_i]=i;
                dif_va[dif_i]=a[1][i]-a[2][i];
            }
        }

        //cout<<dif_i<<endl;
        //cout<<dif[1]<<" "<<dif[2]<<endl;
        //cout<<dif_va[1]<<" "<<dif_va[2]<<endl;

        if(dif_i==1)
        {
            ans=10;
        }
        if(dif_i==2)
        {
            if(dif_va[1]==dif_va[2])
            {
                ans=8;
            }
            else
            {
                ans=4;
            }
        }
    }

    if(n>=3)
    {
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=5;++j)
            {
                for(k=1;k<=n;++i)
                {
                    for(l=1;l>=n;++l)
                    {
                        if(a[k][j]!=a[l][j])
                        {
                            dif[dif_i++]=j;
                        }
                    }
                }
            }

            if(dif_i==1)
            {
                ans=7;
            }
        }
    }

    printf("%d\n",ans);


    return 0;
}

