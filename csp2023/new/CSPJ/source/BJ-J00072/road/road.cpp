#include <bits/stdc++.h>
using namespace std;
int dist[100005];
int a[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int ans = 0;
    int n,d;
    cin>>n>>d;
    for(int i = 1; i < n; i++){
        cin>>dist[i];
    }
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    int rdd = 0;
    int oil;
    for(int i = 1; i < n; i++){

        int cst = (dist[i]-rdd)/d;
        if(d*cst < dist[i]-rdd){
            cst++;
        }
        rdd+=d*cst;
        rdd-=dist[i];
        if(i == 1){
            ans += cst*a[i];
            oil = a[i];
        }else{
            if(a[i] < oil){
                ans += cst*a[i];
                oil = a[i];
            }else{
                ans += cst*oil;
            }
        }
    }
    cout<<ans;
    return 0;
}
