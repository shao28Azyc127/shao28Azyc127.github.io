#include <bits/stdc++.h>
using namespace std;
char a[2000006];
struct _{
    int l,r;
};
vector<_>v;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
    {
        int len=j-i+1;
        if(len%2==0)
        {
            int flag=1;
            for(int k=i;k<=(i+j)/2;k++)
                if(a[k]!=a[i+j-k])
                {
                    //cout<<a[k]<<' '<<a[j-k+1]<<endl;
                    flag=0;
                }

            if(flag)
            {
                //cout<<i<<' '<<j<<endl;
                v.push_back((_){i,j});
            }

        }
    }
    //aa aaaa
    int ans=0;
    ans+=v.size();
    //cout<<ans<<endl;
    for(int i=0;i<v.size();i++)
        for(int j=i+1;j<v.size();j++)
        if(v[i].r+1==v[j].l)
    {
        int flag=1;
        for(int k=0;k<v.size();k++)
            if(v[k].l==v[i].l&&v[k].r==v[j].r)
            flag=0;
        if(flag)
        {
            ans++;
            v.push_back((_){v[i].l,v[j].r});
        }
    }
    cout<<ans;
    return 0;
}

