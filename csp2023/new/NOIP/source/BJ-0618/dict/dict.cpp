#include<bits/stdc++.h>
using namespace std;
int n,m;
char w[4000][4000];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		printf("1");
		return 0;
	}
	for(int i = 1;i <= n;i++){
		cin>>w[i];
		char tmax=w[i][m-1],tmin=w[i][0];
		for(int j = 0;j < m;j++){
			if(tmax<w[i][j])tmax=w[i][j];
			else if(tmin>w[i][j])tmin=w[i][j];
		}
		w[i][0]=tmin;
		w[i][m-1]=tmax;
	}
	for(int i = 1;i <= n;i++){
		bool flag=1;
    	for(int j = 1;j <= n;j++){
			if(i==j)continue;
			if(w[i][0]>w[j][m-1]){
				flag=0;
				break;
			}else if(w[i][0]==w[j][m-1]&&w[j][0]!=w[j][m-1]){
				flag=0;
				break;
			}
    	}
    	printf("%d",flag);
	}
	return 0;
}