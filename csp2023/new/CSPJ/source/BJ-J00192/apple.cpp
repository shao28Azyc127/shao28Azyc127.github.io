#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans=1;
    cin>>n;
    int a[n];
    int j=1;
    while(a[j])
    {
        for(int i=j;i<=n;i+=3)
        {
            if(a[i]==0)
                i+=1;
            else
                a[i]=0;
            if(i==n)
                ans+=1;
        }
        j+=1;
        ans+=1;
        if(a[j]==0)
            j+=1;
    }
    cout<<j<<" "<<ans;
    return 0;
}
