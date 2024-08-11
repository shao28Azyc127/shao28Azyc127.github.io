#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sheng=0,n,d,v[100001],a[100001],ji[100001],jj=2,ans=0,li[100001];
    freopen("road.in","r",stdin);
    freopen("csp-j/road.out","w",stdout);
    cin>>n>>d;
    ji[1]=1;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];

    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int j=1;
        if(a[j]>a[i])
        {
            ji[jj]=i;
            j=i;
            jj++;
        }
    }
    if(ji[jj-1]!=n)
    {
        ji[jj]=n;
    }
    for(int i=1;i<=jj;i++)
    {
        li[i]=0;
        for(int j=ji[i];j<ji[i+1];j++)
        {
            if(j==ji[i+1])
            {
                break;
            }
            li[i]+=v[j];
        }
    }
    for(int i=1;i<=jj;i++)
    {
        int fl=1;

        int mai=(li[i]-sheng);
        if(mai<0)
        {
            mai=0;
            fl=0;
        }
        mai=mai/d;
        if(((li[i]-sheng)%d)!=0&&fl==1)
        {
            mai++;
        }
        ans+=mai*a[ji[i]];
        sheng=sheng+mai*d-li[i];
        if(ji[i]==n)
        {
            break;
        }

    }
    cout<<ans;

    return 0;
}
