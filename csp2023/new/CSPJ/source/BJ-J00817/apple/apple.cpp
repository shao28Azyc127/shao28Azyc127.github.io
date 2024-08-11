#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,ans1,ans2;
int main() {
	ios::sync_with_stdio(false);
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	int x;
	bool myfind=true;
	while(n) {
		ans1++;
		if(n%3) {
			if(myfind) {
				if(n%3==1) {
					ans2=ans1;
					myfind=false;
				}
			}
			x=floor(n/3.0)+1;
		}
		else {
			x=n/3;
		}
		n-=x;
	}
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}

/*
	long long maxnum;
	srand(time(NULL));
	cout<<rand()%maxnum;
*/
