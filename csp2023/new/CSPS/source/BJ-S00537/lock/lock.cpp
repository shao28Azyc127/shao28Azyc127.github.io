#include<bits/stdc++.h>
using namespace std;
const int N=6,M=9;
struct Node
{
    int c[N];
}a[M],b;
int n,ans;
vector<int> Dif(Node x,Node y)
{
    vector<int> ls;
    for(int i=1;i<=5;i++)
        if(x.c[i]!=y.c[i])
            ls.push_back(i);
    return ls;
}
bool Check()
{
    for(int i=1;i<=n;i++)
    {
        vector<int> ls=Dif(b,a[i]);
        if(ls.size()==0)
            return false;
        if(ls.size()>2)
            return false;
        if(ls.size()==2)
        {
            if(ls[0]+1!=ls[1] && ls[0]-1!=ls[1])
                return false;
            if((a[i].c[ls[0]]-a[i].c[ls[1]]+10)%10!=(b.c[ls[0]]-b.c[ls[1]]+10)%10)
                return false;
        }
    }
    return true;
}
void Dfs(int now)
{
    if(now>5)
    {
        if(!Check())
            return ;
        ans++;
        return ;
    }
    for(int i=0;i<=9;i++)
    {
        b.c[now]=i;
        Dfs(now+1);
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin>>a[i].c[j];
    Dfs(1);
    cout<<ans;
    return 0;
}