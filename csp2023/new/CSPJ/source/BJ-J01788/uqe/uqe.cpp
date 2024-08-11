#include<bits/stdc++.h>
using namespace std;
int T,M,a,b,c;
int mod(int a,int b){
	return a-floor(a*1.0/b)*b;
}
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,mod(a,b));
}
void rati(int p,int q){
	int g=gcd(p,q);
	p/=g,q/=g;
	if(q==1) cout << p;
	else cout << p << '/' << q;
}
/*
-b/(2*a) + sqrt(d)/2*a
-2 12 270
2304
*/
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin >> T >> M;
	while(T--){
		cin >> a >> b >> c;
		int d=b*b-4*a*c;
		if(d<0) cout << "NO\n";
		else{
			int dq=sqrt(d);
			if(dq*dq<d){
				if(b!=0){
					rati(-b,2*a);
					cout << "+";
				}
				int p=0,q=2*a;
				for(int i=1;i*i<=d;i++){
					if(d%(i*i)==0){
						p=max(p,i);
					}
				}
				if(a<0) p*=-1;
				int r=d/p/p,g=gcd(p,q);
				p/=g,q/=g;
				if(p==1&&q==1) printf("sqrt(%d)\n",r);
				else if(p!=0&&q==1) printf("%d*sqrt(%d)\n",p,r);
				else if(p==1&&q!=0) printf("sqrt(%d)/%d\n",r,q);
				else printf("%d*sqrt(%d)/%d\n",p,r,q);
			}else{
				if(a<0) rati(-dq-b,2*a);
				else rati(dq-b,2*a);
				cout << endl;
			}
		}
	}
	return 0;
}
