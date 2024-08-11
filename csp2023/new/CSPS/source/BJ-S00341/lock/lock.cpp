#include<bits/stdc++.h>

using namespace std;

int n;
int a[20][10];
int b[10];
int tong[10];
int diff[10];
int diffnum[5];
int twodiff;
int ans;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    if (n==1)
    {
        cout<<81;
        return 0;
    }
    /*
    for(int j=1;j<=5;j++) //»ñÈ¡diff/twodiff
    {
        for(int i=0;i<=9;i++)
        {
            tong[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            tong[a[i][j]]++;
        }
        for(int i=0;i<=9;i++)
        {
            if (tong[i]) diff[j]++;
        }
        if (diff[j]>=2) twodiff++;
    }
    */

    for(b[1]=0;b[1]<=9;b[1]++)
    {
        for(b[2]=0;b[2]<=9;b[2]++)
        {
            for(b[3]=0;b[3]<=9;b[3]++)
            {
                for(b[4]=0;b[4]<=9;b[4]++)
                {
                    for(b[5]=0;b[5]<=9;b[5]++)
                    {
                        bool ok=1;
                        for(int i=1;i<=n;i++)
                        {
                            twodiff=0;
                            for(int j=1;j<=5;j++)
                            {
                                if (a[i][j]!=b[j])
                                {
                                    diffnum[++twodiff]=j;
                                }
                            }
                            if (twodiff==1)
                                continue;

                            if (twodiff>=3) ok=0;
                            //twodiff==2:
                            if (abs(diffnum[1]-diffnum[2])!=1)
                                ok=0;
                            if (a[i][diffnum[1]]-a[i][diffnum[2]]!=b[diffnum[1]]-b[diffnum[2]])
                                ok=0;
                        }
                        ans+=ok;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
