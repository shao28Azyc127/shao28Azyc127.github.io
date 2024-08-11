#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans;
bool f = 0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(n){
        cnt++;
        if(!f && n % 3 == 1)
            f = 1,ans = cnt;
        int x = n % 3;
        n = n / 3 * 2 + (x ? x - 1 : 0);
    }
    printf("%d %d\n",cnt,ans);
    return 0;
}