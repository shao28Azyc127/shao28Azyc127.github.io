#include <iostream>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m;
    int a[1002] = {},b[1002] = {};
    cin >> n >> m;
    for(int i = 1; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    b[n] = 0;
    int store = 0;
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(store == 0){
            int cnt = 1;
            for(int j = 2; j <= n; j++){
                if(b[j] >= b[i]){
                    cnt++;
                    continue;
                }
                break;
            }
            if(cnt == 1){
                if(a[i] % m == 0){
                    ans += (a[i] /m) * b[i];
                }else{
                    ans += (a[i]/ m + 1) * b[i];
                    store = (a[i] / m + 1 ) * m - a[i];
                }
            }else{
                int sumn = 0;
                for(int j = i; j < i + cnt; j++){
                    sumn += a[i];
                }
                if(sumn % m == 0){
                    ans += (a[i] / m) * b[i];
                }else{
                    ans += (a[i] / m + 1) * b[i];
                    store += a[i] % m;
                }
            }
        }else{
            int cnt = 1;
            for(int j = 2; j <= n; j++){
                if(b[j] >= b[i]){
                    cnt++;
                    continue;
                }
                break;
            }
            if(cnt == 1){
                if(a[i] % m == 0){
                    ans += (a[i] /m) * b[i];
                    store = 0;
                }else{
                    ans += (a[i]/ m + 1) * b[i];
                    store = ans % m;
                }
            }else{
                int sumn = 0;
                for(int j = i; j < i + cnt; j++){
                    sumn += a[i];
                }
                if(sumn % m == 0){
                    ans += (a[i] / m) * b[i];
                    store = 0;
                }else{
                    ans += (a[i] / m + 1) * b[i];
                    store = ans % m;
                }
            }
        }
    }
    cout << ans;
    return 0;
}