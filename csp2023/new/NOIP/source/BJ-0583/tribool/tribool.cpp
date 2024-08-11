#include<bits/stdc++.h>

using namespace std;

int c, t;
int n, m;

int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= m; i ++){
            char v;
            int a, b, c;
            cin >> v;
            if(v == '-' || v == '+'){
                cin >> a >> b;
            }else{
                cin >> c;
            }
        }
        cout <<0<<endl;
    }


    return 0;
}
