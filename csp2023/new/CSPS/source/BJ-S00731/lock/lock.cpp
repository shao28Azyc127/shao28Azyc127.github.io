#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,tx,tx2,tp,a[8],ans;
int num[100005];
int hash_(int a[])
{
    int ans=0;
    for(int i=0;i<5;i++)
        ans=ans*10+(a[i]%10);
    return ans;
}
int main()
{
    freopen("lock.in" ,"r",stdin );
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        tx=0;
        for(int j=0;j<5;j++)
            cin>>a[j];
        for(int i=0;i<5;i++)
        {
            tx=a[i];
            for(int j=1;j<10;j++)
            {
                a[i]++;
                tp=hash_(a);num[tp]++;
                if(num[tp]==n)ans++;
            }
            a[i]=tx;
        }
        for(int i=0;i<4;i++)
        {
            tx=a[i],tx2=a[i+1];
            for(int j=1;j<10;j++)
            {
                a[i]++,a[i+1]++;
                tp=hash_(a);num[tp]++;
                if(num[tp]==n)ans++;
            }
            a[i]=tx,a[i+1]=tx2;
        }
    }
    cout<<ans;
    return 0;
}