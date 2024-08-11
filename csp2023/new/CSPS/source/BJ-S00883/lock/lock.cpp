#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
long long a[10][10];

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }
    }
    int m=10000;
    for(int i=1;i<5;i++)
    {
        map<int,bool> tar;
        int cha=0,ha=0;
        m/=10;
        bool can=true;
        for(int j=1;j<=n;j++)
        {
            int he=0;
            for(int k=1;k<=5;k++) he=he*10+a[j][k];
            //printf("(%d,%d)",he,m);
            he=he-(a[j][i+1]*(m)+a[j][i]*(m+10));
            if(j==1)
            {
                tar[ a[j][i]*10 + a[j][i+1] ]=true;
                cha=a[j][i]-a[j][i+1];
                int m=1;
                ha=he;
            }
            else if(a[j][i]-a[j][i+1]!=cha || he!=ha)
            {
                can=false;
                break;
            }
            else if(a[j][i]-a[j][i+1]==cha)
            {
                tar[ a[j][i]*10 + a[j][i+1] ]=true;
            }
            //printf("he:%d cha:%d ha:%d_____",he,cha,ha);
        }
        if(can) ans+=10-tar.size();
        //cout<<ans<<endl;
    }
    //cout<<"gai"<<'\n';
    m=100000;
    for(int i=1;i<=5;i++)
    {
        map<int,bool> tar;
        bool can=true;
        int ha=0;
        m/=10;
        for(int j=1;j<=n;j++)
        {
            int he=0;
            for(int k=1;k<=5;k++) he=he*10+a[j][k];
            //printf("(%d,%d)",he,m);
            he=he-(a[j][i]*m);
            if(j==1)
            {
                tar[a[j][i]]=true;
                ha=he;
            }
            else if(ha!=he)
            {
                can=false;
                break;
            }
            //printf("he:%d ha:%d_____",he,ha);
        }
        if(can)ans+=10-tar.size();
        //cout<<ans<<endl;
    }
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}