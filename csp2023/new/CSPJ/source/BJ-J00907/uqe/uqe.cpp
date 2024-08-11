#include <bits/stdc++.h>
using namespace std;

int a, b, c, t, m;

int get(int x){
	for (int i = sqrt(x); i >= 1; i--){
		if (x%(i*i) == 0) return i;
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin >> t >> m;
	while (t--){
	    cin >> a >> b >> c;
	    int delta = b*b-4*a*c;
	    if (delta < 0) cout << "NO\n";
	    else{
	    	double ans = (-b+sqrt(delta*1.0))/(2.0*a);
	    	if (ans-int(ans) == 0){
	    		cout << ans << "\n";
	    		continue;
			}
	    	int f = get(delta);
	    	if (delta*1.0-sqrt(delta*1.0) == 0){
	    		int x = -b+sqrt(delta);
	    		if (x != 0){
	    			if (x*2*a < 0) cout << "-";
		    		int g = __gcd(abs(x), abs(2*a));
		    		if (abs(x) == abs(2*a)) cout << x/(2*a) << "\n";
		    		else cout << abs(x/g) << "/" << abs(2*a/g) << "\n";
		    	}
		    	else cout << "0\n";
			}
			else{
				if (-b != 0){
					if (-b*2*a < 0) cout << "-";
					int g = __gcd(abs(-b), abs(2*a));
					if (abs(-b) != abs(2*a)){
						if (g != abs(2*a)) cout << abs(-b/g) << "/" << abs(2*a/g);
						else cout << abs(-b/g);
					}
					else cout << -b/(2*a);
					cout << "+";
				}
				int g = __gcd(f, abs(2*a));
				if (f != g){
					if (g != abs(2*a)) cout << f/g << "*sqrt(" << delta/(f*f) << ")/" << abs(2*a/g) << "\n";
					else cout << f/g << "*sqrt(" << delta/(f*f) << ")\n"; 	
				}
				else if (f == abs(2*a)) cout << "sqrt(" << delta/(f*f) << ")\n";
				else{
					if (2*a/g != 1) cout << "sqrt(" << delta/(f*f) << ")/" << abs(2*a/g) << "\n"; 
					else cout << "sqrt(" << delta/(f*f) << ")\n";
				}
			}
		}
	}
    return 0;
}
