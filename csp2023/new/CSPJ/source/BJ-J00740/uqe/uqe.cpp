#include<bits/stdc++.h>
using namespace std;
long long t,m,a,b,c;
int gcd(int x,int y){
	x = abs(x);
	y = abs(y);
	for(int i = min(x,y);i > 1;i --) if(x % i == 0 && y % i == 0) return i;
	return 1;
}
int kai(int x){
	bool flag = true;
	int cnt = 1;
	while(flag){
	flag = false;
		for(int i = 2;i < x;i ++){
			if(x % int(pow(i,2)) == 0){
				cnt *= i;
				x /= pow(i,2);
				flag = true;
			}
		}
	}
	return cnt;
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin >> t >> m;
	for(int i = 0;i < t;i ++){
		cin >> a >> b >> c;
		long long delta = pow(b,2) - 4 * a * c;
		if(delta < 0) cout << "NO";
		else if(delta == 0){
			if(0 - b == 2 * a) cout << 1;
			else printf("%lld/%lld",(0 - b) / gcd(2 * a,b),2 * a / gcd(2 * a,b));
		}else{
			if(pow(int(sqrt(delta)),2) == delta) cout << (int(sqrt(delta)) - b) / (2 * a);
			else{
				if(b != 0){
					if(0 - b == 2 * a) cout << 1;
					else{
						if(b > 0) printf("-%lld",b / gcd(2 * a,b));
						else printf("%lld",(0 - b) / gcd(2 * a,b));
						printf("/%lld",2 * a / gcd(2 * a,b));
					}
					cout << "+";
				}
				long long kai_delta = kai(delta);
				//cout << kai_delta;
				//cout << "start" << kai_delta << " " << 2 * a << " " << gcd(kai_delta,2 * a) << "end";
				if(gcd(kai_delta,2 * a) != 1){
					if(gcd(kai_delta,2 * a) == kai_delta){
						if(2 * a / kai_delta != 1) printf("sqrt(%lld)/%lld",delta / int(pow(kai_delta,2)),2 * a / kai_delta);
						else printf("sqrt(%lld)",delta / int(pow(kai_delta,2)));
					}else{
						if(2 * a / gcd(kai_delta,2 * a) != 1) printf("%lld*sqrt(%lld)/%lld",kai_delta / gcd(kai_delta,2 * a),delta / int(pow(kai_delta,2)),2 * a / gcd(kai_delta,2 * a));
						else printf("%lld*sqrt(%lld)",kai_delta / gcd(kai_delta,2 * a),delta / int(pow(kai_delta,2)));
					}
				}else{
					if(kai_delta == 1) printf("sqrt(%lld)/%lld",delta,2 * a);
					else printf("%lld*sqrt(%lld)/%lld",kai_delta,delta / int(pow(kai_delta,2)),2 * a);
				}
				//printf("sqrt(%lld)/%lld",delta / int(pow(kai_delta,2)),2 * a);
				//if(0 - b == 2 * a) printf("1+sqrt(%lld)/%lld",delta,2 * a);
				//else if(b == 0) printf("sqrt(%lld)/%lld",delta,2 * a);
				//else printf("%lld/%lld+sqrt(%lld)/%lld",0 - b,2 * a,delta,2 * a);
			}
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}