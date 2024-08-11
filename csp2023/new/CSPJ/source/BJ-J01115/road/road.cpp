#include<bits/stdc++.h>
using namespace std;
long long n,d,a[100005],u[100005],ans,i,you;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i = 1;i < n;i++){
        cin >> u[i + 1];
        u[i + 1] += u[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(i = 1;i < n;){
        int j = i + 1;
        for(;j < n;j++){
            if(a[i] >= a[j]){
                break;
            }
        }
        if(j <= n){
            if(you >= u[j] - u[i] + d - 1){
                you -= u[j] - u[i] + d - 1;
            }else{
                ans += a[i] * ((u[j] - u[i] + d - 1 - you) / d);
                you += (u[j] - u[i] + d - 1 - you) / d * d - u[j] + u[i];
            }
            i = j;
        }
    }
    cout << ans;
    return 0;
}
