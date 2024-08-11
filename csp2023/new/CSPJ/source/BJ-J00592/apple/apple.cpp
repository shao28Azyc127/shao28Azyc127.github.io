#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n; cin >> n;
    vector<int> v1, v2;
    for(int i = 1; i <= n; i++) v1.push_back(i);
    int ans1=-1, ans2=0;
    while(!v1.empty()){
        ans2++;
        for(int i = 0; i < v1.size(); i++){
            if(i%3==0) continue;
            v2.push_back(v1[i]);
        }
        swap(v1, v2);
        v2.clear();
        if(v1.empty()) break;
        if(ans1==-1 && v1.back() != n) ans1 = ans2;
    }
    if(ans1==-1) ans1 = ans2;
    cout << ans2 << " " << ans1;
    return 0;
}
