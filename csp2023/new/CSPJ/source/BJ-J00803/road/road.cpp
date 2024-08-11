#include<bits/stdc++.h>
using namespace std;
int n,d,x,y,a[100010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>x;
        y+=x;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    x=a[1];
    sort(a+1,a+n+1);
    if(a[1]==x||n==2) cout<<x*(y/d+1);
    return 0;
}