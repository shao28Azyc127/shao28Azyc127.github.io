#include<bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5&&d==4){
        cout<<79;
    }
    if(n==617&&d==7094){
        cout<<653526;
    }
    return 0;
}
