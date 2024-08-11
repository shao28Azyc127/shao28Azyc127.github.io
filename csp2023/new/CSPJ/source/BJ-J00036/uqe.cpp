#include<bits/stdc++.h>
using namespace std;

int T,M,a,b,c,x;
//int gcd(int x,int y){
//	int d=abs(x),e=abs(y),k=1;
//	while(d%2==0&&e%2==0){
//		d/=2;
//		e/=2;
//		k*=2;
//	}
//	for(int i=3;i<=min(d,e);i+=2){
//		while(d%2==0&&e%2==0){
//			d/=i;
//			e/=i;
//			k*=i;
	//	}
	//}
	//return k;
//}
int cg(int d){
	int k=1,e=d;
	for(int i=2;i<=ceil(sqrt(e));i++){
		while(e%(i*i)==0){
			k*=i;
			e/=i*i;
		}
	}
	return k;	
} 
bool check(double d){
	if(ceil(d)-d==0){
		return 1;
	}
	return 0;
}

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	//cout << __gcd(-2,-4);
	//cout << __gcd(-1*5+5*5-4*1*4,2*1);
	//cout << cg(8);
	cin >> T >> M;
	while(T--){
		cin >> a >> b >> c;
		if(b*b-4*a*c<0){
			cout << "NO\n";
			continue;
		}
		if(check(sqrt(b*b-4*a*c))){
			x=__gcd(-1*b+b*b-4*a*c,2*a);
			if(-1*b+b*b-4*a*c==0){
				cout << 0 << endl;
				continue;
			}
			if(2*a/x==1){
				cout << (-1*b+sqrt(b*b-4*a*c))/x << endl;
				continue;
			}
			else{
				if(2*a/x>=0){
					cout << (-1*b+sqrt(b*b-4*a*c))/x << '/' << 2*a/x << endl;
				}else{
					cout << -1*(-1*b+sqrt(b*b-4*a*c))/x << '/' << -1*2*a/x << endl;
				}
			}
			continue;
		}
		else{
			if(b==0){
				int y=cg(b*b-4*a*c);
				x=__gcd(y,2*a);
				if(2*a/x==1){
					cout << y/x << "*sqrt(" << (b*b-4*a*c)/y/y << ")" << endl;
					continue;
				}
				else{
					if(2*a/x>=0){
						cout << y/x << "*sqrt(" << (b*b-4*a*c)/y/y << ')' <<'/' << 2*a/x << endl;
					}else{
						cout << -1*y/x << "*sqrt(" << (b*b-4*a*c)/y/y<< ')' << '/' << -1*2*a/x << endl;
					}
				}
				continue;
			}
			x=__gcd(-1*b,2*a);
			if(2*a/x==1){
				cout << (-1*b)/x << '+';
			}
			else{
				if(2*a/x>=0){
					cout << (-1*b)/x << '/' << 2*a/x<<'+';
				}else{
					cout << -1*(-1*b)/x << '/' << -1*2*a/x <<"+";
				}
			}
			int y=cg(b*b-4*a*c);
			x=__gcd(y,2*a);
			if(2*a/x==1){
				if(y/x==1)cout << "sqrt(" << (b*b-4*a*c)/y/y << ")" << endl;
				else cout << y/x << "*sqrt(" << (b*b-4*a*c)/y/y << ")" << endl;
				continue;
			}
			else{
				if(2*a/x>=0){
					if(y/x==1) cout << "sqrt(" << (b*b-4*a*c)/y/y << ")" <<'/' << 2*a/x << endl;
					else cout << y/x << "*sqrt(" << (b*b-4*a*c)/y/y << ')' <<'/' << 2*a/x << endl;
				}else{
					if(-1*y/x==1) cout << "sqrt(" << (b*b-4*a*c)/y/y << ")" <<'/' << -1*2*a/x << endl;
					else cout << -1*y/x << "*sqrt(" << (b*b-4*a*c)/y/y << ')' << '/' << -1*2*a/x << endl;
				}
			continue;
			}
		}
	}
	
	
	return 0;
}
