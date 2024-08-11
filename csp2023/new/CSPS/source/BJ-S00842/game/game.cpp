#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n, b[200005];
char s[200005];
long long ans = 0;
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> s + 1;
    for(int i = 1; i < n; i++){
        for(int len = 1; i + len <= n; len += 2){
            int d = len + 1;
            for(int j = i - 1; j <= i +len +1; j++){
                b[j] = 0;
            }
            int f = -1;
            while(d){
                f = d;
                //cout <<d << " ";
                int last = -1;
                for(int j = i; j <= i + len; j++){
                    if(b[j] == 0){
                        last = j;
                        break;
                    }
                }
                //cout << s[last];
                for(int j = last + 1; j <= i + len; j++){
                    if(b[j] == 1) continue;
                    //cout << s[j];
                    if(s[last] == s[j] && last != j){
                        d -= 2;
                        b[last] = 1;
                        b[j] = 1;
                        for(int x = j + 1; x <= i + len; x++){
                            if(b[x] == 0){
                                last = x;
                                j = x;
                                break;
                            }
                        }
                    } else last = j;
                }
                //cout <<endl;
                if(f == d) break;
            }
            if(d == 0){
                ans++;
                //for(int j = i; j <= i + len; j++) cout << s[j];
                //cout <<endl;
            }
        }
    }
    cout << ans;
    return 0;
}
