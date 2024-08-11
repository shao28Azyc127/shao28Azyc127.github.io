#include<iostream>
using namespace std;

const int MXN=100010;
typedef pair<int,int> pant;
int a[MXN],b[MXN],c[MXN];
vector<int> v[MXN];
int day[MXN];
int f[MXN];
pant tmp[MXN];

void dfs(int o,int fa)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[o][i]==fa) continue;
        tmp[i]={f[v[o][i]],v[o][i]};
    }int mx=1;
    sort(tmp,tmp+v.size()-1,greater<int>());
    for(int i=0;i<v.size()-1;i++)
    {
        mx=max(mx,i+1+tmp.first);
    }
}

int main()
{
    int n;cin>>n;
    int is1=1,is3=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(c[i]!=0) is1=0;
    }
    for(int i=1;i<n;i++)
    {
        int x,y;cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        if(x!=i||y!=i+1) is3=0;
    }
    if(is1)
    {
        for(int i=1;i<=n;i++) day[i]=(a[i]+b[i]-1)/b[i];
        for(int )
    }
}