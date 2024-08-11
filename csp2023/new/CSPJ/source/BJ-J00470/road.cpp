#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int dt[100005],v[100005],a[1000005];

int dfs(int n,int d){
    int _min=9999999,mini;
    for(int i=1;i<=n;i++){
        if(_min>a[i]){
            mini=i;
            _min=a[i];
        }
    }
    return dfs(mini)+ceil(v[i]/d);
}

int main(){
    ios::sync_with_stdio(false);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<dfs(n);
    return 0;
}
