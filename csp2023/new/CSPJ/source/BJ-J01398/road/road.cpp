#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
using namespace std;
int n,d,v[100000+10],a[100000+10],dp[100000+10],v2[100000+10];
int fc(int x){
    if (x<0) return 0;
    return x;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf ("%d %d", &n, &d);
    for (int i=2;i<=n;i++){
        scanf ("%d", &v[i]);
        v2[i] = v2[i-1]+v[i];
    }
    for (int i = 1;i<=n;i++){
        scanf ("%d", &a[i]);
    }
    for (int i=2;i<=n;i++){
        dp[i] = 2147483647;
        for (int j=1;j<i;j++){
            dp[i] = min(dp[i],int(dp[j]+ceil((v2[i]-v2[j])*1.0/d)*a[j]));
        }
    }
    printf ("%d\n", dp[n]);
    return 0;
}
// maybe i will AFO after this.