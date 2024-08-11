#include<iostream>
#include<cstdio>
using namespace std;
int n,d,di,totald,nowi=1,ans;
double newd,red;
int s[100005],p[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>s[i];
        totald+=s[i];
    }
    for(int i=1;i<=n;i++)
        cin>>p[i];
    while(di<totald)
    {
        newd=0;
        for(int i=nowi;i<=n;i++)
        {
            if(p[i]<p[nowi])
            {
                newd=0;
                for(int j=nowi+1;j<=i;j++)
                {
                    newd+=s[j-1];
                }
                di+=newd;
                ans+=int((newd-red)/d+0.5)*p[nowi];
                red+=int((newd-red)/d+0.5)*d-newd;
                nowi =i;
            }
        }

    }
    cout<<ans;
    return 0;
}
