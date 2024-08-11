#include <bits/stdc++.h>
using namespace std;
int n,d;
int v[100005],a[100005],b[100005]= {0};
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1; i<n; i++)
        cin>>v[i];
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=n-1; i>=1; i--)
    {
        b[i]=b[i+1]+v[i];
    }

    int h=0,s=0;
    int w=1;
    while(w!=n)
    {
        int i=w+1;
        for(; i<n; i++)
        {
            if(a[i]<a[w])
                break;
        }
        int g=b[w]-b[i];
        if(s<g)
        {
            int x=g-s;
            int y=0;
            y+=x/d;
            if(x%d)
                y++;
            s+=y*d;
            h+=y*a[w];
        }
        s-=g;
        w=i;
    }
    cout<<h;
    return 0;
}
