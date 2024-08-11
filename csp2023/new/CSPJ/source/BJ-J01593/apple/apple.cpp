#include<bits/stdc++.h>
using namespace std;
queue <int> q;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    int t = 0;
    int op = 0;
    while(!q.empty()){
        t++;
        int tot = 1;
        int now = 4;
        int l = q.size();
        int flag = 0;
        while(tot <= l){
            int x = q.front();
            q.pop();
            if(now == 4){
                now = 1;
                if(x == n){
                    flag = 1;
                }
            }
            else{
                q.push(x);
            }
            now++;
            tot++;
        }
        if(flag == 1){
            op = t;
        }
    }
    cout << t << ' ' << op;
    return 0;
}

