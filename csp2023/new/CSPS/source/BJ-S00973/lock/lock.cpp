#include <iostream>
using namespace std;
typedef long long ll;

int n,ans=0;
int a[10];
int possibleNumber[105];
bool possible[105];

ll power(ll x,ll p) {
	if(p==0) return 1;
	if(p==1) return x;
	ll t=power(x,p/2);
	if(p&1) return t*t*x;
	return t*t;
}
ll getDigit(ll n,int index) {
	for(int i=1;i<index;i++) {n/=10;}
	return n%10;
}
ll changeDigit(ll n,int index,int val) {
	ll pow=power(10,index-1);
	n-=(n/pow%10)*pow;
	n+=val*pow;
	return n;
}
bool check(ll a,ll b) {
	int dif=0;
	for(int i=1;i<=5;i++) {
		if(getDigit(a,i)!=getDigit(b,i)) {
			dif++;
		}
	}
	if(dif>=3) return 0;
	if(dif==1) return 1;
	for(int i=1;i<=4;i++) {
		if(getDigit(a,i)!=getDigit(b,i)) {
			if(getDigit(a,i-1)==getDigit(b,i-1)) {
				return (getDigit(a,i)-getDigit(b,i))==(getDigit(a,i-1)-getDigit(b,i-1));
			} else if(getDigit(a,i+1)==getDigit(b,i+1)) {
				return (getDigit(a,i)-getDigit(b,i))==(getDigit(a,i+1)-getDigit(b,i+1));
			} else return 0;
		}
	}
	return 0;
}
void input() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		int t;
		for(int j=1;j<=5;j++) {
			scanf("%d",&t);
			a[i]=(a[i]*10+t);
		}
	}
}
void generatePossibleNumber() {
	ll cop;
	for(int i=1;i<=5;i++) {
		for(int j=1;j<=9;j++) {
			cop=a[1];
			cop=changeDigit(cop,i,(getDigit(cop,i)+j)%10);
			possibleNumber[i*9+j-9]=cop;
			possible[1*9+j-9]=1;
			//printf("%d\n",possibleNumber[i*9+j-9]);
		}
	}
	for(int i=1;i<=4;i++) {
		for(int j=1;j<=9;j++) {
			cop=a[1];
			cop=changeDigit(cop,i,(getDigit(cop,i)+j)%10);
			cop=changeDigit(cop,i+1,(getDigit(cop,i+1)+j)%10);
			possibleNumber[i*9+j+36]=cop;
			possible[1*9+j+36]=1;
			//printf("%d\n",possibleNumber[i*9+j+36]);
		}
	}
}
void calc() {
	for(int i=1;i<=81;i++) {
		for(int j=2;j<=n;j++) {
			if(!check(possibleNumber[i],a[j])) {
				possible[i]=0;
				break;
			}
		}
	}
}
void print() {
	for(int i=1;i<=81;i++) {
		ans+=possible[i];
		//if(possible[i]) printf("%d\n",possibleNumber[i]);
	}
	printf("%d\n",ans);
}
int main() {
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	input();
	generatePossibleNumber();
	calc();
	if(n==1) {
		printf("81\n");
	} else print();

    return 0;
}
