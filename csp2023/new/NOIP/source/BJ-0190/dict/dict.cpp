#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,d[3005][27],M1,M2;
string s;
bool cmp(int x,int y){//1->x<y
	int t=26;
	while(d[x][t]==d[y][t]&&t>=0){
		t--;
	}
	if(t==-1){
		return 0;
	}
	if(d[x][t]>d[y][t]){
		return 0;
	}
	return 1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			d[i][s[j]-'a']++;
		}
	}
	if(n==1){
		printf("1");
		return 0;
	}
	M1=1;
	M2=2;
	if(cmp(2,1)){
		swap(M1,M2);
	}
	for(int i=3;i<=n;i++){
		if(cmp(i,M1)){
			M2=M1;
			M1=i;
		}
		else if(cmp(i,M2)){
			M2=i;
		}
	}
	for(int i=1;i<=n;i++){
		int t1=26,t2=0;
		if(i!=M1){
			while(!d[M1][t1]){
				t1--;
			}
			while(!d[i][t2]){
				t2++;
			}	
			if(t1<=t2){
				printf("0");
			}
			else{
				printf("1");
			}
		}
		else{
			while(!d[M2][t1]){
				t1--;
			}
			while(!d[i][t2]){
				t2++;
			}	
			if(t1<=t2){
				printf("0");
			}
			else{
				printf("1");
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}