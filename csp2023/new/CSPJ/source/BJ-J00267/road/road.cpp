#include <bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005],go,step=1,mon,nor;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        v[i]=v[i]+v[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while(step!=n)
    {
        go=step;
        for(int i=step+1;i<=n;i++)
        {
            if(a[step]>a[i])
            {
                go=i;
                break;
            }
        }
        if(go==step)
        {
            if((v[n]-v[step]-nor)%d!=0)
            mon+=((v[n]-v[step]-nor)/d+1)*a[step];
            else
            mon+=(v[n]-v[step]-nor)/d*a[step];
            break;
        }
        else
        {
            if((v[go]-v[step]-nor)%d!=0)
            {
            mon+=((v[go]-v[step]-nor)/d-1)*a[step];
            nor=d-((v[n]-v[step]-nor)%d);
            }
            else
            {
            mon+=((v[go]-v[step]-nor)/d)*a[step];
            nor=0;
            }
            step=go;

        }
    }
    cout<<mon;
    return 0;
}