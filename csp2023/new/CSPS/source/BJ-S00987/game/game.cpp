#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n , ans , ans2;
string s;
ll l , r;
map<ll , ll>las;

void PraseIn(){
    cin >> n >> s;
}
void Core(){
    for(ll i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]){
            l = i - 1 , r = i + 2;
            ans++;
            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    ans++;
                }
                else{
                    l-- , r++;
                    break;
                }
                l-- , r++;
            }
            l++ , r--;
            las[r + 1] += las[l] + 1;
            if(las[l] > 0){
                ans2 += las[l];
            }
        }
    }
}
void WriteOut(){
    cout << ans + ans2;
}
int main(){
    freopen("game.in" , "r" , stdin);
    freopen("game.out" , "w" , stdout);
    PraseIn();
    Core();
    WriteOut();
    return 0;
}
