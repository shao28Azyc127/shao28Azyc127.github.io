#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,v[9],a[9],r=0;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        r+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[n]=1000000;
    }
    int o=a[1]*r/d;
    if(r%d==0){
        cout<<o;
    }else{
        cout<<o+1*a[1];
    }
    return 0;
}
