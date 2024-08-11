#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<cstdio>
using namespace std;
int n;
int a[10][6];
int pd[100005];
int ww(int o,int oo,int ooo,int oooo,int ooooo){
	return o*10000+oo*1000+ooo*100+oooo*10+ooooo;
}
int te(int y){
	return y%10;
}
int main(){
freopen("lock.in","r",stdin);
freopen("lock.out","w",stdout);
cin>>n;
for(int i = 0;i<n;i++){
	cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
	for(int j = 0;j<=9;j++){
		if(j!=a[i][0]){
			pd[ww(j,a[i][1],a[i][2],a[i][3],a[i][4])]++;
		}
		if(j!=a[i][1]){
			pd[ww(a[i][0],j,a[i][2],a[i][3],a[i][4])]++;
		}
		if(j!=a[i][2]){
			pd[ww(a[i][0],a[i][1],j,a[i][3],a[i][4])]++;
		}
		if(j!=a[i][3]){
			pd[ww(a[i][0],a[i][1],a[i][2],j,a[i][4])]++;
		}
		if(j!=a[i][4]){
			pd[ww(a[i][0],a[i][1],a[i][2],a[i][3],j)]++;
		}
	}
	for(int j = 1;j<=9;j++){
		pd[ww(te(a[i][0]+j),te(a[i][1]+j),te(a[i][2]),te(a[i][3]),te(a[i][4]))]++;
		pd[ww(te(a[i][0]),te(a[i][1]+j),te(a[i][2]+j),te(a[i][3]),te(a[i][4]))]++;
		pd[ww(te(a[i][0]),te(a[i][1]),te(a[i][2]+j),te(a[i][3]+j),te(a[i][4]))]++;
		pd[ww(te(a[i][0]),te(a[i][1]),te(a[i][2]),te(a[i][3]+j),te(a[i][4]+j))]++;
	}
}
int cnt=0;
for(int i = 0;i<100000;i++){
	if(pd[i]==n){
		cnt++;
	}
}
cout<<cnt;
return 0;
}


