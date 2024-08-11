#include<bits/stdc++.h>
using namespace std;
int n,d;
int v[100005];
int a[100005];
int ans=0x3f3f3f3f;
int sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>d;
    int sum=0;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(sum%d==0)
        ans=(int)sum/d*a[1];
    else
        ans=(int)(sum/d+1)*a[1];
    cout<<ans;
    return 0;
}
