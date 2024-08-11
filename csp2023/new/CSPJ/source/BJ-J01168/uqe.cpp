#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
bool isint(double a){
    if(a/1.0==0.0) return true;
    else return false;
}
int maxx(int a,int b){
    for(int i = min(a,b);i>=1;i--){
        if(a%i==0 && b%i==0) return i;
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a[5028],b[5028],c[5028],delta[5028];
    int up[5028];
    int n , m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i] >> b[i] >> c[i];
        delta[i] = b[i]*b[i]-4*a[i]*c[i];
        if(delta[i] < 0) cout << "NO" << endl;
        else{
            if(isint(sqrt(delta[i]))){
                if(isint(((0-b[i]) + sqrt(delta[i]))/(a[i]*2))) cout << ((0-b[i]) + sqrt(delta[i]))/(a[i]*2) << endl;
                else{
                    up[i] = ((0-b[i]) + sqrt(delta[i]));
                    cout << up[i]/maxx(up[i],a[i]*2) << "/" << a[i*2]/maxx(up[i],a[i]*2) << endl;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
