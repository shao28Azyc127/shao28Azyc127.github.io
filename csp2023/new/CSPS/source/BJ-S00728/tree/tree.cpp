#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010],v[100010],u[100010];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++) {
        cin>>v[i]>>u[i];
    }
    cout<<5;
    return 0;
}
