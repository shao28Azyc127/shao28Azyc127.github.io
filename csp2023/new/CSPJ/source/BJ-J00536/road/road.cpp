#include<bits/stdc++.h>
using namespace std;
long long n, d, a[100005], b[100005], r, ans, maxn = 99999999, tmp, ru, need;
int main(){
    freopen("road.in" ,  "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i <= n - 1; i ++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++){
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j ++){
            if(b[i] > b[j]){
                need = j - i;
                for(int k = i; k < j; k ++){
                    ru += a[k];
                }
                if((ru - r) % d != 0){
                    tmp = (ru - r) / d +1;
                }
                else{
                    tmp = (ru - r) / d;
                }
                ans += b[i] * tmp;
                r += tmp * d - ru;
                i = j-1;
                ru = 0;
                break;
            }
            if(j == n){
                need = j - i;
                for(int k = i; k < j; k ++){
                    ru += a[k];
                }
                if((ru - r) % d != 0){
                    tmp = (ru - r) / d +1;
                }
                else{
                    tmp = (ru - r) / d;
                }
                ans += b[i] * tmp;
                r += tmp * d - ru;
                i = j;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
