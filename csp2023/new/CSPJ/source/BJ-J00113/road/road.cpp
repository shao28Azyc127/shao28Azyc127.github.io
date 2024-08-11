#include<bits/stdc++.h>
using namespace std;
int n,d;
int a[100005];
int v[100005];
int sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(sum%d==0)
        cout<<(sum/d)*a[1];
    else cout<<(sum/d+1)*a[1];
}
