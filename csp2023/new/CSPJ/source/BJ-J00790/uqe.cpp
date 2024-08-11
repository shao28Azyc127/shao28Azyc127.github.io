#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int t,m,a,b,c;

bool isZheng(double x){
    int a = x;
    double y = x - a;
    if(y == 0) return 1;
    return 0;
}
int gcd(int x,int y){
    if(x > y) swap(x,y);
    if(x == 0) return y;
    return gcd(y % x,x);
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> m;
    while(t--){
        cin >> a >> b >> c;
        int delta = b * b - 4 * a * c;
        if(delta < 0){
            cout << "NO" << endl;
            continue;
        }
        if(isZheng(sqrt(delta))){
            double jie = (int(sqrt(delta)) - b) * 1.0 / (2 * a);
            if(isZheng(jie)) cout << int(jie) << endl;
            else{
                int k = gcd(int(sqrt(delta)) - b,2 * a);
                int h = (int(sqrt(delta)) - b) / k,j = 2 * a / k;
                if(j < 0) h = -h,j = -j;
                cout << h << '/' << j << endl;
            }
        }
    }
    return 0;
}
