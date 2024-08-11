#include<bits/stdc++.h>
using namespace std;
char s[3005],minx[3005][3005],maxx[3005],compx1[3005],compx2[3005];
int n,m,id;
bool cmp(char a,char b){
	return a<b;
}
bool comp(char a[],char b[]){
	for(int i=0;i<m;i++){
		if(a[i]<b[i])return 1;
		if(a[i]>b[i])return 0;
	}
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> s;
		sort(s,s+m,cmp);
		for(int j=0;j<m;j++)minx[i][j]=s[j];
		for(int j=m-1;j>=0;j--){
			maxx[m-1-j]=s[j];
		}
		if(i==1){
			for(int j=0;j<m;j++)compx1[j]=maxx[j];
			id=1;
		}else {
			if(comp(maxx,compx1)){
				for(int j=0;j<m;j++)compx2[j]=compx1[j];
				for(int j=0;j<m;j++)compx1[j]=maxx[j];
				id=i;
			}else if(i==2){
				for(int j=0;j<m;j++)compx2[j]=maxx[j];
			}else if(comp(maxx,compx2))for(int j=0;j<m;j++)compx2[j]=maxx[j];
		}
	}
	for(int i=1;i<=n;i++){
		if(id==i){
			if(comp(minx[i],compx2))cout << 1;
			else cout << 0;
		}else {
			if(comp(minx[i],compx1))cout << 1;
			else cout << 0;
		}
	}
	cout << endl;
	return 0;
}