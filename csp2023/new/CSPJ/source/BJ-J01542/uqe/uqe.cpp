#include<bits/stdc++.h>
using namespace std;
int gcd(int x, int y){
    while(x){
        int t=x;
        x = y % x;
        y = t;
    }
    return y;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n, t;
    scanf("%d%d",&n,&t);
    while(n--){
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        if(b*b - 4*a*c < 0){
            printf("NO\n");
        }
        else if(c == 0){
            int big = max(2*(0-b), 0);
            if(big == 0){
                printf("0\n");
            }else{
                if((2*(0-b)) % (a * 2) == 0){
                    printf("%d\n",(2*(0-b)) / (2*a));
                }
                else{
                    printf("%d/%d\n",(0-b)/gcd(0-b,a),a/gcd(0-b,a));
                }
            }
        }
        else{
            int sq = sqrt(b*b-4*a*c);
            printf("%d\n",(int)max((int)((0-b)+sq)/(2*a),(int)((0-b)-sq)/(2*a)));
        }
    }
    return 0;
}
