#include <iostream>

using namespace std;

int n,m,k;
int r[20005][20005];
int f[20005];
int t;

void walk(int x)
{
    if(f[x]==0)
    {
        f[x]=t;
    }
    if(t<f[x])
    {
        f[x]=t;
    }
    for(int i=0;i<n;i++)
    {
        if(r[x][i])
        {
            t++;
            walk(i);
            t--;
        }
    }
}

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","r",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y>>r[x][y];
        r[y][x]=r[x][y];
    }
    walk(1);
    for(int i=0;i<f[n];i++)
    {
        if((i*k+f[n])%k==0)
        {
            cout<<i*k+f[n];
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
