#include<iostream>
#include<cmath>
using namespace std;
int a,b,c,t,m,d;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> m;
    while (t--){
        cin >> a >> b >> c;
        d=b*b-4*a*c;
        if (d<0) cout << "NO" << endl;
        else cout << (int(sqrt(d+0.1))-b)/2/a<<endl;
    }
    return 0;
}
