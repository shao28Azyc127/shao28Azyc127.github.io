#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,s=0;
    cin>>n>>d;
    int v[n];
    for(int i=1;i<n;i++){
        cin>>v[i];
        s=s+v[i];
    }
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(s%d==0){
        cout<<s/d*a[1];
    }
    else{
        cout<<(s/d+1)*a[1];
    }
    return 0;
}