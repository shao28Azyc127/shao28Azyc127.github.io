#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int n,a,b,c,m;
inline int jdg(int k){
	return k<0?-k:k;
}
inline int gcd(int a,int b,int c){
	int ans=1,mn=min(min(a,b),c);
	for(int i=2;i<=jdg(mn);i++){
		if(a%i==0 and b%i==0 and c%i==0)ans=i;
	}
	return ans;
}
inline bool chk(double num){
	int abac=num;
	return abac==num;
}
inline int pingfangyinz(int k){
	int ans=1;
	for(int i=1;i<=sqrt(k);i++){
		if(k%(i*i))ans=i;
	}
	return ans;
} 
inline void cal(int fst,int scd,int trd){
	int delta=scd*scd-4*fst*trd;
	#ifdef tst
	printf("\ndelta是%d（%d*%d-4*%d*%d=%d）,2倍2次项系数是%d\n",delta,scd,scd,fst,trd,delta,2*fst);
	#endif
	double p=sqrt(delta);
	if(delta<0){
		cout << "NO\n";
		return;
	}
	if(chk(p)){
		int p1=p;
		int g=gcd(p1-scd,2*fst,2*fst);
		if(p1==0)m++;
		else if((p1-scd)%(2*fst)==0)
			printf("%d",(p1-scd)/(2*fst));
		else 
			printf("%d/%d",(p1-scd)/g,(2*fst)/g);
	}
	else{
		int q1=-scd;
		int g=gcd(q1,2*fst,q1);
		if(q1%(2*fst)==0)printf("%d+",q1/(2*fst));
		else printf("%d/%d+",q1/g,(2*fst)/g);
		int yinz=pingfangyinz(delta);
		int as=gcd(yinz,2*fst,yinz);
		#ifdef tst
		printf("\n %d的最大平方因子%d与2*二次项系数的最大公因数是%d\n",delta,yinz,as);
		#endif
		if(yinz==1)printf("sqrt(%d)/%d",delta,2*fst);
		else if(yinz%(2*fst)==0)printf("%d*sqrt(%d)",yinz/(2*fst),delta/yinz);
		else printf("%d*sqrt(%d)/%d",yinz/as,delta/yinz,(2*fst)/as);
	}
	cout << "\n";
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a >> b >> c;
		cal(a,b,c);
	}
	return 0;
}