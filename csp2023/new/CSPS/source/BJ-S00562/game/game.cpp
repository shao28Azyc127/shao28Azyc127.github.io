# include<iostream>
# include<algorithm>
# include<cmath>
# include<stack>
# define endl "\n"
# define int long long
using namespace std;
const int maxn=2000001;
int n, f[maxn], ans[maxn], sum=0;
string a;
signed main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(int i=1; i<=n; i++) {
        stack<int> s;
        for(int j=i; j>=1; j--) {
            if(!s.empty() && a[s.top()]==a[j]) {
                s.pop();
                if(s.empty()) sum++;
            } else {
                s.push(j);

        }
    }
    cout << sum << endl;
    return 0;
}
