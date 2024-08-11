#include<bits/stdc++.h>
using namespace std;
const long long maxn = 8005;
long long n;
char arr[maxn];
bool isPoss[maxn][maxn];
int main () {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld",&n);
    if(n > maxn) return 0;
    for(long long i = 0; i < n; i++) {
        scanf(" %c",&arr[i]);
    }
    long long ans = 0;
    for(long long i = 0; i < n-1; i++) {
        if(arr[i] == arr[i+1]) {
            ans++;
            isPoss[i][i+1] = true;
        }
    }
    for(long long i = 3; i < n; i += 2) {
        for(long long j = 0; j < n-i; j++) {
            long long lP = j;
            long long rP = j+i;
            if(arr[lP] == arr[rP] && isPoss[lP+1][rP-1] == true) {
                isPoss[lP][rP] = true;
                ans++;
            }
            else {
                for(long long l = lP+1; l < rP; l += 2) {
                    if(isPoss[lP][l] == true && isPoss[l+1][rP] == true) {
                        isPoss[lP][rP] = true;
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
