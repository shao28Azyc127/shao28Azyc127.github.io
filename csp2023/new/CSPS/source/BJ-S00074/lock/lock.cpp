#include<iostream>
using namespace std;
int n,a[10][10],b[100010],sum=0,x,y;
int poww(int i,int j){
	int num=1;
	for(int k=1;k<j;k++)
		num*=i;
	return num;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=5; j>=1; j--)
			cin >> a[i][j];
	if (n==1){
		cout << "81";
		return 0;
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=5; j++){
			x=0;
			for (int k=1; k<=5; k++)
				if (k!=j)
					x+=a[i][k]*poww(10,k);
			for (int k=0; k<=9; k++){
				int y=x+k*poww(10,j);
				b[y]++;
			}
		}
	}
	for (int i=1; i<=n; i++){
		for (int j=2; j<=5; j++){
			x=0;
			for (int k=1; k<=5; k++)
				if (k!=j && k!=j-1)
					x+=a[i][k]*poww(10,k);
			for (int k=0; k<=9; k++){
				int y=x+(k+a[i][j])%10*poww(10,j)+(k+a[i][j-1])%10*poww(10,j-1);
				b[y]++;
			}
		}
	}
	for (int i=100; i<=99999; i++)
		if (b[i]==n)
			sum++;
	cout << sum;
	return 0;
}