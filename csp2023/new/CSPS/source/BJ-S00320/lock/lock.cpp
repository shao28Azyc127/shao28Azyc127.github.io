#include <bits/stdc++.h>
using namespace std;
int a[15][15],n,flag,sum,b[15];
bool check(int k){
	int mark=0,cnt=0,po1,po2,m1,m2;
	for(int i=1;i<=5;i++){
		if(a[k][i]==b[i])  cnt++;
		else{
			if(mark==0){
				mark=1;
				po1=i;
			}
			else{
				po2=i;
			}
		}
	}
	if(cnt==4)  return true;
	if(cnt!=3)  return false;
	if(po1-po2!=1&&po2-po1!=1)  return false;
	m1=b[po1]<a[k][po1]?a[k][po1]-b[po1]:10-b[po1]+a[k][po1];
	m2=b[po2]<a[k][po2]?a[k][po2]-b[po2]:10-b[po2]+a[k][po2];
	if(m1==m2)  return true;
	return false;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){
			for(int k=0;k<=9;k++){
				for(int l=0;l<=9;l++){
					for(int o=0;o<=9;o++){
						flag=0;
						b[1]=i,b[2]=j,b[3]=k,b[4]=l,b[5]=o;
						for(int t=1;t<=n;t++){
							if(check(t)==false){
								flag=1;
								break;
							}
						}
						if(flag==0){
							sum++;
						}
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
