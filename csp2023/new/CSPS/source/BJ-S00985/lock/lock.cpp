#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=1;i<=n;i++)

int n, ans=1;
int a[10][8];
int b[8];

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
	cin>>n;
	rep(i,n) rep(j,5) cin>>a[i][j];
    if(n == 1){
		cout<< 81 <<endl;
		return 0;
	}
    rep(j,5){
		bool tmp[11] = {0,0,0,0,0,0,0,0,0,0,0};
		rep(i,n){
			if(!tmp[a[i][j]]) b[j]++;
			tmp[a[i][j]] = 1;
		}
	}
	int cnt = 0;
	int x;
	rep(i,5) if(b[i]>1){
		cnt++;
		if(x==0) x=i;
	}
	if(n == 2){
		if(cnt == 1){
			if(x==5) ans = 10;
			else ans = 12;
		}
		if(cnt == 2){
			if( ( (a[1][x+1]-a[1][x]) == (a[2][x+1]-a[2][x]) || (a[1][x+1]-a[1][x]) == (a[2][x+1]-a[2][x]+10) ) || (a[1][x+1]-a[1][x]+10) == (a[2][x+1]-a[2][x]))
				ans = 8;
			else ans = 2;
		}
	}
	if(n > 2){
		if(cnt > 2) ans = 1;
		if(cnt == 2) ans = 10 - n;
		if(cnt == 1) ans = 10 - n;
	}
	cout<< ans <<endl;
    return 0;
}
