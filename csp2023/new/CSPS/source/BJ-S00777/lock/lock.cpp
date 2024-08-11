#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,a[10],vis[100005],ans,k=1,mark=0;
int weishu(int x,int k)
{
    for(int i=1;i<=k-1;i++)
    {
        x/=10;
    }
    x%=10;
    return x;
}
void check(int x)
{
    for(int i=0;i<=99999;i++)
    {
        if(i==x)
        {
            vis[i]++;
            continue;
        }
        for(int j=1;j<=5;j++)
        {
            if(weishu(x,j)==weishu(i,j)) continue;
            else if(!mark&&(weishu(x,j)-weishu(i,j)+10)%10==(weishu(x,j+1)-weishu(i,j+1)+10)%10)
            {
                mark++;
                j++;
                continue;
            }
            else vis[i]++;
        }
        mark=0;
        int t=i-x;
        while(abs(t)%10==0)
        {
            t/=10;
            k++;
        }
        if((-weishu(x,k)<=t)&&(t<=9-weishu(x,k)))
        {
            vis[i]--;
        }
        k=1;
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            int p;
            cin>>p;
            a[i]*=10;
            a[i]+=p;
        }
        check(a[i]);
    }
    for(int i=0;i<=99999;i++)
    {
        if(vis[i]<=0)
        {
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}