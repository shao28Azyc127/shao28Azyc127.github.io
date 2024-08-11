#include <bits/stdc++.h>
using namespace std;
int n,ans;
bool flag = 0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    int j = 0;
    while (n){
        int tmp = n;
        for (int i = 1;i <= n;i += 3){
            if (i == n&&!flag){
                ans = j + 1;
                flag = 1;
            }
            tmp--;
        }
        j++;
        n = tmp;
    }
    printf("%d %d",j,ans);
    return 0;
}
