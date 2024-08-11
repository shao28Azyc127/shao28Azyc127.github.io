#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<string,int> mp;

bool chk(string a){
    if (a.size() % 2 == 1) return 0;
    while (1){
        ll dos = 0;
        for (ll i = 0; i < a.size(); i++){
            if (a[i] == a[i+1]){
                a.erase(i,2);
                dos++;
            }
        }
        //cout << a << endl;
        if (dos == 0 && !a.empty())return 0;
        if (a.empty())return 1;
    }
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ll n;
    scanf("%lld",&n);
    string a;
    cin >> a;
    ll sum = 0;
    for (int i = 0; i < a.size();i++){
        for (int j = 1; (j+i) <= a.size(); j++){
            //cout << a.substr(i,j) << endl;
            if (mp[a.substr(i,j)] == 1 || chk(a.substr(i,j))){
                    mp[a.substr(i,j)] = 1;
                //cout << a.substr(i,j) << endl;
                sum++;
            }
        }
    }
    //cout << chk("aaaa");
    cout << sum;
    return 0;
}
