#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define int long long
const int N=1e3+10;
int t,m,a,b,c,box[N];
void ipt1(){
	scanf("%lld%lld",&t,&m);
}
void ipt2(){
	scanf("%lld%lld%lld",&a,&b,&c);
}
int gcd(int a,int b){
	if(a==0) return b;
	return gcd(b%a,a);
}
struct res{
	int xq,xp;
};
int qp(int x,int y){
	int ret=1,now=a;
	while(y){
		if(y&1) ret*=now;
		now*=now;
		y>>=1;
	}
	return ret;
}
int broken1(int x){
	//cout<<x<<'\n';
	x=abs(x);
	memset(box,0,sizeof(box));
	int len=x;
	for(int i=2;i<=len;i++){
		if(x==1) break;
		if(x==0) break;
		while(x%i==0&&x>1){
			//cout<<i<<endl;
			x/=i;
			box[i]++;
		}
	}
	int ret=1;
	//for(int i=1;i<=len;i++)
	//	if(box[i])
	//		printf("%lld^%lld+",i,box[i]);
	for(int i=1;i<=len;i++)
		if(box[i]>0){
			//cout<<i<<endl;
			//cout<<(pow(i,(box[i]%2?((box[i]-1)/2):(box[i]/2))))<<endl;
			//cout<<i<<"^"<<(box[i]%2?((box[i]-1)/2):(box[i]/2))<<endl;
			int tmp44=(box[i]%2?((box[i]-1)/2):(box[i]/2));
			//cout<<ret*(int)(qp(i,tmp44));
			ret=ret*(qp(i,(box[i]%2?((box[i]-1)/2):(box[i]/2))));
		}
	//cout<<"fc"<<endl;
	printf("\n");
	return ret;
}
void writeres(int q,int p){
	int xx=abs(gcd(q,p));
	q/=xx,p/=xx;
	//printf("%lld,%lld:",q,p);
	if(p==1)
		printf("%lld",q);
	else
		printf("%lld/%lld",q,p);
}
void solve(){
	int ky=b*b-4*a*c;
	if(ky<0){
		printf("NO\n");
		return;
	}
	else{
		int tmp1=sqrt(double(ky*1.0));
		if(tmp1*tmp1==ky){
			int q=max(-b+tmp1,-b-tmp1),p=2*a;
			//printf("%lld/%lld\n",q,p);
			writeres(q,p);
			printf("\n");
		}
		else{
			double tmp2=sqrt(double(ky*1.0));
			res q1,q2;int r=b*b-4*a*c;
			q1.xq=-b,q1.xp=2*a;
			if(2*a>0) q2.xq=1,q2.xp=2*a;
			else q2.xq=-1,q2.xp=2*a;
			if(q1.xq!=0){
				writeres(q1.xq,q1.xp);
				printf("+");
			}
			if(q2.xq==q2.xp)
				printf("sqrt(%lld)\n",r);
			else if(q2.xq%q2.xp==0)
				printf("%lld*sqrt(%lld)\n",q2.xq/q2.xp,r);
			else if(q2.xq==1)
				printf("sqrt(%lld)/%lld\n",r,abs(q2.xp));
			else{
				int xx=gcd(q2.xp,q2.xq);
				q2.xp/=xx,q2.xq/=xx;
				printf("%lld*sqrt(%lld)/%lld\n",q2.xq,r,q2.xp);
			}
		}
	}
}
signed main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	ipt1();
	//cout<<broken1(432*4)<<' '<<broken1(108)<<endl;
	while(t--){
		//int a,b;
		//cin>>a>>b;
		//cout<<gcd(a,b)<<endl;
		ipt2();
		solve();
	}
	return 0;
}