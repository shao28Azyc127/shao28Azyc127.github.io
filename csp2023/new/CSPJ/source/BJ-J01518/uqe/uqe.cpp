#include<bits/stdc++.h>
using namespace std;
void asqrt(int derta,int a,int p,int q){
    int i = 2;
    int sqrtderta = 1;
    while(i * i <= derta){
        if(derta % (i * i) == 0)sqrtderta *= i,derta /= i * i;
        i++;
    }
    int sqrtgcd = __gcd(sqrtderta,a);
    sqrtderta /= sqrtgcd;
    a /= sqrtgcd;
	if(q == a and derta == 1){
		int gcdpq = __gcd(p + sqrtderta,q);
		p = p + sqrtderta;
		p /= gcdpq;
		q /= gcdpq;
		if(q == 1) cout << p;
		else if(p == 0) cout << "";
		else cout << p + sqrtderta << "/" << q;
		return ;
	}
	else{
		if(p == 0) cout << "";
		else if(q == 1) cout << p;
		else cout << p << "/" << q;
	}
    if((sqrtderta != 1 or derta != 1 or a != 1) and p != 0)cout << "+";
    if(sqrtderta > 1){
        cout << sqrtderta << "*";
    }
    if(sqrtderta < 1){
		cout << -1 * sqrtderta << "*";
	}
    if(derta != 1 or a != 1){
		cout << "sqrt(" << derta << ")";
	}
    if(a != 1){
        cout << "/" << a;
    }
    cout << endl;
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin >> t >> m;
    while(t--){
		int a,b,c;
		cin >> a >> b >> c;
		int derta = b * b - 4 * a * c;
		if(derta < 0) cout << "NO" << endl;
		else if(derta == 0){
			int p = -b,q = 2 * a;
			int m = __gcd(p,q);
			p /= m;
			q /= m;
			if(q == 1) cout << p << endl;
			else if(p == 0) cout << 0 << endl;
			else cout << p << "/" << q << endl;
		}
		else{
			int p = -b,q = 2 * a;
			int m = __gcd(p,q);
			p /= m;
			q /= m;
			asqrt(derta,2 * a,p,q);
		}
    }
    return 0;
}
/*
-b + sqrt(derta)
----------------
      2a
*/
     
