#include<bits/stdc++.h>//g++ t2.cpp -o t2 -O2 -std=c++14 -static
using namespace std;
struct operation{
	char op;
	int x;
	int y;
}q[200005];
int n,m;
int N(int k){
	if(k==3){
		return 3;
	}else{
		return (k==1?2:1);
	}
}
int type1[200005];
int type2[200005];
void run(){
	for(int i=1;i<=m;i++){
		if(q[i].op=='T'){
			type1[q[i].x]=1;
		}
		if(q[i].op=='F'){
			type1[q[i].x]=2;
		}
		if(q[i].op=='U'){
			type1[q[i].x]=3;
		}
		if(q[i].op=='+'){
			type1[q[i].x]=type1[q[i].y];
		}
		if(q[i].op=='-'){
			type1[q[i].x]=N(type1[q[i].y]);
		}
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int z=1;z<=t;z++){
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>q[i].op;
			if(q[i].op=='T'||q[i].op=='F'||q[i].op=='U'){
				cin>>q[i].x;
			}else{
				cin>>q[i].x>>q[i].y;
			}
		}
		for(int i=1;i<=n;i++){
			type1[i]=1;
		}
		if(n<5005){
			for(int i=1;i<=n+1;i++){
				for(int i=1;i<=n;i++){
					type2[i]=type1[i];
				}
				run();
			}
		}else{
			for(int i=1;i<=80;i++){
				for(int i=1;i<=n;i++){
					type2[i]=type1[i];
				}
				run();
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			//cout<<i<<' '<<type1[i]<<' '<<type2[i]<<endl;
			if(type1[i]!=type2[i]||type1[i]==3){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*
g++ t2.cpp -o t2

1 1
3 3
- 2 1
- 3 2
+ 1 3
*/