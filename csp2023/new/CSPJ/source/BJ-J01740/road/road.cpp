#include<bits/stdc++.h>
using namespace std;
const int NN=1e6;
int n,d;
int v[NN];
int a[NN];
int ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int minn=1e9;
    for(int i=1;i<=n;i++){
        minn=min(minn,a[i]);
    }
    if(minn==a[1]){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum=v[i]+sum;
        }
        if(sum%d==0){
            ans=(sum/d)*a[1];
        }else{
            ans=(sum/d+1)*a[1];
        }
    }
    cout<<ans;
    return 0;
}
/*
5 3
10 10 10 10
3 8 9 6 5
*/
