#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    int m = n;
    int ans = 0;
    while(m){
        ans++;
        int cnt = (m - 1) / 3 + 1;
        m -= cnt;
    }
    cout << ans << " ";
    ans = 0;
    while(n){
        ans++;
        if(n % 3 == 1){
            break;
        }
        int c = (n - 1) / 3 + 1;
        n -= c;
    }
    cout << ans << endl;
    return 0;
}