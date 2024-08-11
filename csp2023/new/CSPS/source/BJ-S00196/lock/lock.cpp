#include<cstdio>
using namespace std;

int n,a[10][10],mid[10],ans=0;



int v(int x)
{
    if(x>=10)
    {
        return x%10;
    }
    else if(x<0)
    {
        return 10+x;
    }
    else
    {
        return x;
    }
}


bool al(int nk)
{
    int l=-1,r=-1,cnt=1;
    for(int i=1;i<=5;i++)
    {
        if(a[nk][i]!=mid[i])
        {
            switch(cnt)
            {
                case 1:
                    l=i;
                    cnt++;
                    break;
                case 2:
                    r=i;
                    cnt++;
                    break;
                case 3:
                    return false;
            }
        }
    }
    if(l==-1)
    {
        return false;
    }
    if(r==-1)
    {
        return true;
    }
    if(r-l+1>2)
    {
        return false;
    }
    if(v(a[nk][l]-mid[l])==v(a[nk][r]-mid[r]))
    {
        return true;
    }
    return false;
}


/*
2 8 3 5 5
2 6 5 2 0
*/

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            scanf("%d",&a[i][j]);
        }

    }
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=9;j++)
        {
            for(int k=1;k<=5;k++)
            {
                mid[k]=a[1][k];
            }
            mid[i]=v(mid[i]+j);
            bool flag=true;
            for(int k=2;k<=n;k++)
            {
                if(!al(k))
                {
                    flag=false;
                }
            }
            if(flag)
            {
                ans=ans+1;
            }
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=9;j++)
        {
            for(int k=1;k<=5;k++)
            {
                mid[k]=a[1][k];
            }
            mid[i+1]=v(mid[i+1]+j);
            mid[i]=v(mid[i]+j);
            bool flag=true;
            for(int k=2;k<=n;k++)
            {
                if(!al(k))
                {
                    flag=false;
                }
            }
            if(flag)
            {
                ans=ans+1;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
