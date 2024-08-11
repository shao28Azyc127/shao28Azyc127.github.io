#include<bits/stdc++.h>
using namespace std;
int n;
struct mim{
    int a, b, c, d, e;
}A[10];
bool check1(int f1, int f2, int k1, int k2){
    if(k1 < f1) k1 += 10;
    if(k2 < f2) k2 += 10;
    if(k1 - f1 == k2 - f2){
        return true;
    }else return false;
}
bool check2(int f1, int f2, int k1, int k2){
    if(k1 > f1) f1 += 10;
    if(k2 > f2) f2 += 10;
    if(f1 - k1 == f2 - k2){
        return true;
    }else return false;
}
bool good(mim f, mim k){
    int boss = 0;
    if(f.a != k.a) boss++;
    if(f.b != k.b) boss++;
    if(f.c != k.c) boss++;
    if(f.d != k.d) boss++;
    if(f.e != k.e) boss++;
    if(boss >= 3){
        return false;
    }
    if(boss == 1){
        return true;
    }else if(boss == 2){
        int bt1, bt2;
        bool fdbt1 = true, fdbt2 = true;
        if(f.a != k.a && fdbt1) bt1 = 1, fdbt1 = false;
        if(f.b != k.b && fdbt1) bt1 = 2, fdbt1 = false;
        if(f.c != k.c && fdbt1) bt1 = 3, fdbt1 = false;
        if(f.d != k.d && fdbt1) bt1 = 4, fdbt1 = false;
        if(f.e != k.e && fdbt1) bt1 = 5, fdbt1 = false;
        if(f.a != k.a && fdbt2 && bt1 != 1) bt2 = 1, fdbt2 = false;
        if(f.b != k.b && fdbt2 && bt1 != 2) bt2 = 2, fdbt2 = false;
        if(f.c != k.c && fdbt2 && bt1 != 3) bt2 = 3, fdbt2 = false;
        if(f.d != k.d && fdbt2 && bt1 != 4) bt2 = 4, fdbt2 = false;
        if(f.e != k.e && fdbt2 && bt1 != 5) bt2 = 5, fdbt2 = false;
        if(abs(bt1-bt2) != 1) return false;
        int val1, val2;
        int VAL1, VAL2;
        if(bt1 == 1) val1 = f.a, VAL1 = k.a;
        if(bt1 == 2) val1 = f.b, VAL1 = k.b;
        if(bt1 == 3) val1 = f.c, VAL1 = k.c;
        if(bt1 == 4) val1 = f.d, VAL1 = k.d;
        if(bt1 == 5) val1 = f.e, VAL1 = k.e;
        if(bt2 == 1) val2 = f.a, VAL2 = k.a;
        if(bt2 == 2) val2 = f.b, VAL2 = k.b;
        if(bt2 == 3) val2 = f.c, VAL2 = k.c;
        if(bt2 == 4) val2 = f.d, VAL2 = k.d;
        if(bt2 == 5) val2 = f.e, VAL2 = k.e;
        if(check1(val1, val2, VAL1, VAL2) || check2(val1, val2, VAL1, VAL2)){
            return true;
        }else{
            return false;
        }
    }else if(boss == 0){
        return false;
    }
    return true;
}
bool check(mim f){
    bool flag = true;
    for(int i = 1; i <= n; i++){
        if(good(f, A[i])){
            flag &= true;
        }else{
            flag &= false;
        }
    }
    return flag;
}
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> A[i].a >> A[i].b >> A[i].c >> A[i].d >> A[i].e;
    }
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= 9; k++){
                for(int l = 0; l <= 9; l++){
                    for(int m = 0; m <= 9; m++){
                        mim f;
                        f.a = i;
                        f.b = j;
                        f.c = k;
                        f.d = l;
                        f.e = m;
                        if(check(f)){
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
