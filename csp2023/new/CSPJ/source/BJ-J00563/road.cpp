#include <bits/stdc++.h>

using namespace std;

struct stop
{
    double f;
    int m;
    double h;
};

stop a[100];


int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    double y = 0;
    int c = 0;
    double z = 0;
    for(int i = 1;i<n;i++)
    {
        cin>>a[i].f;
    }
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i].m;
    }
    for(int i = 1;i<=n;i++)
    {
        a[i].h = a[i].f/d;
    }
    for(int i = 1;i<n;i++)
    {
        z = y*d*1.0;
        if(z<a[i].f)
        {
            for(int o = 1;z<a[i].f;o++)
            {
                c+=a[i].m;
                y++;
                z = y*d*1.0;
            }
            int d1 = a[i].f;
            for(int j = i+1;j<n;j++)
            {
                d1+=a[j].f;
                if(a[i].m<a[j].m)
                {
                    if(z<d1)
                    {
                        for(int o = 1;z<d1;o++)
                        {
                            c+=a[i].m;
                            y++;
                            z = y*d*1.0;
                        }
                    }
                    z = y*d*1.0;
                }
                else
                {
                    y-=a[i].h;
                    z = y*d*1.0;
                    break;
                }
            }
            continue;
        }
        if(z>=a[i].f)
        {
            int d1 = a[i].f;
            for(int j = i+1;j<n;j++)
            {
                d1+=a[j].f;
                if(a[i].m<a[j].m)
                {
                    if(z<d1)
                    {
                        for(int o = 1;z<d1;o++)
                        {
                            c+=a[i].m;
                            y++;
                            z = y*d*1.0;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
            y-=a[i].h;
        }
    }
    cout<<c;
    return 0;
}