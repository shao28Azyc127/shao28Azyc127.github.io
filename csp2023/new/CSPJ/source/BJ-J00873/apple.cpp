#include<iostream>
#include<algorithm>
using namespace std;
int n, ans = 0, rnd = 0;
int main()
{
        freopen("apple.in", "r", stdin);
        freopen("apple.out", "w", stdout);
        cin >> n;
        while(n != 0) {
                ans++;
                if(n % 3 == 1 && rnd == 0) rnd = ans;
                n = n - (n + 2) / 3;
        }
        cout << ans << " " << rnd << endl;
        return 0;
}