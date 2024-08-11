#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int v[N],a[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int ans=0;
    int x;
    for(int i=1;i<n;i++){
        cin>>v[i];
        ans+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x=a[1];
    }
    if(ans%d==0){
        cout<<ans/d*x;
    }
    else{
        cout<<(ans/d+1)*x;
    }
    return 0;
}

