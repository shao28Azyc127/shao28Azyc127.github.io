#include <bits/stdc++.h>
using namespace std;
int A[2010],B[2010],c,n,q,m,aa[2010],bb[2010],node[2][2010],kx[2010],ky[2010];
bool mark;
void work (int a[],int b[])
{
    memset(node,0,sizeof(node));
    if((a[1]-b[1])*(a[n]-b[m])<=0)
        cout<<0;
    else
    {
        bool flag=1;
        mark=(a[1]>b[1]);
        node[0][1]=1,node[1][1]=m;
        for(int i=1;i<=m;i++)
            if((b[i]>=a[1]&&mark)||(b[i]<=a[1]&&!mark))
            {
                node[1][1]=i-1;
                break;
            }
        for(int i=2;i<n;i++)
        {
            flag=0;
            for(int j=node[0][i-1];j<=m;j++)
                if((b[j]<a[i]&&mark)||(b[j]>a[i]&&!mark))
                {
                    flag=1;
                    node[0][i]=j;
                    break;
                }
            if(!flag||node[0][i]>node[1][i-1])
            {
                flag=0;
                break;
            }
            node[1][i]=m;
            for(int j=node[0][i]+1;j<=m;j++)
                if((b[j]>=a[i]&&mark)||(b[j]<=a[i]&&!mark))
                {
                    node[1][i]=j-1;
                    break;
                }
        }
        cout<<flag;
    }
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
        aa[i]=A[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>B[i];
        bb[i]=B[i];
    }
    work(A,B);
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        memset(kx,0,sizeof(kx));
        memset(ky,0,sizeof(ky));
        for(int i=1;i<=x;i++)
            cin>>kx[i]>>aa[kx[i]];
        for(int i=1;i<=y;i++)
            cin>>ky[i]>>bb[ky[i]];
        work(aa,bb);
        for(int i=1;i<=x;i++)
            aa[kx[i]]=A[kx[i]];
        for(int i=1;i<=y;i++)
            bb[ky[i]]=B[ky[i]];
    }
    return 0;
}