#include <bits/stdc++.h>

using namespace std;

//
queue<int> q;
int n;

int main(){
    freopen("apple.in" , "r" , stdin);
    freopen("apple.out" , "w" , stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        q.push(i);
    }
    int ans , cnt = 0;
    while (q.size()){
        cnt ++;
        if (q.front() == n) ans = cnt;
        q.pop();
        int len = q.size();
        for (int i = 0 ; i < len - len % 3 ; i += 3){
            q.push(q.front());
            q.pop();
            q.push(q.front());
            q.pop();
            if (q.front() == n) ans = cnt;
            q.pop();
        }
        for (int i = 1 ; i <= len % 3 ; i ++){
            q.push(q.front());
            q.pop();
        }
    }


    cout << cnt << " " << ans << endl;

    return 0;
}
