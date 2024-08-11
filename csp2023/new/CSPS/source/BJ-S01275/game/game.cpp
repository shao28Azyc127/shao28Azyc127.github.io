#include<bits/stdc++.h>
using namespace std;
int a[2000005];
struct Node{
    int id, val;
};
int p[2000005];
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        char ch;
        cin >> ch;
        a[i] = ch - 'a';
    }
    if(n <= 8000){
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            stack<int> s;
            for(int j = i; j <= n; j++){
                if(s.empty()) s.push(a[j]);
                else {
                    if(s.top() == a[j]){
                        s.pop();
                    } else {
                        s.push(a[j]);
                    }
                }
                if(s.empty() && i != j){
                    ans++;
                }
            }
        }
        cout << ans;
    } else {
    long long ans = 0;
        for(int i = 1; i <= n; i++){
            stack<int> s;
            for(int j = i; j <= i + 250; j++){
                if(s.empty()) s.push(a[j]);
                else {
                    if(s.top() == a[j]){
                        s.pop();
                    } else {
                        s.push(a[j]);
                    }
                }
                if(s.empty() && i != j){
                    ans++;
                }
            }
        }
        cout << ans;
    }
    return 0;
}
