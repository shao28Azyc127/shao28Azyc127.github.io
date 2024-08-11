#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin >> t >> m;
    while(t--){
        double a,b,c;
        cin >> a >> b >> c;
        if(a<0){
            a*=-1;
            b*=-1;
            c*=-1;
        }
        if(b*b-4*a*c<0){
            cout << "NO" << "\n";
            continue;
        }
        cout << max((-1*b+sqrt(b*b-4*a*c))/(2*a),(-1*b-sqrt(b*b-4*a*c))/(2*a)) <<"\n";
    }
}
