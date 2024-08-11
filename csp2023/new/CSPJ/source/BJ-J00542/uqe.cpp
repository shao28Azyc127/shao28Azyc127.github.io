#include<iostream>
#include<math.h>

using namespace std;

int n, m;
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    gcd(b, a % b);
}

string charge(int v){
    string s, ret;
    while(v){
        s += v % 10;
        v /= 10;
    }
    for(int i = s.length() - 1; i >= 0; i++){
        ret += s[i];
    }
    return ret;
}

double sqrt1(int v){
    if(sqrt(v) == (int)(sqrt(v))) ;
    else{
        //return -
    }
}

void decode(int a, int b, int c){
    int tr = b * b - 4 * a * c;
    int fm = 2 * a;
    int fz = -b;
    if(tr < 0) cout << "NO" << endl;
    else if(tr == 0){
        int gc = gcd(max(abs(fz), abs(fm)), min(abs(fm), abs(fz)));
        if(fz * fm > 0){
            if(gc == abs(fm)) cout << abs(fm) / abs(fz) << endl;
            else cout << abs(fz)/gc << "/" << abs(fm)/gc << endl;
        }
        else if(fz != 0){
            if(gc == abs(fm)) cout << -abs(fm) / abs(fz) << endl;
            else cout << "-" << abs(fz)/gc << "/" << abs(fm)/gc << endl;
        }
    }
    else{
        int gc = gcd(max(abs(fz), abs(fm)), min(abs(fm), abs(fz)));
        if(fz * fm > 0){
            if(gc == abs(fm)) cout << abs(fm) / abs(fz);
            else cout << abs(fz)/gc << "/" << abs(fm)/gc;
        }
        else if(fz != 0){
            if(gc == abs(fm)) cout << -abs(fm) / abs(fz);
            else cout << "-" << abs(fz)/gc << "/" << abs(fm)/gc;
        }
        cout << "+" << "sqrt(" << tr << ")/" << fm << endl;
    }
}
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        decode(a, b, c);
    }
    return 0;
}
