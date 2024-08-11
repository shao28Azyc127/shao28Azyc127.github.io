#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
double n,d,v[maxn],a[maxn],dp[maxn];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    double sum=0;
    for(int i=1;i<=n-1;i++){
        cin >> v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    cout << ceil(sum/d/a[1]);
    return 0;
}
