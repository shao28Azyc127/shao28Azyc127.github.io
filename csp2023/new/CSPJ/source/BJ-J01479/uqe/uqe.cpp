#include <bits/stdc++.h>
using namespace std;
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}
void out(int u,int d){
	int tmp=gcd(u,d);
	u/=tmp,d/=tmp;
	if(u<0&&d<0)u=-u,d=-d;
	if(d<0) u=-u,d=-d;
	if(d==1)cout << u ;
	else cout << u << "/" << d;
}
int cnt[2510];
vector<int> pe;
bool check(int a){
	int t=sqrt(a);
	fr(i,2,t){
		if(a%i==0)return 0;
	}
	return 1;
}
signed main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t,m;
	cin >> t >> m;
	fr(i,2,2500){
		if(check(i))pe.push_back(i);
	}
	while(t--){
		int a,b,c;
		cin >> a >>  b>> c;
		int d=(b*b)-(4*a*c);
		if(d<0)cout << "NO" << endl;
		else if(2*a<0){
			int t=sqrt(d);
			if(t*t==d){
				t=-t;
				out(t-b,2*a);
				cout << endl;
			}
			else{
				if(b!=0){
					out(-b,2*a);
					cout <<'+';
				}
				memset(cnt,0,sizeof cnt);
				int tmp=d;
				for(auto x:pe){
					while(tmp%x==0)tmp/=x,cnt[x]++;
				}
				int ans1=1,ansp=1;
				for(auto x:pe){
					if(cnt[x]){
						int tt=cnt[x]/2;
						fr(i,1,tt)ans1*=x;
						if(cnt[x]&1)ansp*=x;
					}
				}
				ans1=-ans1;
				
				int u=ans1,d=2*a;
				int ttmp=gcd(u,d);
				u/=ttmp,d/=ttmp;
				if(u==1&&d==1)
					cout << "sqrt(" << ansp << ")" << endl;
				else if(u==1)
					cout << "sqrt(" << ansp << ")/" << d << endl;
				else if(d==1)
					cout << u << "*sqrt(" << ansp << ")" << endl;
				else 
					cout << u << "*sqrt(" << ansp << ")/" << d << endl;
			}
		}
		else{
			int t=sqrt(d);
			if(t*t==d){
				out(t-b,2*a);
				cout << endl;
			}
			else{
				if(b!=0){
					out(-b,2*a);
					cout <<'+';
				}
				memset(cnt,0,sizeof cnt);
				int tmp=d;
				for(auto x:pe){
					while(tmp%x==0)tmp/=x,cnt[x]++;
				}
				int ans1=1,ansp=1;
				for(auto x:pe){
					if(cnt[x]){
						int tt=cnt[x]/2;
						fr(i,1,tt)ans1*=x;
						if(cnt[x]&1)ansp*=x;
					}
				}
				int u=ans1,d=2*a;
				int ttmp=gcd(u,d);
				u/=ttmp,d/=ttmp;
				if(u==1&&d==1)
					cout << "sqrt(" << ansp << ")" << endl;
				else if(u==1)
					cout << "sqrt(" << ansp << ")/" << d << endl;
				else if(d==1)
					cout << u << "*sqrt(" << ansp << ")" << endl;
				else 
					cout << u << "*sqrt(" << ansp << ")/" << d << endl;
			}
		}
	}
	return 0;
}
