#include<bits/stdc++.h>
using namespace std;
const int maxlen = 1000;
int n;
string s;
int sum[maxlen][maxlen];
bool f[maxlen][maxlen];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    cin >> s;
    s = "0" + s;
    for(int i = 1; i <= n; i++) sum[i][1] = 0;
    for(int i = 1; i < n; i++) sum[i][2] = f[i][2] = (s[i] == s[i + 1]);
    for(int i = 3; i <= n; i++){
        for(int j = 1; j <= n - i + 1; j++){
            if(i % 2 == 0){
                f[j][i] = (s[j] == s[j + i - 1]) && f[j + 1][i - 2];
                for(int k = 2; k <= i; k += 2){
                    if(f[j][k] && f[j + k][i - k]){
                        f[j][i] = 1;
                        break;
                    }
                }
            }
            sum[j][i] = sum[j][i - 1] + sum[j + 1][i - 1] - sum[j + 1][i - 2] + int(f[j][i]);
        }
    }
    cout << sum[1][n] << endl;
    return 0;
}