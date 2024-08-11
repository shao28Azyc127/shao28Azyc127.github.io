#include<bits/stdc++.h>
using namespace std;

int n,d,u[100000000],a[100000000],ma,ju,mo;

int road(int g,int h){
    for(int i=1;i<=n-1;i++) ju+=u[i];
    if(ju%d!=0) mo=(ju/d+1)*a[1];
    else mo=ju/d*a[1];

return mo;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n,d;
    for(int i=1;i<=n-1;i++) cin>>u[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<road(n,d);

    return 0;
}
