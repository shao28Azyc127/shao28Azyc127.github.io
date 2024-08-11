#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
    int T, M;
    cin >> T >> M;
    while(T--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int d = b * b - 4 * a * c;
        if(d < 0)printf("NO\n");
        else{
            int tmp = -b + sqrt(d);
            tmp = tmp / (2 * a);
            //cout << tmp << endl;
            if((a * tmp * tmp + b * tmp + c) == 0){
                printf("%d\n", tmp);
                continue;
            }
            int x = -b, y = 2 * a;
            int z = __gcd(abs(x), abs(y));
            x /= z; y /= z;
            if(x % y == 0 && x / y != 0)cout << x / y;
            else if(x != 0){
                printf("%d/%d", x, y);
            }
            if(sqrt(d) * sqrt(d) == d){
                z = __gcd(abs((int)sqrt(d)), abs(2 * a));
                int t = sqrt(d) / z; y = 2 * a / z;
                if(t % y == 0 && t / y != 0)cout << "+" << t / y << endl;
                else if(y != 0 && t != 0){
                    printf("+%d/%d\n", t, y);
                }
                continue;
            }
            bool flag = false;
            int t = 1;
            for(int i = d; i >= 2; i--){
                if(d % i == 0){
                    if(sqrt(i) * sqrt(i) == i){
                        flag = true;
                        t = t * sqrt(i);
                        d /= i;
                    }
                }
            }
            y = 2 * a; 
            if(flag){
                z = __gcd(abs(2 * a), abs(t));
                y = 2 * a / z; t = t / z;
                if(t / y == 1 && t % y == 0){
                    cout << 1 << endl;
                }else if(t % y == 0 && t / y != 0)cout << "+" << t / y << "*" << "sqrt(" << d << ")" << endl;
                else if(y % t == 0 && y / t != 0)printf("+sqrt(%d)/%d\n", d, y / t);
            }else{
                y = 2 * a;
                for(int i = d; i >= 2; i--){
                    if(d % i == 0 && y % i == 0 && sqrt(i) * sqrt(i) == i){
                        d = d / i; y /= i;
                    }
                }
                printf("+sqrt(%d)/%d\n", d, y);
            }
        }
    }
}
