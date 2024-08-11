#include <bits/stdc++.h>
using namespace std;

int n, c = 0, f = 0, d, k;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i += 3){
    	c = i;
    	f = 1;
    	k = 1;
    	while (c <= n){
    		if (c == n) d = f;
    		c += (c+1)/2;
    		f++; 
    		if (c <= n) k = max(k, f);
		}
	}
	cout << k << " " << d;
    return 0;
}
