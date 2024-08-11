#include <iostream>
#include <cstdio>
using namespace std;
int f[100005];
int a[15];
int cal()
{
    return a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5];
}
int main(){
//    ios::sync_with_stdio(false);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    int s=n;
    while(s--)
    {
        for(int i=1; i<=5; i++)
            cin>>a[i];
        f[cal()]=-1;
        for(int i=1; i<=5; i++)
        {
//            cout<<a[i]<<" ";
            for(int j=1; j<=9; j++)
            {
                a[i]=(a[i]+1)%10;
                f[cal()]++;
            }
            a[i]=(a[i]+1)%10;
            if(i<=4)
            {
                for(int j=1; j<=9; j++)
                {
                    a[i]=(a[i]+1)%10;
                    a[i+1]=(a[i+1]+1)%10;
                    f[cal()]++;
                }
                a[i]=(a[i]+1)%10;
                a[i+1]=(a[i+1]+1)%10;
            }
//            cout<<a[i]<<endl;
        }
    }
    int ans=0;
    for(int i=1; i<1e5; i++)
        if(f[i]==n) ans++;
    cout<<ans<<endl;
    return 0;
}

