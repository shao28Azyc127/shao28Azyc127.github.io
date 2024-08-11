#include<iostream>
#include<cstring>
using namespace std;
int n;
char p[200001];
int d[200001],ds;
int ans,w;
void dele(int s)
{
    if(s==w-1)
    {
        w-=2;
        return;
    }
    for(int i=s;i<=w-2;i++)
    {
        p[i]=p[i+2];
    }
    w-=2;
    return;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    w=n;
    ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    for(int i=1;i<=10000;i++)
    {
        ds=0;
        for(int j=1;j<=w-1;j++)
        {
            if(p[j]==p[j+1])
            {
                d[ds]=j;
                ds++;
                ans++;
                j+=1;
            }
        }
        for(int j=0;j<ds-1;j++)
        {
            if(d[j+1]-d[j]==2)
            {
                int k=1;
                while(d[j+k]-d[j+k-1]==2&&j+k<ds)
                {
                    k++;
                }
                int sans=0;
                for(int q=1;q<=k-1;q++)
                {
                    sans+=q;
                }
                ans+=sans;
                j=j+k;
            }
        }
        for(int j=0;j<ds;j++)
        {
            dele(d[j]-2*j);
        }
        if(w==0) break;
    }
    cout<<ans;
    return 0;
}
