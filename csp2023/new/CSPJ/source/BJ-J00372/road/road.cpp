#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,v[100005],a[100005],m=0,k=0;
    cin >> n >> d;
    for(int i=1;i<n;i++)
    {
        cin >> v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(k<v[i]||a[i]<=a[i+1])
        {
            if(v[i]%d==0&&v[i+1]&d==0)
            {
                m+=a[i]*(v[i]/d+v[i+1]/d);
                k+=v[i]/d+v[i+1]/d;
            }
            else if(v[i]%d==0||v[i+1]%d==0)
            {
                m+=a[i]*(v[i]/d+1+v[i+1]/d);
                k+=v[i]/d+1+v[i+1]/d;
            }
            else
            {
                m+=a[i]*(v[i]/d+2+v[i+1]/d);
                k+=v[i]/d+2+v[i+1]/d;
            }
        }
        else if(k>=v[i]||a[i]>a[i+1])
        {
            continue;
        }
        else
        {
            if(v[i]%d==0)
            {
                m+=a[i]*(v[i]/d);
                k+=v[i]/d;
            }
            else
            {
                m+=a[i]*(v[i]/d+1);
                k+=v[i]/d+1;
            }

        }
    }
    cout << m<< endl;
    return 0;
}
