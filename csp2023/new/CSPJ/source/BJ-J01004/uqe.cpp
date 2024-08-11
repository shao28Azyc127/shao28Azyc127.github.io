#include <iostream>
using namespace std;

int gcd(int a, int b){
    while(a != 0 && b != 0){
        a %= b;
        swap(a, b);
    }

    if(a == 0){
        return b;
    }else if(b == 0){
        return a;
    }
}

int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    int t;
    cin >> t;

    while(t--){
        int a;
        int b;
        int c;
        cin >> a >> b >> c;

        //解：a*x^2 + b*x = -c;
        //骗分:
        //c = 0;
        if(c == 0){
            //x(b + ax) = 0;
            //解1：x = 0;
            //解2：ax = -b
            //=> :x = -b/a;
            if(a == 0){
                cout << "NO" << endl;
                continue;
            }
            if(-b % a == 0){
                cout << max(-b/a, 0) << endl;
            }else{
                if(-b / a <= 0){
                    cout << 0 << endl;
                }else{
                    int GCD = gcd(a, b);

                    cout << b/GCD << "/" << a/GCD << endl;
                }
            }
        }
        //b = 0;
        if(b == 0){
            //a*x*x = -c
            //x*x = -c/a;
            if(-c/a < 0){
                cout << "NO" << endl;
                continue;
            }
            int x = sqrt(-c/a);

            if(x * x == -c/a){
                cout << x << endl;
            }
        }
    }
    return 0;
}
