#include<bits/stdc++.h>
using namespace std;
int t, m, yt;
int q1, q2;
bool yta(int x, int y, int z){ //b2-4ac
    yt = y * y - x * z * 4;
    if(yt < 0) return false;
    else return true;
}
int gcd(int x, int y){ // 最大公因数
    if(x > y) swap(x, y);
    if(x == 0) return y;
    return gcd(x, y % x);
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf(" %d %d",&t,&m);
    while(t--){
        yt = 0, q1 = 0, q2 = 0;
        int a, b, c;
        scanf(" %d %d %d",&a,&b,&c);
        if(!yta(a, b, c)){
            puts("NO");
            continue;
        }
        if(b == 0 && c == 0){
            printf("0\n");
        }
        else if(c == 0){
            if(b / (a * 2) > 0) printf("0/n");
        }
    }
    return 0;
}
