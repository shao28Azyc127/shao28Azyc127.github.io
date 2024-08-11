#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int c,n,m,q;
int a[500005],b[500005];
int aa[500005],bb[500005];
void chk()
{
    if(aa[1]<bb[1])
    {
        int j=1;
        for(int i=1;i<=n;i++)
        {
            //cout<<"i="<<i<<"j="<<j<<'\n';
            while(aa[i]>=bb[j]&&i>1&&j<m)
            {
                i--;
            }
            if(aa[i]>=bb[j])
            {
                cout<<'0';
                return;
            }
            if(j<m) j++;
            //while(aa[i]>bb[j]&&j<m) j++;
        }
        cout<<'1';
    }
    else
    {
        int j=1;
        for(int i=1;i<=n;i++)
        {
            //cout<<"i="<<i<<"j="<<j<<'\n';
            while(aa[i]<=bb[j]&&i>1&&j<m)
            {
                i--;
            }
            if(aa[i]<=bb[j])
            {
                cout<<'0';
                return;
            }
            if(j<m) j++;
            //while(aa[i]>bb[j]&&j<m) j++;
        }
        cout<<'1';
    }
}
void cpy()
{
    for(int i=1;i<=n;i++) aa[i]=a[i];
    for(int i=1;i<=m;i++) bb[i]=b[i];
}
int main()
{
    //freopen("/home/rdfz/day0/expand/expand5.in","r",stdin);
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    cpy();
    chk();
    for(int _=1;_<=q;_++)
    {
        cpy();
        int kx,ky;
        cin>>kx>>ky;
        for(int i=1;i<=kx;i++)
        {
            int tmp1,tmp2;
            cin>>tmp1>>tmp2;
            aa[tmp1]=tmp2;
        }
        for(int i=1;i<=ky;i++)
        {
            int tmp1,tmp2;
            cin>>tmp1>>tmp2;
            bb[tmp1]=tmp2;
        }
        chk();
    }
    return 0;
}
