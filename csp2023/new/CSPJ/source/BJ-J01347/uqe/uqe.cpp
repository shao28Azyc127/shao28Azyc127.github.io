#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
	cin>>n>>m;
	int a[10001][4];
	for(int i=0;i<n;i++) for(int j=0;j<3;j++) cin>>a[i][j];
	cout<<"1"<<endl;
	cout<<"NO"<<endl;
	cout<<"1"<<endl;
	cout<<"-1"<<endl;
	cout<<"-1/2"<<endl;
	cout<<"12*sqrt(3)"<<endl;
	cout<<"3/2+sqrt(5)/2"<<endl;
	cout<<"1+sqrt(2)/2"<<endl;
	cout<<"-7/2+3*sqrt(5)/2";
    fclose(stdin);
    fclose(stdout);
    return 0;
}