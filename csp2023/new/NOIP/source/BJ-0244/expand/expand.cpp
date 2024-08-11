#include<bits/stdc++.h>
using namespace std;

    int c,n,m,q;
bool check(vector<int> a,vector<int> b)
{
    if(a.size()!=b.size()) return false;
    int cnt0=0,cnt1=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<b[i]) cnt0++;
        else if(a[i]>b[i]) cnt1++;
        else return false;
    }
    if(cnt0 && cnt1) return false;
    return true;
}
vector<int> X,Y;
vector<int> nx,ny;
vector<int> c1,c2;
bool flag=0;
bool check()
{
    vector<int> A,B;
    for(int i=0;i<nx.size();i++)
    {
        for(int j=0;j<c1[i];j++)
        {
            A.push_back(nx[i]);
        }
    }
    for(int i=0;i<ny.size();i++)
    {
        for(int j=0;j<c2[i];j++)
        {
            B.push_back(ny[i]);
        }
    }

    if(check(A,B))
    {
        return true;
    }
    return false;
}
void dfs(int id1,int id2)
{
    if(flag) return ;
    if(id1==n+1 && id2==m+1)
    {
        if(check())
        {
            flag=1;
            return ;
        }
    }
    if(id1!=n+1)
    {
        for(int i=1;i<=n;i++)
        {
            c1.push_back(i);
            dfs(id1+1,id2);
            c1.pop_back();
        }
        return ;
    }
    if(id2!=m+1)
    {
        for(int i=1;i<=m;i++)
        {
            c2.push_back(i);
            dfs(id1,id2+1);
            c2.pop_back();
        }
        return ;
    }
}
char query()
{
    nx=X,ny=Y;
    int kx,ky;
    scanf("%d%d",&kx,&ky);
    for(int i=1;i<=kx;i++)
    {
        int px,vx;
        scanf("%d%d",&px,&vx);
        nx[px-1]=vx;
    }
    for(int i=1;i<=ky;i++)
    {
        int py,vy;
        scanf("%d%d",&py,&vy);
        ny[py-1]=vy;
    }

    c1.clear(),c2.clear();
    flag=false;
    dfs(1,1);
    if(flag) return '1';
    else return '0';
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        X.push_back(x);
    }
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        Y.push_back(x);
    }
    string ans="";
    dfs(1,1);
    if(flag) ans.push_back('1');
    else ans.push_back('0');
    while(q--)
    {
        ans+=query();
    }
    cout<<ans<<'\n';
    return 0;
}
