#include <bits/stdc++.h>
using namespace std;
int T,M,x,y,z;
int gcd(int a,int b){
	if(a==0){
		return b;
	}else if(b==0){
		return a;
	}
	if(a>b){
		return gcd(a%b,b);
	}else{
		return gcd(a,b%a);
	}
}
void uqe(int a,int b,int c){
	int delt=b*b-4*a*c,t;
	if(a<0){
		a=-a,b=-b,c=-c;
	}
	if(delt<0){
		cout << "NO";
		return;
	}else if(delt==0){
		a*=2,b=-b;
		t=gcd(abs(b),abs(a));
		a/=t,b/=t;
		if(b==0){
			cout << 0;
			return;
		}
		if(a==1){
			cout << b/a ;
		}else{
			cout << b << '/' << a;
		}
	}else{
		a*=2,b=-b;
		t=gcd(abs(b),abs(a));
		a/=t,b/=t;
		if(int((int)sqrt(delt))==sqrt(delt)){
			a*=t,b*=t;
			int k=sqrt(delt)+b;
			t=gcd(abs(a),abs(k));
			a/=t,k/=t;
			if(a==1||a==-1){
				cout << k/a;
			}else{
				cout << k << '/' << a ;
			}
		}else{
			if(b!=0){
				if(a==1||a==-1){
					cout << b/a;
				}else{
					if(b>0){
						cout << b << '/' << a; 
					}else{
						cout  << b << '/' << a;
					}
				}
			}
			a*=t;
			int j=2,ma=0;
			while(j*j<=delt){
				if(delt%(j*j)==0){
					ma=j;
				}
				j++;
			}
			if(b!=0){
				cout << '+';
			}
			if(ma==0){
				cout  << "sqrt(" << delt << ")/" << abs(a);
				return;
			}
			//cout << t << ' ' << ma << ' ' << a << endl;
			delt=delt/ma/ma;
			//cout << t << ' ' << ma << ' ' << a << endl;
			t=gcd(abs(a),ma);
			//cout << t << ' ' << ma << ' ' << a << endl;
			a/=t,ma/=t;
			//cout << t << ' ' << ma << ' ' << a << endl;
			a=abs(a);
			if(ma==1){
				if(a==1){
					cout  << "sqrt(" << delt << ")";
				}else{
					cout  << "sqrt(" << delt << ")/" << a;
				}
				return;
			}
			if(a==1){
				cout << ma << "*sqrt(" << delt << ')';
			}else{
				cout << ma << "*sqrt(" << delt << ")/" << a;
			}
		}
	}
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin >> T >> M;
	while(T--){
		cin >> x >> y >> z;
		uqe(x,y,z);
		cout << endl;
	}
	return 0;
}
