#include <iostream>
#include <cstdio>
using namespace std;
char c[1005][1005],d[1005][1005];
int n,m,s=0,t=0;
bool check1(int x,int y){
	if(c[x][1]>=c[y][1]){
		return true;
	}
	return false;
}
bool check2(int x,int y){
	if(c[x][1]<c[y][1]){
		return false;
	}
	else if(c[x][1]==c[y][1]&&c[x][2]<c[y][2]){
		return false;
	}
	return true;
}
bool check3(int x,int y){
	if(c[x][2]<c[y][1]){
		return false;
	}
	else if(c[x][2]==c[y][1]&&c[x][1]<c[y][2]){
		return false;
	}
	return true;
}
bool check4(int x,int y){
	int g=1;
	for(int k=1;k<=m;k++){
		d[x][k]=c[x][k];
		d[y][k]=c[y][k];
	}
	for(int k=1;k<=m;k++){
		if(d[x][k]<d[y][k]){
			return false;
		}
		else if(d[x][k]==d[y][k]){
			continue;
		}
		else if(d[x][k]>d[y][k]){
			if(g==1){
				for(int l=m;l>k;l--){
					if(d[x][l]<d[y][k]){
						swap(d[x][l],d[x][k]);
						g=0;
					}
				}
				if(g==1){
					for(int l=m;l>k;l--){
					if(d[x][l]==d[y][k]){
						swap(d[x][l],d[x][k]);
						g=2;
					}
				}
					if(g==1){
						return true;
					}
				}
				else{
					return false;
				}
			}
			else{
				return true;
			}
		}
	}
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >>c[i][j];
		}
	}
	if(n==1&&m==1){
		cout<<1;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			s=0;
			for(int j=1;j<=n;j++){
				if(i!=j){
					if(check1(i,j)){
						s=1;
					}
				}
			}
			if(s==0){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			s=0;
			t=0;
			for(int j=1;j<=n;j++){
				if(i!=j){
					if(check2(i,j)){
						s=1;
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(i!=j){
					if(check3(i,j)){
						t=1;
					}
				}
			}
			if(s==1&&t==1){
				cout<<0;
			}
			else{
				cout<<1;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			s=0;
			for(int j=1;j<=n;j++){
				if(i!=j){
					if(check4(i,j)){
						s=1;
						//cout<<i<<" "<<j<<endl;
					}
				}
			}
			if(s==0){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
	}
	return 0;
	}
