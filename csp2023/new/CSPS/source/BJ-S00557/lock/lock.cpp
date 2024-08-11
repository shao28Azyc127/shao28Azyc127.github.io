#include<bits/stdc++.h>
using namespace std;
int n, ans;
int loc[10][6];
int fz(int st, int add){
	return (st + add) % 10;
}
int ff(int st, int last){
	if(last>st){
		return last - st;
	}else{
		return 10 - st + last;
	}
}
bool judge(int nw, int nl){
	int cnt = 0, fu = 0, flag = 6;
	for(int i=5; i>=1; --i){	
		if(nw%10!=loc[nl][i]){
			++cnt;
			if(cnt==1){
				flag = i;
				fu = ff(nw%10, loc[nl][i]);
			}else if(cnt==2){
				if(flag!=i+1 || fz(nw%10, fu)!=loc[nl][i]) return 0;
			}else return 0;
		}
		nw /= 10;
	}
	if(cnt==0) return 0;
	return 1;
}
int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=5; ++j){
			scanf("%d", &loc[i][j]);
		}
	}
	bool kil = 0;
	for(int w=0; w<=99999; ++w){
		kil = 0;
		for(int i=1; i<=n; ++i){
			if(!judge(w, i)){
				kil = 1;
				break;
			}
		}
		if(!kil) ++ans;
	}
	cout<<ans;
	return 0;
}
