#include <bits/stdc++.h>
using namespace std;
int n, a[1000005];
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    int ge = 0, x = 1;
    int pos, h = 1;
    for(int i = 1; ge != n; i++){
        if(i > n){
            i %= n;
            x = 1;
            h++;
        }//new line
        if(a[i] == 1) continue;//jump
        if(x > 3) x %= 3;//cycle
        if(x == 1){//get
            ge++;
            a[i] = 1;
        }
        x++;
        if(i == n) pos = h;
    }
    //cout << h <<" " << pos;
    printf("%d %d",h,pos);
    return 0;
}