#include <bits/stdc++.h>
using namespace std;
const int N=3005;
struct node
{
    int a[N],b[N],c[N];
    //b small
    //c big
}x[N];
int n,m;
bool cmp(int x,int y)
{
    return x>y;
}
int pos1=0,pos2=0;
void comp(int tmp)
{
    for(int i=1;i<=m;i++)
    {
        if(x[pos1].c[i]<x[tmp].c[i])
            return ;
        if(x[pos1].c[i]>x[tmp].c[i])
        {
            pos2=pos1;
            pos1=tmp;
            return ;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(x[pos2].c[i]<x[tmp].c[i]) return ;
        if(x[pos2].c[i]>x[tmp].c[i])
        {
            pos2=tmp;
            return ;
        }
    }
}
// 1 2
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        x[0].a[i]='z'+1;
        x[0].b[i]='z'+1;
        x[0].c[i]='z'+1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char tmp;
            cin>>tmp;
            x[i].a[j]=tmp;
            x[i].b[j]=x[i].a[j];
            x[i].c[j]=x[i].a[j];
        }
        sort(x[i].b+1,x[i].b+m+1);
        for(int j=1;j<=m;j++) x[i].c[j]=x[i].b[m-j+1];
        comp(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(pos1==i)
        {
            bool fl=0;
            for(int j=1;j<=m;j++)
            {
                if(x[i].b[j]<x[pos2].c[j])
                {
                    fl=1;
                    break;
                }
            }
            cout<<fl;
        }
        else
        {
            bool fl=0;
            for(int j=1;j<=m;j++)
            {
                if(x[i].b[j]<x[pos1].c[j])
                {
                    fl=1;
                    break;
                }
            }
            cout<<fl;
        }
    }
    return 0;
}

