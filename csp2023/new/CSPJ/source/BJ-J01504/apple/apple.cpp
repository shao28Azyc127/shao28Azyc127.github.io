#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100001];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    for(int i=0;i<100001;i++) a[i]=0;
    int n,sum=0,ans;
    cin>>n;
    if(n==1)
    {
        cout<<"1 1";
        return 0;
    }
    while(1)
    {
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                break;
                flag=1;
            }
        }
        cout<<1<<endl;
        if(flag==0)
        {
            break;
        }
        sum++;
        int l=-1,num=0;
        while(l<=n);
        {
            l++;
            if(a[l]==0) continue;
            if(num%3==0) a[l]=1;
            if(l=n-1) ans=sum;
            num++;
        }
    }
    cout<<sum<<" "<<ans;
    return 0;
}