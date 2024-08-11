#include<iostream>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(i%3==0) a[i]=0;
        else a[i]=a[i-i/3-1]+1;
        if(a[i]>ans) ans=a[i];
    }
    cout<<ans+1<<' '<<a[n-1]+1<<endl;
    return 0;
}
