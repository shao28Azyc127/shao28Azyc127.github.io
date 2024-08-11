#include<bits/stdc++.h>
using namespace std;
int a[10][5],b[10][5];
struct u{
	int o[11];
	bool flag=0;
}bi[100001];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			cin >> a[i][j];
		}
	}
	if(n==1){
		cout << 81;
		return 0;
	}
	int sum=0;
	for(int t=0;t<n;t++){
		for(int i=0;i<5;i++){
			for(int j=0;j<10;j++){
					for(int s=0;s<5;s++){
						if(s==i){
							bi[sum].o[s]=j;
							cout << bi[sum].o[s]<<endl;
						}else{
							bi[sum].o[s]=a[t][s];
						}
					}
				sum++;
			}
		}
	}
	int nm=sum;
	for(int i=0;i<sum;i++){
		bool flag=0;
		for(int j=0;j<5;j++){
			if(bi[i].o[j]){
				flag=1;
			}
		}
		if(flag==0){
			nm--;
		}
	}
	cout << nm;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
