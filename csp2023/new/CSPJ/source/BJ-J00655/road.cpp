#include <bits/stdc++.h>
using namespace std;
int v[1111111],o[1111111],sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++)
            cin>>o[i];
    int ke=sum/d;
    cout<<ke*o[1];
    return 0;
}
