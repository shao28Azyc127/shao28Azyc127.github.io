#include <bits/stdc++.h>
using namespace std;
int ans,cnt = 0;
bool getans = 0;
int take(int n){
    if(!getans){
        cnt++;
        if(n%3==1)  {
            ans = cnt;
            getans = 1;
        }
    }
    int took = (n-1)/3+1;
    if(n==1)    return 1;
    else{
        return take(n-took)+1;
    }
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    cout << take(n) << " " << ans;
    return 0;
}
