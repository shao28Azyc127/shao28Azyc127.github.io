#include<iostream>
using namespace std;

int k[3005];

bool prime(int x){
    if(x == 1) return false;
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

void xiao(int p, int q){
    bool flag = true;
    if(p < 0) {
        flag = false;
        p *= -1;
    }
    for(int i = 2; i <= min(p,q); i++){
        while(p % i == 0 && q % i == 0){
            p /= i; q /= i;
        }
    }
    if(q == 1){
        if(flag) cout << p;
        else cout << "-" << p;
    }
    else{
        if(flag) cout << p << "/" << q;
        else cout << "-" << p << "/" << q;
    }
    return ;
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int cnt = 0;
    for(int i = 1; i <= 3005; i++){
        if(prime(i)){
            cnt++;
            k[cnt] = i;
        }
    }
    int t,m; cin >> t >> m;
    for(int u = 1; u <= t; u++){
        int a; int b; int c;
        cin >> a >> b >> c;
        int derta = b*b - 4*a*c;
        //cout << derta << " ";
        if(a < 0){
            a *= -1; b *= -1; c *= -1;
        }
        if(derta < 0) {cout << "NO" << endl; continue;}

        if(derta == 0) {
            if(b != 0){
                xiao(-1*b, 2*a);
                cout << endl;
            }
            else {
                cout << 0 << endl;
            }
            continue;
        }
        int j = 1;
        for(int i = 1; i <= cnt; i++){
            int g = 0;
            while(derta % k[i] == 0){
                derta /= k[i];
                g++;
            }
            //cout << g << " ";
            int l = g/2;
            if(g%2 == 1) derta *= k[i];
            for(int r = 1; r <= l; r++){
                j *= k[i];
            }
        }
        //cout << j * j * derta << " ";
        if(derta == 1){
            if(-1*b+j == 0) {cout << 0 << endl; continue;}
            else {xiao(-1*b+j,2*a);
            cout << endl;
            continue;}
        }
        if(b != 0){
            xiao(-1*b,2*a);
            cout << "+";
        }
        int h = 2*a;
        for(int i = 2; i <= min(j,h); i++){
            while(j % i == 0 && h % i == 0){
                j /= i;
                h /= i;
            }
        }
        if(j == 1 && h == 1){
            cout << "sqrt(" << derta << ")";
            cout << endl;
            continue;
        }
        if(j == 1 && h != 1){
            cout << "sqrt(" << derta << ")" << "/" << h << endl;
            continue;
        }
        if(j != 1 && h == 1){
            cout << j << "*" << "sqrt(" << derta << ")" << endl;
            continue;
        }
        if(j != 1 && h != 1){
            cout << j << "*" << "sqrt(" << derta << ")" << "/" << h << endl;
            continue;
        }
    }
    return 0;
}