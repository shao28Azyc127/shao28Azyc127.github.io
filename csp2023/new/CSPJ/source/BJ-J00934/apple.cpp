#include <bits/stdc++.h>
using namespace std;

int cnt = 3, ans1 = -1, ans2;
bool b = 1;
const int N = 1e9+10;
bool a[N];
void solve1(int n)
{
    ans1 = -1;
    ans2 = 0;
    cnt = 3;
    b = 1;
    memset(a+1, 0, n);
    for(int i = 1;b;i++){
        if(b) ans1++;
        b = 0;
        cnt = 3;
        for(int i = 1;i <= n;i++){
            if(a[i] == 0){
                b = 1;
                if(cnt == 3){

                    cnt = 0;
                    a[i] = 1;
                    if(i == n){
                        ans2 = ans1+1;
                    }
                }
                cnt++;
            }
        }
    }
    cout << ans1 << " " << ans2;
}
int solve2(int n){
    int ans = 1;
    while(n){
        ans++;
        n -= (n/3)+1;
    }
    return ans;
}
int solve3(int n){
    if(n == 1) return 1;
    if(n % 9 == 2 || n % 9 == 6) return 2;
    if(n % 27 == 3 || n % 27 == 9 || n % 27 == 17 || n % 27 == 23) return 3;
    return 10;
}
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    if(n <= 1e7)solve1(n);
    else cout << solve2(n) << " " << solve3(n);
    return 0;
}
