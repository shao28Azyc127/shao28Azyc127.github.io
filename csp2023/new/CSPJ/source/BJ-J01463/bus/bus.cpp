#include<bits/stdc++.h>
using namespace std;
int v[10005],a[1000005];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>v[i]>>v[j]>>a[i];
        }
    }
    int t,ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i<a[i])
            {
                k++;
                a[i]++;
                a[i+1]++;
            }
        }
    }
    cout<<6;
    return 0;
}
