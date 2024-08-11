#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e6+5;
struct Node
{
    int a,b,c;
    bool operator<(const Node y)const
    {
        return b<y.b;
    }
}node[MAXN];
int l[MAXN];
int main()
{
    //freopen("/home/noip02/CSP-S/tree1.in","r",stdin);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>node[i].a>>node[i].b>>node[i].c;
    }
    sort(node+1,node+n+1);
    int cnt=1;
    while(true)
    {
        for(int i=1;i<=min(n,cnt);i++) l[i]+=max(node[i].b+cnt*node[i].c,1);
        bool flag=true;
        for(int i=1;i<=n;i++)
            if(l[i]<node[i].a)
        {
            flag=false;
            break;
        }
        if(flag)
        {
            cout<<cnt<<endl;
            break;
        }
        cnt++;
    }
    return 0;
}