#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin >> n;
    bool flag = true;
    int day = 0;
    int ans;
    while(n){
        day++;
        if(flag&&(n-1)%3==0){
            ans = day;
            flag = false;
        }
        n = n-1-(n-1)/3;
    }if(flag)ans = day;
    cout << day << " " << ans;
    return 0;
}