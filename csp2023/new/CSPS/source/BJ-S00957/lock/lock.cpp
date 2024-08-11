#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long z[10010],w[100010];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int num=0;
        for(int j=1;j<=5;j++) cin>>z[j],num=num*10+z[j];
        for(int j=1;j<=5;j++)
        {
            for(int k=0;k<=9;k++)
            {
                if(z[j]==k) continue;
                int x=num;
                x+=1ll*(k-z[j])*pow(10,5-j);
                //cout<<x<<"\n";
                w[x]++;
            }
        }
        for(int j=1;j<=4;j++)
        {
            for(int k=0;k<=9;k++)
            {
                if(z[j]==k) continue;
                int x=num;
                int a,b;
                a=k;b=(z[j+1]+k-z[j])%10;
                x+=1ll*(a-z[j])*pow(10,5-j)+1ll*(b-z[j+1])*pow(10,4-j);
                //cout<<x<<"\n";
                //cout<<1ll*(a-z[j])*pow(10,5-j)<<" "<<1ll*(b-z[j+1])*pow(10,4-j)<<" "<<j<<"\n";
                w[x]++;
            }
        }
    }
    for(int i=0;i<=100000;i++) if(w[i]==n) ans++;
    cout<<ans;

    cout<<endl;
    return 0;
}
