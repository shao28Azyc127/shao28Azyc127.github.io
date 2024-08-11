#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[15][15];
int z[15];
bool can1(int chk)
{
    int dist[15]={0};
    //for(int i=1;i<=5;i++)
        //cout<<"dist["<<i<<"]="<<(dist[i]=(z[i]+10-a[chk][i])%10)<<'\n';
    int d=0,pos1=0,pos2=0;
    for(int i=1;i<=5;i++)
        if(dist[i])
        {
            if(!d)
            {
                d=dist[i];
                pos1=i;
                //cout<<"pos1="<<i<<'\n';
                continue;
            }
            if(d!=dist[i]) return false;
            if(pos1&&!pos2)
            {
                //cout<<"pos2="<<i<<'\n';
                if(pos1!=i-1) return false;
                pos2=i;
                continue;
            }
            if(pos2) return false;
        }
    if(!pos1) return false;
    return true;
}
bool can(int chk)
{
    int dist[15]={0};
    for(int i=1;i<=5;i++)
        dist[i]=(z[i]+10-a[chk][i])%10;
    int d=0,pos1=0,pos2=0;
    for(int i=1;i<=5;i++)
        if(dist[i])
        {
            if(!d)
            {
                d=dist[i];
                pos1=i;
                continue;
            }
            if(d!=dist[i]) return false;
            if(pos1&&!pos2)
            {
                if(pos1!=i-1) return false;
                pos2=i;
                continue;
            }
            if(pos2) return false;
        }
    if(!pos1) return false;
    return true;
}
bool canall()
{
    for(int i=1;i<=n;i++)
        if(!can(i))
        {
            //cout<<i<<" NOT OK\n";
            return false;
        }
    //for(int i=1;i<=5;i++)
    //    cout<<z[i];
    //cout<<'\n';
    return true;
}
int cnt;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin>>a[i][j];
    for(z[1]=0;z[1]<=9;z[1]++)
        for(z[2]=0;z[2]<=9;z[2]++)
            for(z[3]=0;z[3]<=9;z[3]++)
                for(z[4]=0;z[4]<=9;z[4]++)
                    for(z[5]=0;z[5]<=9;z[5]++)
                        if(canall())
                            cnt++;
    cout<<cnt;
    //while(cin>>z[1]>>z[2]>>z[3]>>z[4]>>z[5]>>z[6])
    //{
    //    cout<<can(z[6])<<'\n';
    //}
    return 0;
}
