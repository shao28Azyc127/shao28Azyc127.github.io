#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll vis[200000010];

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ll n,cnt=0,res=2,ans=0,u;
    cin>>n;
    //cout<<n<<endl;
    memset(vis,0,sizeof(vis));
    if(n%3!=1)
    {
        while(cnt<n)
        {
            ans++;
            res=2;
            ll flag=0;
            for(ll i=1;i<=n;i++)
            {
                //cout<<1<<endl;
                if(res==2)
                {
                    while(vis[i]==1)
                    {
                        i++;
                    }
                    if(vis[i]==0)
                    {
                        vis[i]=1;
                        if(i==n)    u=ans;
                        //cout<<i<<" ";
                        cnt++;
                        res=0;
                    }


                }
                else if(vis[i]==0)
                     {
                         res++;
                     }
            }
            //cout<<cnt<<endl;
        }
        cout<<ans<<" "<<u<<endl;
    }
    else
    {
        while(n/3!=0)
        {
            //cout<<n<<endl;
            ans++;
            if(n%3==0)
                n-=ceil(n/3);
            else
                n-=(n/3+1);
        }
        ans+=n;
        cout<<ans<<" "<<1<<endl;
    }

    return 0;
}
