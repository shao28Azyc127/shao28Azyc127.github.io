#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e4+10;
int a[10][10];
int b[11][11][11][11][11];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
		for(int j=1; j<=5; j++){
			scanf("%d",&a[i][j]);
		}
	}
	if(n==1){
		printf("81");
		return 0;
	}
		for(int j=0; j<=9; j++){
			if(a[1][1]==j) continue;
			b[j][j][a[1][3]][a[1][4]][a[1][5]]=1;
		}
		for(int j=0; j<=9; j++){
			if(a[1][2]==j) continue;
			b[a[1][1]][j][j][a[1][4]][a[1][5]]=1;
		}
		for(int j=0; j<=9; j++){
			if(a[1][3]==j) continue;
			b[a[1][1]][a[1][2]][j][j][a[1][5]]=1;
		}
		for(int j=0; j<=9; j++){
			if(a[1][4]==j) continue;
			b[a[1][1]][a[1][2]][a[1][3]][j][j]=1;
		}
		for(int j=0; j<=9; j++){
			if(a[1][1]==j) continue;
			b[j][a[1][2]][a[1][3]][a[1][4]][a[1][5]]=1;
		}
		for(int j=0; j<=9; j++){
			if(a[1][2]==j) continue;
			b[a[1][1]][j][a[1][3]][a[1][4]][a[1][5]]=1;
		}
		for(int j=0; j<=9; j++){
			if(a[1][3]==j) continue;
			b[a[1][1]][a[1][2]][j][a[1][4]][a[1][5]]=1;
		}
		for(int j=0; j<=9; j++){
			if(a[1][4]==j) continue;
			b[a[1][1]][a[1][2]][a[1][3]][j][a[1][5]]=1;
		}
		for(int j=0; j<=9; j++){
			if(a[1][5]==j) continue;
			b[a[1][1]][a[1][2]][a[1][3]][a[1][4]][j]=1;
		}
	for(int i=2; i<=n; i++){
		for(int j=0; j<=9; j++){
			for(int k=0; k<=9; k++){
				for(int l=0; l<=9; l++){
					for(int z=0; z<=9; z++){
						for(int h=0; h<=9; h++){
							if(b[j][k][l][z][h]) continue;
							if(a[i][1]==j&&a[i][2]==j&&a[i][3]==j&&a[i][4]==j&&a[i][5]!=j){
								cnt++;
							}
							if(a[i][1]==j&&a[i][2]==j&&a[i][3]==j&&a[i][4]!=j&&a[i][5]==j){
								cnt++;
							}
							if(a[i][1]==j&&a[i][2]==j&&a[i][3]!=j&&a[i][4]==j&&a[i][5]==j){
								cnt++;
							}
							if(a[i][1]==j&&a[i][2]!=j&&a[i][3]==j&&a[i][4]==j&&a[i][5]==j){
								cnt++;
							}
							if(a[i][1]!=j&&a[i][2]==j&&a[i][3]==j&&a[i][4]==j&&a[i][5]==j){
								cnt++;
							}
							if(a[i][1]==j&&a[i][2]==j&&a[i][3]==j&&a[i][4]!=j&&a[i][5]!=j){
								cnt++;
							}
							if(a[i][1]==j&&a[i][2]==j&&a[i][3]!=j&&a[i][4]!=j&&a[i][5]==j){
								cnt++;
							}
							if(a[i][1]==j&&a[i][2]!=j&&a[i][3]!=j&&a[i][4]==j&&a[i][5]!=j){
								cnt++;
							}
							if(a[i][1]!=j&&a[i][2]!=j&&a[i][3]==j&&a[i][4]==j&&a[i][5]!=j){
								cnt++;
							}
						}
					}
				}
			}
		}
	}
	printf("%d",cnt);
   return 0;
}
