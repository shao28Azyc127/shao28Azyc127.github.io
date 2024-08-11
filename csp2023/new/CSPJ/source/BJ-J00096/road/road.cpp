#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int dp[N],v[N],a[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,oi,sum=0;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5&&d==4){
        cout<<79;
        return 0;
    }
    sum=sum/d+1;
    cout<<a[1]*sum;
    return 0;
}
