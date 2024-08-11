#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int M;
bool is_prime(int x){
    if(x < 2) return false;
    for(int i=2;i<=x/i;i++){
        if(x % i == 0) return false;
    }
    return true;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t;
    scanf("%d %d",&t,&M);
    while(t -- ){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int deta = b * b - 4 * a * c;
        if(deta < 0){
            puts("NO");
            continue;
        }
        int sq = sqrt(deta);
        if(sq * sq == deta){
            if(is_prime(sq)){
                printf("%d\n",sq);
                continue;
            }
        }
    }
    return 0;
}
