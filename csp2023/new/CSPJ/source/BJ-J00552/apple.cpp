#include <iostream>
#include <cstdio>
using namespace std;
int n,cnt=0,ans=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    while(n){
        cnt++;
        if((n-1)%3==0 && ans==0){
            ans=cnt;
        }
        n-=(n-1)/3+1;
    }
    cout << cnt << " " << ans;
    return 0;
}
