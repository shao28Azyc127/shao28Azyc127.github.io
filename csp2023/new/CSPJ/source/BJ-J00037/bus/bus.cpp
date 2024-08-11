#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int s[20005],e[20005],a[20005],n,m,k;
queue<int> x,lx;
void Move(int T){
	while(!x.empty()){
		if(x.front() == n && T%k == 0){
			cout << T;
			exit(0);
		}
		for(int i = 1;i <= m;i++){
			if(s[i] == x.front() && T >= a[i]){
				lx.push(e[i]);
			}
		}
		x.pop();
	}
	//cout << T << ":";
	while(!lx.empty()){
		x.push(lx.front());
		//cout << lx.front() << " ";
		lx.pop();
	}
	//cout << endl;
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int Maxtime = 0;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> s[i] >> e[i] >> a[i];
		Maxtime = max(Maxtime,a[i]);
	}	
	x.push(1);
	Move(k);
	for(int i = k+1;i <= Maxtime;i++){
		if(i%k == 0) x.push(1);
		Move(i);
	}
	int Nowtime = Maxtime+1;
	while(!x.empty()){
		Move(Nowtime);
		Nowtime++;
	}
	cout << -1;
}