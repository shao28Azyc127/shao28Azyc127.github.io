#include <bits/stdc++.h>
using namespace std;
int ans=1;
int n;
int day;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    int s = n;
    while(n!=0) {
        ans++;
        if(n>3) {
            n = n-n/3-1;
        }
        if(n<=3) {
            n--;
        }
        if(n==0)
            break;
    }
    if((s-1)%3==1) {
        day = ans;
    }
    if((s-1)%3==0) {
        day = 1;
    }
    if((s-1)%3==2) {
        day = ans-2;
    }
    cout << ans << " " << day;
    return 0;

}
