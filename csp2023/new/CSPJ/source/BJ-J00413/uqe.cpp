#include<iostream>
#include<cmath>
using namespace std;
int T = 0, M = 0;
int gcd(int x, int y){
    int yu = 0;
    if(x < y){
        int z = x;
        x = y;
        y = z;
    }
    for(int i = 1; true; i++){
        yu = x % y;
        if(yu == 0){
            return y;
        }
        if(yu == 1){
            return 1;
        }
        x = y;
        y = yu;
    }
}
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> M;
    for(int i = 1; i <= T; i++){
        int a, b, c;
        cin  >> a >> b >> c;
        int delta = b * b - 4 * a * c;
        if(delta < 0){
            cout << "NO" << endl;
        }else{
            if(sqrt(delta) == (int)(sqrt(delta))){
                int num;
                if(a > 0){
                    num = sqrt(delta) - b;
                }else{
                    num = 0 - sqrt(delta) - b;
                }
                if(num % (2 * a) == 0){
                    cout << num / (2 * a) << endl;
                }else{
                    int yin = gcd(num, 2 * a);
                    cout << num / yin << "/" << 2 * a / yin << endl;
                }
            }else{
                if(gcd(-b, 2 * a) == 2 * a){
                    if(a > 0){
                        cout << -b / (2 * a) << "+sqrt(" << delta << ")/" << 2 * a << endl;
                    }else{
                        cout << -b / (2 * a) << "-sqrt(" << delta << ")/" << -2 * a << endl;
                    }
                }else{
                    if(a > 0){
                        if(b > 0){ 
            
                        }else if(b == 0){

                        }else{

                        }
                    }else{
                        if(b > 0){

                        }else if(b == 0){

                        }else{

                        }
                    }
                }
            }
        }
    }
    return 0;
}