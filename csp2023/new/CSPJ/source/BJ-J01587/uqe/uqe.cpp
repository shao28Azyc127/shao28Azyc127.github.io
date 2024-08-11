#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL NR = 1e3;
LL v[NR + 10];
LL a[NR + 10];
pair<int, int> hj(int p, int q){
    if(p == 0 || q == 0) return make_pair(p, q);
    int tmp = __gcd(p, q);
    if(tmp != 0){
        p /= tmp;
        q /= tmp;
    }
    if(p < 0 && q < 0){
        p *= -1;
        q *= -1;
    }
    if(p > 0 && q < 0){
        p *= -1;
        q *= -1;
    }
    return make_pair(p, q);
}
bool check(int x){
    int tmp = sqrt(x);
    return tmp * tmp == x;
}
void print(pair<int, int> x){
    if(x.first == 0){
        printf("0");
        return ;
    }
    x = hj(x.first, x.second);
    if(x.second == 1){
        printf("%d", x.first);
    }
    else{
        printf("%d/%d", x.first, x.second);
    }
}
int flag[NR + 10];
void fjzys(int x){
    memset(flag, 0, sizeof(flag));
    for(int i = 2;i <= x;i++){
        if(x == 1) break;
        while(x > 1 && x % i == 0){
            flag[i]++;
            x /= i;
        }
    }
}

int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, limit;
    scanf("%d%d", &T, &limit);
    while(T--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int d = b * b - 4 * a * c;
        if(d < 0){
            printf("NO\n");
            continue;
        }
        if(d == 0){
            int p = 0 - b;
            int q = 2 * a;
            print(make_pair(p, q));
            printf("\n");
            continue;
        }
        else{
            if(check(d)){
                int p = sqrt(d) - b;
                int q = 2 * a;
                print(make_pair(p, q));
                printf("\n");
            }
            else{
                int p1 = 0 - b;
                int q1 = 2 * a;
                if(p1 != 0){
                    print(make_pair(p1, q1));
                    printf("+");
                }
                int p2 = 1;
                int q2 = 2 * a;
                int r;
                fjzys(d);
                for(int i = 2;i <= d;i++){
                    while(flag[i] >= 2){
                        p2 *= i;
                        flag[i] -= 2;
                    }
                }
                printf("%d\n", p2);
                r = d / p2;
                pair<int, int> tmp = hj(p2, q2);
                p2 = tmp.first;
                q2 = tmp.second;
                if(p2 == 1 && q2 == 1){
                    printf("sqrt(%d)\n", r);
                }
                else if(q2 == 1){
                    printf("%d*sqrt(%d)\n", p2, r);
                }
                else if(p2 == 1){
                    printf("sqrt(%d)/%d\n", r, q2);
                }
                else{
                    printf("sqrt(%d)/", r);
                    print(make_pair(p2, q2));
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
/*
1000 1000
1 0 ©\432
*/
