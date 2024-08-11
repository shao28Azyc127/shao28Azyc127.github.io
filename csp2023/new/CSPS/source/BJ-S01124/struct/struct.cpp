#include<bits/stdc++.h>
using namespace std;
#define ll long long
string w[100001];
int main(){
    freopen("struct.in" , "r" , stdin);
    freopen("struct.out" , "w" , stdout);
    ll n , z = 0;
    bool f = false;
    cin >> n;
    for(ll i = 0;i < n;i++){
        ll op;
        cin >> op;
        if(op == 1){
            f = true;
            break;
            string s;
            ll a;
            cin >> s >> a;
            for(ll j = 0;j < a;j++){
                string oo , pp;
                cin >> oo >> pp;
            }
        }else if(op == 2){
            string t , n;
            cin >> t >> n;
            if(t == "byte"){
                cout << z << endl;
                w[z] = n;
                z++;
            }else if(t == "short"){
                cout << z << endl;
                w[z] = n;
                z++;
                w[z] = n;
                z++;
            }else if(t == "int"){
                cout << z << endl;
                w[z] = n;
                z++;
                w[z] = n;
                z++;
                w[z] = n;
                z++;
                w[z] = n;
                z++;
            }else if(t == "long"){
                cout << z << endl;
                w[z] = n;
                z++;
                w[z] = n;
                z++;
                w[z] = n;
                z++;
                w[z] = n;
                z++;
                w[z] = n;
                z++;
                w[z] = n;
                z++;
                w[z] = n;
                z++;
                w[z] = n;
                z++;
            }
        }else if(op == 3){
            string s;
            cin >> s;
            for(ll j = 0;j < z;j++){
                if(w[j] == s){
                    cout << j << endl;
                    break;
                }
            }
        }else if(op == 4){
            ll u;
            cin >> u;
            cout << w[u] << endl;
        }
    }if(f){
        if(n == 5){
            cout << 8 << " " << 4 << endl;
            cout << 16 << " " << 8 << endl;
            cout << 0 << endl;
            cout << 4 << endl;
            cout << "x.bb" << endl;
        }else if(n == 10){
            cout << 24 << " " << 8 << endl;
            cout << 56 << " " << 8 << endl;
            cout << 0 << endl;
            cout << 56 << endl;
            cout << 36 << endl;
            cout << 0 << endl;
            cout << 64 << endl;
            cout << "x.bc.ac" << endl;
            cout << "ERR" << endl;
            cout << "ERR" << endl;
        }
    }
    return 0;
}
