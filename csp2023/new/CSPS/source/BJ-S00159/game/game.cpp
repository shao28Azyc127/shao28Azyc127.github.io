#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
char a[N], s[N];
int n, ans;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf(" %d",&n);
    int k = 0;
    for(int i = 1; i <= n; i++){
        scanf(" %c",&a[i]);
        if(s[k] != a[i]) s[++k] = a[i];
        else{
            s[k--] = '0';
            ans++;
        }
    }
    int all = k;
    for(int i = 1; i <= all; i++){
        if(s[i] == '0') continue;
        if(s[i] == s[i + 1]){
            k -= 2;
            ans++;
            s[i] = s[i + 1] = '0';
        }
    }
    if(k == 0) ans += (n / 4) * (n / 4 - 1) / 2;
    printf("%d",ans);
    return 0;
}
