#include <iostream>
#include <cstring>
using namespace std;
const int N = 8e3 + 5;
bool f[N][N];
int n;
char c[N];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    memset(f, false, sizeof(f));
    int cnt = 0;
    cin >> n >> c;
    for(int len = 2; len <= n; len += 2){
        for(int i = 1; i <= n; i ++){
            int j = i + len - 1;
            if(j != i + 1){
                if(c[i - 1] == c[j - 1] && f[i + 1][j - 1] == true){
                    f[i][j] = true;
                    continue;
                }
                for(int k = i + 1; k <= j - 1; k ++){
                    if(f[i][k] == true && f[k + 1][j] == true){
                        f[i][j] = true;
                        break;
                    }
                }
            }
            else{
                if(c[i - 1] == c[j - 1]){
                    f[i][j] = true;
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int len = 2; len <= n; len += 2){
            int j = i + len - 1;
            if(f[i][j] == true){
                cnt ++;
            }
        }
    }
    cout << cnt;
    return 0;
}
