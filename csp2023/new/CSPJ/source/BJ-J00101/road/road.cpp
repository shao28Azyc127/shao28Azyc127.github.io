#include<iostream>
using namespace std;
int a[100050],dis[100050],you[100050],minn[100050];
int main()
{
    int n,d;
    cin>>n>>d;
    dis[1]=0;
    for(int i=2;i<=n;i++)
    {
        cin>>dis[i];
        dis[i]+=dis[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        if(dis[i]%d==0)
            dis[i]/=d;
        else
        {
            dis[i]/=d;
            dis[i]++;
        }
    }
    int minx=0x7fffffff;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<minx)
        {
            minn[i]=i;
            minx=a[i];
        }
        else minn[i]=minn[i-1];
    }
    you[1]+=dis[2];
   for(int i=3;i<=n;i++)
   {
        int x=dis[i]-dis[i-1];
        you[minn[i-1]]+=x;
   }
   long long cnt=0;
   for(int i=1;i<=n;i++)
   {
       cnt+=you[i]*a[i];
   }
   cout<<cnt;
}
