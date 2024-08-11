#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,cnt=0,s=0;
    cin >> n;
    if(n % 3 == 1) s = 1;
    while(n > 3){
        if((n % 3 == 1) && (s == 0)){
            s = cnt+1;
        }
        cnt++;
        n =n - ((n+2)/3);
    }
    cnt+=n;
    if(s==0) s = cnt;
    cout << cnt << " " << s;
    return 0;
}