#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        int z = b * b - 4 * a * c;
        cout << "NO" << endl;
        double xone = (b * -1) + sqrt(z);
        double xtwo = (b * -1) - sqrt(z);
    }
    return 0;
}
