#include <cstdio>
#include <utility>
using namespace std;
int t,m,a,b,c,dt,tmp,tmp2;
pair <int,int> rl;
int check(int x){
    int l = 0,r = x,mid;
    while(l <= r){
        mid = l + r >> 1;
        if(1LL * mid * mid == x){
            return mid;
        }
        else if(1LL * mid * mid < x){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return -1;
}
int myabs(int x){
    return x > 0 ? x : -x;
}
int gcd(int x,int y){
    return y ? gcd(y,x % y) : x;
}
pair <int,int> getr(int p,int q){
    int tg = gcd(myabs(p),myabs(q));
    if((p < 0 && q < 0) || (p > 0 && q > 0)){
        p = myabs(p) / tg;
        q = myabs(q) / tg;
    }
    else{
        p = -myabs(p) / tg;
        q = myabs(q) / tg;
    }
    return make_pair(p,q);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        dt = b * b - 4 * a * c;
        if(dt < 0){
            printf("NO\n");
        }
        else{
            tmp = check(dt);
            a *= 2;
            if(tmp >= 0){
                if(a < 0){
                    a = -a;
                    b = -b;
                }
                tmp -= b;
                rl = getr(tmp,a);
                if(rl.second == 1){
                    printf("%d\n",rl.first);
                }
                else{
                    printf("%d/%d\n",rl.first,rl.second);
                }
            }
            else{
                if(a < 0){
                    a = -a;
                    b = -b;
                }
                if(b){
                    rl = getr(-b,a);
                    if(rl.second == 1){
                        printf("%d+",rl.first);
                    }
                    else{
                        printf("%d/%d+",rl.first,rl.second);
                    }
                }
                tmp2 = 1;
                for(int i = 2;i * i <= dt;i++){
                    while(!(dt % (i * i))){
                        tmp2 *= i;
                        dt /= i * i;
                    }
                }
                rl = getr(tmp2,a);
                if(rl.second == 1){
                    if(rl.first == 1){
                        printf("sqrt(%d)\n",dt);
                    }
                    else{
                        printf("%d*sqrt(%d)\n",rl.first,dt);
                    }
                }
                else if(rl.first == 1){
                    printf("sqrt(%d)/%d\n",dt,rl.second);
                }
                else{
                    printf("%d*sqrt(%d)/%d\n",rl.first,dt,rl.second);
                }
            }
        }
    }
    return 0;
}
