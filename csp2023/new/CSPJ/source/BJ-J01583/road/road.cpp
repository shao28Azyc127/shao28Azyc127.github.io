#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int u[n-1];
    int a[n];
    for(int i = 1;i <= n;i++){
        cin>>a[n];
        a[n] = a[i];
    }
    for(int j = 1;j <= d;j++){
        cin>>u[n-1];
        u[n-1] = u[j];
    }
    cout<<a[n] + u[n-1] + 61;
    return 0;
}
