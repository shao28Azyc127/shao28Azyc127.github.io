#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
    memset(a,0,sizeof(a));
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    int sum=0,ans=0;
    int i=1,cnt=0;
    while(a[1]!=0)
    {
        if(i%2==1)
        {
            cnt++;
        }
        if(a[i+cnt-1]==n&&i%2==1)
        {
            ans=sum;
        }
        if(a[i]!=0)
        {
            a[i]=a[i+cnt];
        }
        else
        {
            i=1;
            cnt=0;
            sum++;
            continue;
        }
        i++;
    }
    cout<<sum+1<<" "<<ans+1;
    return 0;
}
