#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool vis[1000005];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
        vis[i]=true;
    }
    int y=n,sum=0,ans=0,nn=0,f=0;
    while(y!=0)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
            {
                if(ans==0)
                {
                    if(a[i]==n)
                    {
                        nn++;
                        f=1;
                    }
                    vis[i]=false;
                    y--;
                }
                if(ans==2)
                {
                    ans=0;
                    continue;
                }
                ans++;
            }


        }
        sum++;
        if(!f)
        {
            nn++;
        }
    }
    cout<<sum<<" "<<nn;
    return 0;
}