#include<bits/stdc++.h>
using namespace std;
const int N=8+5;
int a[N][6],b[6];
int to(int x)
{
    if(x>=0)return x;
    else return 10+x;
}
int n;
int check(int x)
{
    int w=0,c=0,nw=0;
    for(int i=1;i<=5;i++)
    {
        if(a[x][i]!=b[i])
        {
            if(w==0)w++,c=to(a[x][i]-b[i]),nw=i;
            else if(w==1)
            {
                w++;
                if(to(a[x][i]-b[i])!=c)return 0;
                if(i-nw!=1)return 0;
            }
            else return 0;
        }
    }
    if(w==0)return 0;
    return 1;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            scanf("%d",&a[i][j]);
    int ans=0,flag;
    for(int sa=0;sa<=9;sa++)
    {
        for(int sb=0;sb<=9;sb++)
        {
            for(int sc=0;sc<=9;sc++)
            {
                for(int sd=0;sd<=9;sd++)
                {
                    for(int se=0;se<=9;se++)
                    {
                        flag=1;
                        for(int i=1;i<=n;i++)
                        {
                            b[1]=sa;
                            b[2]=sb;
                            b[3]=sc;
                            b[4]=sd;
                            b[5]=se;
                            if(!check(i))
                            {
                                flag=0;
                                break;
                            }
                        }
                        ans+=flag;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
