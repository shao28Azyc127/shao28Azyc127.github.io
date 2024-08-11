#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],b[1000000],f1[1000000],f2[1000000],f3[1000000],z,k;;
int main()
{
    freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n-1;i++) cin>>a[i+1];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++){
        k=k+a[i];
    }
    cout<<(k/m+k%m)*b[1];
    return 0;
}
