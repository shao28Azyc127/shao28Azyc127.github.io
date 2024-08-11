#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

const int N=1e4+5;
vector<int> v[N],t[N];
bool f[N][1000];

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k,mx=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        v[x].push_back(y);
        t[x].push_back(w);
        mx=max(mx,w);
    }
    for(int j=0;j<=mx+m;j+=k)f[1][j]=1;
    for(int j=0;j<=mx+m;j++)
        for(int i=1;i<=n;i++)
        {
            //printf("%d %d %d\n",i,j,f[i][j]);
            for(int l=0;l<v[i].size();l++)
            {
                //printf("%d %d %d\n",i,j,v[i][l]);
                 if(j<t[i][l])continue;
                 f[v[i][l]][j+1]|=f[i][j];
            }
        }
    for(int j=0;j<=mx+m;j+=k)
        if(f[n][j]){
            cout<<j;
            return 0;
        }
    cout<<-1;
    return 0;
}
