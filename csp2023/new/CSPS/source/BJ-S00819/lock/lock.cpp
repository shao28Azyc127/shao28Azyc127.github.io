#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][6];
int sum[100000];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<5;j++){
			cin>>a[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=4;j++){
			for(int k=0;k<=9;k++){
					int indd=(int)a[i][4]*pow(10,0)+a[i][3]*pow(10,1)+a[i][2]*pow(10,2)+a[i][1]*pow(10,3)+a[i][0]*pow(10,4)-a[i][j]*pow(10,4-j)+k*pow(10,4-j);
					//~ cout<<indd<<endl;
					sum[indd]++;
			}
		}
		for(int j=0;j<4;j++){
			for(int k=0;k<=9;k++){
					int indd=(int)a[i][4]*pow(10,0)+a[i][3]*pow(10,1)+a[i][2]*pow(10,2)+a[i][1]*pow(10,3)+a[i][0]*pow(10,4)-a[i][j]*pow(10,4-j)+((a[i][j]+k)%10)*pow(10,4-j)-a[i][j+1]*pow(10,3-j)+((a[i][j+1]+k)%10)*pow(10,3-j);
					//~ cout<<indd<<endl;
					sum[indd]++;
			}
		}
	}
	for(int i=0;i<100000;i++){
		if(sum[i]==n) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
