#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, M;
    scanf("%d%d", &T, &M);
    for(int i=0; i<T; ++i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (b*b-4*a*c<0) printf("No\n");
        else if (b==0 && c==0) printf("0\n");
        else{
            double ans=max((sqrt(b*b-4*a*c)-b)/2/a, (0-b-sqrt(b*b-4*a*c))/2/a);
            if (int(ans)==ans) printf("%d\n", int(ans));
            else{
                int p, q=1;
                while (int(ans)==ans){
                    ans*=10;
                    q*=10;
                }p=ans;
                while (p%2==0 && q%2==0){
                    p/=2;
                    q/=2;
                }while (p%5==0 && q%5==0){
                    p/=5;
                    q/=5;
                }printf("%d/%d\n", p, q);
            }
        }
    }
    return 0;
}