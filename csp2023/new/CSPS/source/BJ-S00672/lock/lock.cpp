#include<iostream>
using namespace std;
#define maxn 8
const int base[5]={10000,1000,100,10,1};
int n,ans=0;
int a[maxn+100];
bool vis[110000];
bool valid(int x)
{
    bool flag=true;
    for(int i=0;i<5;i++)
        for(int j=1;j<10;j++)
        {
            int ow=x/base[i]%10;
            int nw=(ow+j)%10;
            vis[x-ow*base[i]+nw*base[i]]=true;
        }
    for(int i=0;i<4;i++)
        for(int j=1;j<10;j++)
        {
            int ow1=x/base[i]%10,ow2=x/base[i+1]%10;
            int nw1=(ow1+j)%10,nw2=(ow2+j)%10;
            vis[x-ow1*base[i]-ow2*base[i+1]+nw1*base[i]+nw2*base[i+1]]=true;
        }
    for(int i=0;i<n;i++)
        if(!vis[a[i]])
        {
            flag=false;
            break;
        }
    for(int i=0;i<5;i++)
        for(int j=1;j<10;j++)
        {
            int ow=x/base[i]%10;
            int nw=(ow+j)%10;
            vis[x-ow*base[i]+nw*base[i]]=false;
        }
    for(int i=0;i<4;i++)
        for(int j=1;j<10;j++)
        {
            int ow1=x/base[i]%10,ow2=x/base[i+1]%10;
            int nw1=(ow1+j)%10,nw2=(ow2+j)%10;
            vis[x-ow1*base[i]-ow2*base[i+1]+nw1*base[i]+nw2*base[i+1]]=false;
        }
    return flag;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<5;j++)
        {
            int x;
            cin>>x;
            a[i]=a[i]*10+x;
        }
    for(int i=0;i<100000;i++)
        if(valid(i))ans++;
    cout<<ans<<"\n";
    return 0;
}