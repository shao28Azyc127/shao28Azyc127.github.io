#include<bits/stdc++.h>
using namespace std;

int a[500005],b[500005];
int aa[500005],bb[500005];
bool ans[100];
int c,n,m,q;
bool solve()
{
    if(c==1)
    {
        return a[1]!=b[1];
    }
    else if(c==2)
    {
        if(n==1)
        {
            if(m==1)
            {
                return a[1]!=b[1];
            }
            else
            {
                if(a[1]==b[1]||a[1]==b[2])return 0;
                if((a[1]<b[1])^(a[1]<b[2]))return 0;
                else return 1;
            }
        }
        else
        {
            if(m==1)
            {
                if(a[1]==b[1]||a[2]==b[1])return 0;
                if((a[1]<b[1])^(a[2]<b[1]))return 0;
                else return 1;
            }
            else
            {
                if(a[1]==b[1]||a[2]==b[2])return 0;
                    if((a[1]<b[1])^(a[2]<b[2]))return 0;
                    else return 1;
            }   
        }
    }
    else
    {
        return 1;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        aa[i]=a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        bb[i]=b[i];
    }
    ans[0]=solve();
    for(int Case=1;Case<=q;Case++)
    {
        int ka,kb;
        cin>>ka>>kb;
        for(int i=1;i<=n;i++)a[i]=aa[i];
        for(int i=1;i<=m;i++)b[i]=bb[i];
        for(int i=1;i<=ka;i++)
        {
            int p,x;
            cin>>p>>x;
            a[p]=x;
        }
        for(int i=1;i<=kb;i++)
        {
            int p,x;
            cin>>p>>x;
            b[p]=x;
        }
        ans[Case]=solve();
    }
    for(int i=0;i<=q;i++)cout<<ans[i];
    return 0;
}