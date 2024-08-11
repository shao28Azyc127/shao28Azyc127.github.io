#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ll a;
    cin >> a;
    queue<ll> q;
    for(ll i=1;i <= a;i++){
 //           cout << "#1" << endl;
        q.push(i);
    }
    ll days = 0;
    ll ans;
    while(!q.empty()){
 //       cout << "#2" << endl;
        days++;
        if(q.front() == a){
            ans = days;
        }
        q.pop();
        ll cnt = 0;
        ll size = q.size();
        for(ll i = 0;i < size;i++){
            cnt++;
            if(cnt == 3){
                cnt = 0;
                if(q.front() == a){
                    ans = days;
                }
            }
            else{
                q.push(q.front());
            }
            q.pop();
        }
    }
    cout << days << " " << ans;
    //printf("%lld %lld",days,ans);
    return 0;
}
