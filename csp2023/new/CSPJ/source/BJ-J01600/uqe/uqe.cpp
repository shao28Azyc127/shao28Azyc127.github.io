#include <bits/stdc++.h>
using namespace std;
int T,M,cnt = 0;
int prime[2000005];
bool numlist[10000005];
void work (int n ){
	for (int i = 2; i <= n; i ++){
		if (numlist[i] == false){
			prime[++cnt] = i;
		}
		for (int j = 1; j <= cnt && i * prime[j] <= n; j ++){
			numlist [i * prime[j]] = true;
			if (i % prime[j] == 0 ) break;
		}
	}
}
void shuchu (int ta , int tb , int xa , int xb , int r){
	if (r == 0){
		if (ta == 0) return;
		if (tb == 1) cout << ta;
		else cout << ta << "/" << tb;
		cout << endl;
		return;
	}
	else if (r == 1){
		if (ta == 0 && xa == 0) return;
		// = ta/tb + xa/xb = ta xb + tb xa / tb xb
		int fz = ta * xb + tb * xa;
		int fm = tb * xb;
		int f = __gcd (fz , fm);
		fz /= f , fm /= f;
		if (fm < 0) fz *= -1 , fm *= -1;
		if (fm == 1) cout << fz << endl;
		else cout << fz << "/" << fm << endl;
		return;
	}
	else {
		if (tb == 1 && ta != 0) cout << ta << "+";
		else if (ta != 0) cout << ta << "/" << tb << "+";
		if (xa == 1 && xb == 1) cout << "sqrt(" << r << ")" << endl;
		else if (xb == 1) cout << xa << "*sqrt(" << r << ")" << endl;
		else if (xa == 1) cout << "sqrt(" << r << ")/" << xb << endl;
		else cout << xa << "*sqrt(" << r << ")/" << xb << endl;
		return;
	}
}
int main (){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin >> T >> M;
	work (10000000);
	while (T--){
		int a,b,c;
		cin >> a >> b >> c;
		if ( b * b - 4 * a * c < 0) {
			cout << "NO" << endl;
			continue;
		}
		int kta = -b;
		int ktb = 2*a;
		int m = __gcd (2*a , b);
		kta /= m , ktb /= m;
		if (ktb < 0){
			kta *= -1 , ktb *= -1;
		}
		//if (ktb == 1) cout << kta;
		//else cout << kta <<"/" << ktb;
		//cout << "+";
		int kua = b * b - 4 * a * c;
		int kub = 4 * a * a;
		int mu = __gcd ( kua , kub);
		int xa = 1 , xb = 1;
		kua /= mu; kub /= mu;
		for (int i = 1; prime[i] * prime[i] <= max (kua , kub); i ++){
			int x = prime[i] * prime[i];
			while (kua % x == 0) kua /= x , xa *= prime[i];
			while (kub % x == 0) kub /= x , xb *= prime[i];
		}
		
		kua *= kub; xb *= kub; kub = 1; 
		for (int i = 1; prime[i] * prime[i] <= kua; i ++){
			int x = prime[i] * prime[i];
			while (kua % x == 0) xa *= prime[i] , kua /= x;
		}
		int cash = __gcd (xa , xb);
		xa /= cash , xb /= cash;
		//if (xb != 1) cout << xa << "/" << xb;
		//else cout << xa;
		//cout << "*";
		//cout << "sqrt(" << kua << ")" << endl;
		//cout << kta << " " << ktb << " " << xa << " " << xb << " " << kua << " " << kub << endl;
		shuchu (kta , ktb , xa , xb , kua);
	}
}
