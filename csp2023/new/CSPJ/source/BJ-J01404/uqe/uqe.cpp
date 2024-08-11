#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n , m;
ll a , b , c , ans1 , ans2;
ll ping[10005];

void PraseIn(){
    cin >> a >> b >> c;
    ans1 = 0 , ans2 = 0;
}
void WriteOut(){
    if(ans1 == 0){
        return;
    }
    if(ans2 == 1){
        cout << ans1;
    }
    else{
        cout << ans1 << "/" << ans2;
    }
}
void Core1(ll d , ll e){
    ll sum1 = 0 , sum2 = 0;
    if(e == 0){
        return;
    }
    if(d < 0){
        d = -d;
        e = -e;
    }
    ll cc = __gcd((e > 0 ? e : -e) , (d > 0 ? d : -d));
    e /= cc;
    d /= cc;
    sum1 = e , sum2 = d;
    if(ans2 == 0){
        ans1 = sum1 , ans2 = sum2;
    }
    else{
        ll lm = ans2 * sum2 / (__gcd(ans2 , sum2));
        ll ls = lm / sum2;
        ll la = lm / ans2;
        ans2 = lm;
        sum1 *= ls;
        ans1 *= la;
        ans1 += sum1;
        ll cc = __gcd(ans2 > 0 ? ans2 : -ans2 , ans1 > 0 ? ans1 : -ans1);
        if(cc != 1){
            ans1 /= cc , ans2 /= cc;
        }
    }
}
void Core2(){
    ll cc = b * b - 4 * a * c;
    if(cc == (int(sqrt(cc)) * int(sqrt(cc)))){
        ll s1 = sqrt(cc);
        if(a > 0){
            Core1(2 * a , s1);
        }
        else{
            Core1(2 * a , -s1);
        }
        WriteOut();
        if(ans1 == 0){
            cout << "0";
        }
    }
    else{
        WriteOut();
        if(ans1)    cout << "+";
        ll c1 = lower_bound(ping + 1 , ping + 1 + m , cc) - ping;
        ll s1 = 1;
        for(ll i = c1; i >= 1; i--){
            if(cc % ping[i] == 0){
                cc /= ping[i];
                s1 *= sqrt(ping[i]);
            }
        }
        ans1 = 0 , ans2 = 0;
        if(a > 0){
            Core1(2 * a , s1);
        }
        else{
            Core1(2 * a , -s1);
        }
        if(ans1 == 1){
            if(ans2 == 1){
                cout << "sqrt(" << cc << ")";
            }
            else cout << "sqrt(" << cc << ")/" << ans2;
        }
        else{
            if(ans2 == 1){
                cout << ans1 << "*sqrt(" << cc << ")";
            }
            else cout << ans1 << "*sqrt(" << cc << ")/" << ans2;
        }
    }
}
void Core(){
    ll cc = b * b - 4 * a * c;
    if(cc < 0){
        cout << "NO";
    }
    else{
        Core1(2 * a , -b);
        Core2();
    }
}

int main(){
    freopen("uqe.in" , "r" , stdin);
    freopen("uqe.out" , "w" , stdout);
    cin >> n >> m;
    for(ll i = 1; i <= 5 * m; i++){
        ping[i] = i * i;
    }
    while(n--){
        PraseIn();
        Core();
        cout << endl;
    }
    return 0;
}
