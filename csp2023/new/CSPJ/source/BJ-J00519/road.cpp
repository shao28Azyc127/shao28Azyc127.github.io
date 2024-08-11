#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    int x,y;
    int ans=0;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>x;
        ans+=x;
    }
    cin>>y;
    for(int i=1;i<=n-1;i++){
        cin>>x;
    }
    if(ans%d==0){
        cout<<ans/d*y;
    }else{
        cout<<(ans/d+1)*y;
    }
    return 0;
}
