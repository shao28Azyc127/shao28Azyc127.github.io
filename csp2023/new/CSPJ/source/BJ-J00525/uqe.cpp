#include<bits/stdc++.h>
using namespace std;
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> m;
    while(t --){
        int a,b,c;
        cin >> a >> b >> c;
        int san = b * b - 4 * a * c;
        if(san < 0) cout << "NO\n";
        else{
            cout << max((-b + sqrt(san)) / (2 * a),(-b - sqrt(san)) / (2 * a)) << '\n';
        }
    }

    return 0;
}
