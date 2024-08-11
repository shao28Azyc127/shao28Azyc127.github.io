#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int qpqpqpqp, wertyuu;
void hua_jian(int a, int b){
    int c = 1;
    if(a < 0){
        a = a * -1;
        c = -1;
    }
    if(b < 0){
        b = b * -1;
        c *= -1;
    }
    for(int i = 2;i <= a;i++){
        while(a % i == 0 && b % i == 0){
            a = a / i;
            b = b / i;
        }
    }
    if(b == 1) cout << c*a;
    else cout << c*a << "/" << b;
}
void kai_fang(int a, int b){
    int ans = 1;
    for(int i = 2;i * i <= a;i++){
        while(a % (i*i) == 0){
            a = a / i / i;
            ans *= i;
        }
    }
    int c = 1;
    if(b < 0){
        b = b * -1;
        c *= -1;
    }
    for(int i = 2;i <= ans;i++){
        while(ans % i == 0 && b % i == 0){
            ans = ans / i;
            b = b / i;
        }
    }
    if(b == 1 && c * ans != 1) cout << c*ans << "*sqrt(" << a << ")";
    else if(c * ans == 1 * b == 1) cout << "sqrt(" << a << ")";
    else if(c * ans != 1 * b == 1) cout << "sqrt(" << a << ")/" << b;
    else cout << c*ans << "*sqrt(" << a << ")" << "/" << b;
}
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> qpqpqpqp >> wertyuu;
    for(int qpqpqp = 1;qpqpqp <= qpqpqpqp;qpqpqp++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int tryangle = b * b - 4 * a * c;
        if(tryangle < 0){
            cout << "NO";
        }
        else{
            if(b != 0){
                if(((int)sqrt(tryangle)) * ((int)sqrt(tryangle)) == tryangle){
                    hua_jian(sqrt(tryangle)-b, 2*a);
                }
                else{
                    hua_jian(-b, 2*a);
                    cout << "+";
                    kai_fang(tryangle, 2*a);
                }
            }
            if(((int)sqrt(tryangle)) * ((int)sqrt(tryangle)) == tryangle && b == 0){
                hua_jian(sqrt(tryangle), 2*a);
            }
            else if(((int)sqrt(tryangle)) * ((int)sqrt(tryangle)) != tryangle && b == 0) {kai_fang(tryangle, 2*a);}
        }
        cout << endl;
    }
    return 0;
}

