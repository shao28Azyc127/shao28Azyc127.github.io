#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#define LL long long

using namespace std;

int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
};

struct fnum{
	int x,y;
	void yuefen(){
		if(y<0)x=-x,y=-y;
		int tmp=gcd(abs(x),abs(y));
		x/=tmp,y/=tmp;
	} 
	void print(){
		cout << x;
		if(y!=1)cout << "/" << y;
	}
	bool operator==(const int &tmp)const{
		return x/y==tmp;
	}
	bool iszheng(){
		return x%y==0;
	}
	fnum daoshu(){
		fnum re;
		re.x=y,re.y=x;
		return re;
	}
};
struct rnum{
	int x,y;
	rnum(){
		x=1,y=1;
	}
	void huajian(){
		if(y==0){
			x=0;
			return;
		}
		for(int i=floor(sqrt(y));i>=2;i--){
			while(y%(i*i)==0){
				y/=i*i;
				x*=i;
			}
		}
	}
	bool youli(){
		huajian();
		if(y==0||y==1)return true;
		return false;	
	}

};

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int T,M;
	cin >> T >> M;
	while(T--){
		int a,b,c;
		cin >> a >> b >> c;
		int d=b*b-4*a*c;
		if(d<0){
			printf("NO\n");
			continue;
		}
		rnum rd;
		rd.y=d;
		if(rd.youli()){
			fnum ans;
			if(a>0)ans.x=-b+rd.x*rd.y;
			else ans.x=-b-rd.x*rd.y;
			ans.y=2*a;
			ans.yuefen();
			ans.print();
		}
		else{
			fnum q1=(fnum){-b,2*a};
			fnum q2=(fnum){abs(rd.x),abs(2*a)};
			q1.yuefen(),q2.yuefen();
			if(q1.x!=0){
				q1.print();
				printf("+");
			}
			if(q2.x==q2.y){
				printf("sqrt(%d)",rd.y);
			}
			else if(q2.iszheng()){
				printf("%d*sqrt(%d)",q2.x/q2.y,rd.y);
			}
			else if(q2.daoshu().iszheng()){
				printf("sqrt(%d)/%d",rd.y,q2.y/q2.x);
			}
			else{
				printf("%d*sqrt(%d)/%d",q2.x,rd.y,q2.y);
			}
		}
		cout << endl;

	}
}