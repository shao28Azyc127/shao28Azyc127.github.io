#include <iostream>

using namespace std;

long long n;
char c[2000001];
char s[2000001];
int main(){

    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    scanf("%s", s);
    long long ans = 0;
    for (long long i = 0; i < n; i++){
        long long l = 0;
        for (int j = i; j < n; j++){
            if (l && c[l] == s[j]) l--;
            else l++, c[l] = s[j];
            if (l == 0) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
