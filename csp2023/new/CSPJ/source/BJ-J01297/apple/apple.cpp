#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
int n, cnt, ans;
bool v[N];
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    int j = 1;
    while(cnt < n) {
        int x = 0;
        for(int i = 1;i <= n;i ++) {
            if(v[i]) continue;
            if(x == 0) {
                x ++;
                v[i] = true;
                cnt ++;
                if(i == n) ans = j;
            } else {
                if(x == 1) x ++;
                else if(x == 2) x = 0;
            }
        }
        j ++;
    }
    printf("%d %d\n", j - 1, ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
