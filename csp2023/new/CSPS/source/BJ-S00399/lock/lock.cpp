#include<iostream>
using namespace std;

const int MXK=10,MXN=10;
int a[MXN][MXK],c[MXN];
int tmp[MXN];

int chk(int a,int b)
{
    if(a<b) a+=10;
    return a-b;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,ans=0;cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++) cin>>a[i][j];
    }
    for(int i=0;i<=99999;i++)
    {
        for(int j=10000,k=1;j>=1;j/=10,k++) c[k]=(i/j)%10;
        for(int _=1;_<=n;_++)tmp[_]=0;
        for(int _=1;_<=n;_++)
        {
            int diff=0;
            // for(int j=1;j<=5;j++) cerr<<c[j];
            for(int k=1;k<=5;k++)
            {
                if(chk(a[_][k],c[k])!=0) diff++;
                // cerr<<a[_][k]<<' '<<c[k]<<endl;
            }
            // cerr<<diff<<' ';
            if(diff==1) tmp[_]=1;
            diff=0;int diff2=0;
            for(int k=1;k<=4;k++)
            {
                if(chk(a[_][k],c[k])!=0&&chk(a[_][k],c[k])==chk(a[_][k+1],c[k+1])) diff++;
                if(chk(a[_][k],c[k])!=0) diff2++;
                // cerr<<a[j][k]<<' '<<c[j]<<' '<<diff<<endl;
            }
            if(chk(a[_][5],c[5])!=0) diff2++;
            // cerr<<diff<<' '<<diff2<<endl;
            if(diff==1&&diff2==2) tmp[_]=1;
        }
        int mn=1;
        for(int _=1;_<=n;_++) mn=min(mn,tmp[_]);
        if(mn) ans++;
        // else
        // {
        //     for(int _=1;_<=n;_++)tmp[_]=0;
        //     for(int _=1;_<=n;_++)
        //     {
        //         int diff=0;int diff2=0;
        //         for(int k=1;k<=4;k++)
        //         {
        //             if(chk(a[_][k],c[k])!=0&&chk(a[_][k],c[k])==chk(a[_][k+1],c[k+1])) diff++;
        //             if(chk(a[_][k],c[k])!=0) diff2++;
        //             // cerr<<a[j][k]<<' '<<c[j]<<' '<<diff<<endl;
        //         }
        //         if(chk(a[_][5],c[5])!=0) diff2++;
        //         // cerr<<diff<<' '<<diff2<<endl;
        //         if(diff==1&&diff2==2) tmp[_]=1;
        //     }
        //     mn=1;
        //     for(int _=1;_<=n;_++) mn=min(mn,tmp[_]);
        //     if(mn) ans++;
        // }
    }
    cout<<ans<<endl;
    return 0;
}