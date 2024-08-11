#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int m,n,sum = 0,ans = 0,c = 0;
    int a[100000],b[100000];
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        sum+=a[i];
    }
    for(int j = 1;j <= n;j++){
        cin >> b[j];
    }
    for(int j = 1;j <= n;j++){
         c = b[1];
    }

    ans = sum * c;
    cout << ans;
return 0;
}