#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m, a, b, c;
    bool f = false;
    cin>>t>>m;
    for(int i = 1; i <= t; i++){
        cin>>a>>b>>c;
        if(b * b < 4 * a * c){
            cout<<"NO"<<endl;
        }else{
            int x = ((sqrt(b * b - 4 * a * c) - b) / (2 * a));
            if(x % 1 == 0){
                cout<<x<<endl;
            }else{
                int y;
                if(x < 0){
                    y = -x;
                }
                for(int j = 1; j <= 10; j++){
                    for(int k = 1; k <= 10; k++){
                        if(y == j / k){
                            if(x < 0){
                                cout<<"-";
                            }
                            cout<<j<<"/"<<k<<endl;
                            f = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}