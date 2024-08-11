#include<bits/stdc++.h>
using namespace std;
int a[100001];
int v[100001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,d;
    cin>>n>>d;
    int sum=0;
    int oil=100000000;
    int l=0;
    int road=0;
    for(int i=1;i<n;i++){
        cin>>m;
        a[i]=a[i-1]+m;
    }

    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]<oil)oil=v[i];
        if(road<a[i]){
            l=(a[i]-road-1)/d+1;
            sum+=oil*l;
            road+=l*d;
        }
    }
    if(oil==v[1]){
        cout<<v[1]*((a[n-1]-1)/d+1);
        return 0;
    }
    cout<<sum;
    return 0;
}
