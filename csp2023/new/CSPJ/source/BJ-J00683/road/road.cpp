#include <bits/stdc++.h>
using namespace std;
int u[100006];
int a[100006];
int sumd[100005];
int n,d;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    sumd[1]=0;
    for(int i = 1;i <=n-1;i++)
    {
        cin>>u[i];
        sumd[i+1]=sumd[i]+u[i];
    }
    for(int i = 1;i <=n;i++)
        cin>>a[i];
    int haveg=1,usem=0,lastd=0;
    while(haveg!=n)
    {
        int minnext=-1;
        for(int asdf = haveg+1;asdf <=n;asdf++)
            if(a[asdf]<a[haveg])
            {
                minnext=asdf;
                break;
            }
        if(minnext!=-1)
        {
            if(sumd[minnext]-sumd[haveg]-lastd<=0)
            {
                haveg=minnext;
                lastd-=(sumd[minnext]-sumd[haveg]);
                continue;
            }
            usem+=ceil(1.0*(sumd[minnext]-sumd[haveg]-lastd)/d)*a[haveg];
            lastd=lastd+ceil(1.0*(sumd[minnext]-sumd[haveg]-lastd)/d)*d-(sumd[minnext]-sumd[haveg]);
            haveg=minnext;
        }
        else if(minnext==-1)
        {
            if(sumd[n]-sumd[haveg]-lastd<=0)
            {
                cout<<usem;
                return 0;
            }
            usem+=ceil(1.0*(sumd[n]-sumd[haveg]-lastd)/d)*a[haveg];
            cout<<usem;
            return 0;
        }
    }
    cout<<usem;
    return 0;
}
