#include<bits/stdc++.h>
using namespace std;
const int J = 1e6;
char a[2 * J];
long long dp[2 * J];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    long long n;
    cin >> n;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
    }
    dp[1] = 0;
    for(int i = 2;i <= n;i += 1){
        dp[i] = dp[i - 1];
        for(int j = 1;j <= i;j += 1){
            if(a[i] == a[i - j]){
				dp[i]++;
			}
			bool s = 0;
            for(int k = 1;k <= j;k++){
				if(a[i - k] != a[i - j + k]){
					s = 1;
					break;
				}
			}
			if(s == 1 and a[i] == a[i - j])dp[i]--;
        }
        if(i % 1 == 0){
            for(int j = 2;j < i - 1;j += 2){
                bool s = 0;
                for(int k = 1;k + k <= j;k++){
					if(a[k] != a[j - k + 1]){
						s = 1;
						break;
					}
				}
				if(s == 1) continue;
				for(int k = 1;k + k <= i - j;k++){
					if(a[j + k] != a[i - k + 1]){
						s = 1;
						break;
					}
				}
				if(s == 0){ 
					dp[i]++;
				}
            }
        }
        //cout << dp[i] << " " ;
    }
    cout << dp[n] << endl;
    return 0;
}
