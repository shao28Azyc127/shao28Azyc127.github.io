#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    int x=0;
    cin>>n>>d;
    int v[100000];
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    int g;
    int a[100001];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        x+=v[i];
    }
    g=x/d;
    cout<<(g+1)*a[1];
    return 0;
}
