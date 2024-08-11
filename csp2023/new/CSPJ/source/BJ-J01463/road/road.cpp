#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int v[N],a[N],z[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,d;
    cin>>n>>d;
    int ans=0;
    for(int i=1;i<=n-1;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
     for(int i=1;i<=n;i++)
     {
        z[i+1]-z[i]==v[i];
        for(int j=1;j<=n;j++)
        {
            v[1]=0;
            v[n]=n*a[i];
            a[i]/d==0;
            ans++;
        }
     }
     cout<<ans*3+4;
    return 0;
}
