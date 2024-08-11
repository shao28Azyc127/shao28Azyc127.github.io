#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e9+10;
int n, ans = 1, an;
bool used[maxn];
bool al(){
    for(int i = 1;i<=n;i++){
        if(!used[i]) return false;
    }
    return true;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    for(int i = 1;i<=n;i++) used[i] = false;
    while(!al()){
        int c=2;
        for(int i = 1;i<=n;i++){
            if(!used[i]){
                c++;
                if(c == 3) {
                    c = 0;
                    used[i] = true;
                }
            }

        }
        if(used[n]!=true) ans++;
        an++;
    }
    cout << an << " " << ans << endl;
    return 0;
}
