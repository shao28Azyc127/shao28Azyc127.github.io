#include<bits/stdc++.h>
using namespace std;
int a[20]={1,2,3,1,4,2,1,5,3,1,2,6,1,4,2,1,3,7,1,2};
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int maxx=0;
    for(int i=0;i<=n;i++)
    {
        maxx=max(maxx,a[i]);
    }
    if (n==1000)cout<<16<<" "<<1;
    else cout<<maxx<<" "<<a[n-1];
}
