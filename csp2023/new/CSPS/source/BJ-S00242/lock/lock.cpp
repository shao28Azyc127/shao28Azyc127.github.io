#include <iostream>
#include <cmath>
using namespace std;
int a[10][5],s,t;
bool b[100010];
int ne(int n){
	if(n>10) return (n-10)%10;
	else return n;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		for (int j=0;j<5;j++){
			cin>>a[i][j];
		}
	}
	
	for (int d=0;d<n;d++){
		t=a[d][0]*10000+a[d][1]*1000+a[d][2]*100+a[d][3]*10+a[d][4];
		/*
		for (int i=0;i<5;i++){
			for (int add=1;add<10;add++){
				if (b[t+(((int)pow(10,5-i-1))*(ne(a[d][i]+add)))]==0){
					s++;
					b[t+(((int)pow(10,5-i-1))*(ne(a[d][i]+add)))]=1;
					cout<<t+(((int)pow(10,5-i-1))*(ne(a[d][i]+add)))<<endl;
				}
			}
		}*/
		s+=45;
		for (int i=0;i<4;i++){
			
			for (int add=1;add<10;add++){
				if (b[t+(((int)pow(10,5-i-1))*(ne(a[d][i]+add)))+(((int)pow(10,5-i-2))*(ne(a[d][i+1]+add)))]==0){
					s++;
					b[t+(((int)pow(10,5-i-1))*(ne(a[d][i]+add)))+(((int)pow(10,5-i-2))*(ne(a[d][i+1]+add)))]=1;
					//cout<<t+(((int)pow(10,5-i-1))*((a[d][i]+add)))+(((int)pow(10,5-i-2))*ne((a[d][i+1]+add)))<<endl;
				}
			}
		}
	}
	cout<<s;
	return 0;
}
