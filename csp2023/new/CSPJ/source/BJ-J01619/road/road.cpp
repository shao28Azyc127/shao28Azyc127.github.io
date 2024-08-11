
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long juli[maxn + 5];
long long jiage[maxn + 5];
bool v [maxn];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    long long you = 0;
    for(int i = 1; i < n; i++){
        cin >> juli[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> jiage[i];
    }
    long long ans = 0;
    for (int i = 1;i<=n;i++){
        int x = juli[i];
        if(v[i] == 1){
            continue;
        }
        for(int j = i+1;j < n;j++){
            if(jiage[j] >= jiage[i]){
            x += juli[j];
            v[j] = 1;
            }
            else{
                break;
            }
    }
    x -= you;
    x = max(x,0);
    ans += jiage[i] * (x % d==0?x / d:x / d +1);
    you += (x %d == 0?x / d:x / d + 1) * d;
    you -= x;
    }
    cout << ans;
    return 0;
}
