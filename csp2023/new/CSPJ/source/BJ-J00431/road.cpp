#include <bits/stdc++.h>

using namespace std;

int n,m,d,ew;

struct z
{
    int v;
    int a;
    int s;
};

int main()
{

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>d;
    z b[n-1];
    for(int i=0;i<(n-1);i++)
    {
        cin>>b[i].v;
    }
    for(int i=0;i<(n-1);i++)
    {
        cin>>b[i].a;
        b[i].s=i+1;
    }
    for(int i=0;i<(n-1);i++)
    {
        int cm=1,vn=b[i].v;
        while(b[i].a<b[i+cm].a&&i+cm<n-1)
        {
            cm++;
        }
        for(int j=1;j<cm;j++)
        {
            vn=vn+b[j+cm].v;
        }
        vn=vn-ew;
        int yg;
        yg=vn/d;
        ew=0;
        if(vn%d!=0)
        {
            yg++;
            ew=yg*d-vn;
        }
        m=m+yg*b[i].a;
        i=i+cm-1;
    }
    cout<<m;

    return 0;
}
