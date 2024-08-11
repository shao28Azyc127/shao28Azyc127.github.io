#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long LL;
LL n,t,cnt,ans=0;
//2.5 5 13 38
queue<LL> q;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    t = n;
    while(t){
        t = t * 2 / 3;
        ++cnt;
    }
    if(n%3 == 1){
        cout << cnt << ' ' << 1 << endl;
        return 0;
    }
    for(int i = 1; i <= n; ++i) q.push(i);
    while(1){
        ++ans;
        //cout << q.front() << endl;
        for(int i = 1; i <= q.size(); ++i){
            //cout << q.front() << endl;
            if(i%3 == 1){
                //cout << q.front() << endl;
                if(q.front() == n){
                    cout << cnt << ' ' << ans << endl;
                    return 0;
                }
                q.pop();

            }
            else{
                q.push(q.front());
                q.pop();
            }
        }
    }

    return 0;
}
