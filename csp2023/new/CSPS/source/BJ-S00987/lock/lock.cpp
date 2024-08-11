#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n , sum , pos , ans;
set<ll>a[10];
ll b[10][10];

void PraseIn(){
    cin >> n;
    for(ll i = 1; i <= n; i++){
        ll c1 = 0 , c2 = 0 , c3 = 0 , c4 = 0 , c5 = 0;
        cin >> c1 >> c2 >> c3 >> c4 >> c5;
        b[i][1] = c1 , b[i][2] = c2;
        a[1].insert(c1);
        a[2].insert(c2);
        a[3].insert(c3);
        a[4].insert(c4);
        a[5].insert(c5);
    }
}
void Core(){
    if(n == 1){
        cout << "81";
        exit(0);
    }
    for(ll i = 1; i <= 5; i++){
        if(a[i].size() != 1){
            sum++;
            if(sum == 1){
                pos = i;
            }
        }
    }
    if(sum == 1){
        if(pos >= 2){
        set<ll>::iterator it1 = a[pos - 1].begin();
        for(ll i = 1; i < pos; i++){
            it1++;
        }
        for(ll i = 0; i <= 9; i++){
            for(ll j = 0; j <= 9; j++){
                bool f1 = 1;
                for(set<ll>::iterator it = a[pos].begin(); it != a[pos].end(); it++){
                    bool flag = 1;
                    for(ll z = -9; z <= 9; z++){
                        ll q1 = i + z , q2 = j + z;
                        if(q1 > 9){
                            q1 -= 10;
                        }
                        if(q2 > 9){
                            q2 -= 10;
                        }
                        if(q1 < 0){
                            q1 += 10;
                        }
                        if(q2 < 0){
                            q2 += 10;
                        }
                        if((*it1) == q1 && (*it) == q2){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag){
                        f1 = 0;
                        break;
                    }
                }
                if(f1){
                    ans++;
                }
            }
        }
        }
    }
    else{

    }
}
void WriteOut(){
    cout << ans;
}
int main(){
    freopen("lock.in" , "r" , stdin);
    freopen("lock.out" , "w" , stdout);
    PraseIn();
    Core();
    WriteOut();
    return 0;
}
