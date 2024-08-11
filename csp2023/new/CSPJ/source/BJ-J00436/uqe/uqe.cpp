#include<bits/stdc++.h>
using namespace std;
int T,M;
char minu;
double a,b,c,delta,pub,q1,q2;
int gcd(int a,int b){
	//a=abs(a); b=abs(b);
	if(abs(a)<abs(b)){int temp=a; a=b; b=temp;}
	if(b==0) return a;
	return abs(gcd(b,a%b));
}
int abs(int n){
	return n>=0?min(n,M):min(-n,M);
}
int sqr(int n){
	int i=2,sum=1;
	while(i*i<=n){
		if(n%(i*i)==0){
			sum*=i;
			n/=i*i;
		}
		else i++;
	}
	return sum;
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>T>>M;
	for(int i=0;i<T;i++){
		cin>>a>>b>>c;
		delta=b*b-4*a*c;
		if(delta<0) cout<<"NO\n";
		else{
			b=-b;
			a=a*2;
			delta=abs(delta);
			minu=((b+sqrt(delta))/a>(b-sqrt(delta))/a?'+':'-');
			
			pub=gcd(a,b);
			q2=a; a/=pub; b/=pub;
			
			q1=sqr(delta);
			delta/=q1*q1;
			pub=gcd(q1,q2);
			q1/=pub; q2/=pub;
			
			cout<<b;
			if(a!=1) printf("/%d",int(a));
			if(delta!=0&&delta!=1){
				cout<<minu;
				if(q1!=1) printf("%d*",int(q1));
				printf("sqrt(%d)",int(delta));
				if(q2!=1) printf("/%d",int(q2));
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
