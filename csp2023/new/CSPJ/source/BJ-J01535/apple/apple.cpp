#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,ans1 = 1,ans2,f = 0;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if(n % 3 == 1)ans2 = 1,f = 1;
    while(n > 1){
		ans1++;
		if(n % 3 == 2 || n % 3 == 1)n -= n / 3 + 1;
		else n -= n / 3;
        if(n % 3 == 1 && f == 0)ans2 = ans1,f = 1;
	}
	cout << ans1 << " " << ans2;
	return 0;
}
