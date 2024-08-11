#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c,d;
    cin >> t >>m;
    for(int i = 0;i < t;i ++){
        cin >> a >> b >> c;
        d = (a * a) - (4 * b * c);
        if(d < 0){
            cout << "NO" << endl;
            continue;
        }
        else{
            cout <<max((-b + sqrt(d)) / 2 * a,(-b + sqrt(d)) / 2 * a);
        }
    }
    return 0;
}
