#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n , sum , cnt = -1;
string bb[105][105];
ll b[105][2];
map<string , ll>a;
string c[100005];

void PraseIn(){
    cin >> n;
}
void Core(){
    while(n--){
        ll cur = 0;
        cin >> cur;
        if(cur == 1){
            ll cc = 0;
            string s1 , s;
            cin >> s1 >> cc;
            sum++;
            a[s1] = sum;
            b[sum][0] = cc;
            ll maxn = 0;
            for(ll i = 1; i <= cc; i++){
                cin >> s >> bb[sum][i];
                if(s == "byte"){
                    maxn = max(maxn , (ll)1);
                }
                else if(s == "short"){
                    maxn = max(maxn , (ll)2);
                }
                else if(s == "int"){
                    maxn = max(maxn , (ll)4);
                }
                else if(s == "long"){
                    maxn = max(maxn , (ll)8);
                }
                else{
                    maxn = max(maxn , b[a[s]][1]);
                }
            }
            b[sum][1] = maxn;
            cout << cc * maxn << " " << maxn << endl;
        }
        else if(cur == 2){
            string s , s1;
            ll pos = 0;
            cin >> s >> s1;
            cout << cnt + 1 << endl;
            for(ll i = cnt + 1; i <= cnt + b[a[s]][0] * b[a[s]][1]; i++){
                c[i] = s1;
                c[i] += ".";
                c[i] += bb[a[s]][1 + (pos / b[a[s]][1])];
                pos++;
            }
            cnt += b[a[s]][0] * b[a[s]][1];
        }
        else if(cur == 3){
            string s;
            cin >> s;
            for(ll i = 0; i; i++){
                cout << c[i] << endl;
                if(s == c[i]){
                    cout << i << endl;
                    break;
                }
            }
        }
        else{
            ll cc = 0;
            cin >> cc;
            cout << c[cc];
        }
    }
}
void WriteOut(){

}
int main(){
    freopen("struct.in" , "r" , stdin);
    freopen("struct.out" , "w" , stdout);
    PraseIn();
    Core();
    WriteOut();
    return 0;
}
