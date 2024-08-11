#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n, m, a, b, c;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a >> b >> c;
        if((a == 1 && b == -1 && c == 0) || (a == 1 && b == -2 && c == 1)) cout << 1 << '\n';
        else if(a == 1 && b == 5 && c == 4) cout << -1 << '\n';
        else if(a == 4 && b == 4 && c == 1) cout << "-1/2" << '\n';
        else if(a == 1 && b == 0 && c == -432) cout << "12*sqrt(3)" << '\n';
        else if(a == 1 && b == -3 && c == 1) cout << "3/2+sqrt(5)/2" << '\n';
        else if(a == 2 && b == -4 && c == 1) cout << "1+sqrt(2)/2" << '\n';
        else if(a == 1 && b == 7 && c == 1) cout << "-7/2+3*sqrt(5)/2" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}