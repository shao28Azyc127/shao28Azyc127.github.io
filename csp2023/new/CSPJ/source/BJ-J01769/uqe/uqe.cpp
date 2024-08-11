#include <bits/stdc++.h>
using namespace std;
int t, m, a, b, c;

int check(int n){//sqrt(bas);
    int l = 1, r = m;
    while(l < r){
        int mid = l+r >> 1;
        if(mid*mid >= n) r= mid;
        else l = mid+1;
    }
    return r;
}

int main(){
    freopen("upe.in", "r", stdin);
    freopen("upe.out", "w", stdout);
    cin >> t >> m;
    while(t--){
        cin >> a >> b >> c;
        int bas = b*b-(4*a*c);
        if(bas < 0){
            cout << "No" << endl;
			continue;
        }

		// can it be a/b?
		int sqrt = check(bas);
		if(sqrt*sqrt == bas){
        	//cout << 1 << endl;
            double x = max(-1.0*b+sqrt/(2*a), -1.0*b-sqrt/(2*a));
		    double p = x, q = 1;
	      	while(int(p) != p){
		    	p *= 10;
			    q *= 10;
		    }// tong fen
	     	//cout << "p = " << p << " " << "q = " << q << endl;
	    	for(int i = min(p, q); i >= 2; i--){
	    		if(p == 1||q == 1) break;
			    while(int(p) % i == 0&&int(q) % i == 0){
				    p /= i;
				    q /= i;
			    }
	    	}//yuefen
		    //cout << "2p = " << p << " " << "q = " << q << endl;
	     	if(q == 1) cout << int(p);
	    	else cout << int(p) << "/" << int(q);
	    	continue;
		}
		int q1[3], q2;
		if(2*a > 0) {
			q1[1] = -b; q1[2] = 2*a;
			q2 = 2*a;
		}
		else{
			q1[1] = b; q1[2] = -2*a;
			q2 = -2*a;
		}
		if(q1[1] != 0){
			for(int i = q2; i >= 2; i--){
				if(int (q1[1])%i == 0&&int (q1[2])%i == 0){
					q1[1] /= i;
					q1[2] /= i;
				}
			}
			if(q1[1] !=  0) {
				cout << int(q1[1]/q1[2]) << "+";
			}
			else {
				cout << int (q1[1]/q1[2]) << "/" << int (q2) << "+";
			}
		}
		if(1/q2 == 1){
			cout << "sqrt(" << bas << ");";
		}
		else if(q2 == -1){
			cout << -1 <<"*"<<"sqrt(" << bas << ");";
		}
		else if(1 == (1/q2)){
			cout <<"sqrt(" << bas << ")/" << int (1/q2) << ";";
		}
    }
    return 0;
}
