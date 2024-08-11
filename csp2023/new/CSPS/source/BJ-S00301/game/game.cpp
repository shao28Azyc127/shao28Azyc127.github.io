#include<iostream>
using namespace std;
int n;
string s;
int ans = 0;
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> s;
    //i:length j:start k:digital
    for(int i = 2; i <= n; i = i + 2){
        for(int j = 0; j <= n - i + 1; j++){
            int count = 0;
            for(int k = 0; k < i / 2; k++){
                if(s[j + k] == s[j + i - k - 1]){
                    count++;
                }
            }
            if(count == i / 2){
                ans++;
                //cout << i << " " << j << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}