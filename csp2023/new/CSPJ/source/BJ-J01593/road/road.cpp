#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("road.in", "r", stdin);
    //freopen("road.out", "W", stdout);
    int n, d;
    cin >> n >> d;
    int distance[n];
    for(int i = 1; i < n; i++){
        cin >> distance[i];
    }
    int l = n + 1;
    int price[l];
    for(int i = 0; i < n; i++){
        cin >> price[i];
    }
    int zong = 0;
    int now = 0;
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(i > 1){
            i--;
        }
        for(int j = i; j < n; j++){
            if(price[j - 1] >= price[i - 1]){
                zong += distance[j];
                if((zong - now) % d == 0){
                    now = zong;
                    ans += (zong - now) / d * price[i - 1];
                }
                else{
                    now = (zong - now) / d * (d + 1);
                    ans += ((zong - now) / d + 1) * price[i - 1];
                }
                i++;
            }
            else{
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
